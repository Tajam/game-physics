#include "Room.h"

namespace tjm {

  const float Room::B2ToSFML = 64.f;
  const float Room::SFMLToB2 = 1.f / 64.f;

  Room::Room(Game* game, sf::Vector2i roomSize) {
    this->game = game;
    this->world = game->getWorld();
    this->camera = new Camera(game->getWindow(), roomSize);
    this->isFollow = false;
    this->haveBackground = false;
  }

  Room::~Room() {
    delete camera;
    camera = nullptr;
  }

  void Room::setFollow(unsigned long id) {
    followObject = id;
    isFollow = true;
  }

  void Room::resetFollow() {
    camera->setPosition(sf::Vector2i(0, 0));
    isFollow = false;
  }

  sf::Vector2i Room::getFollow() {
    GameObject* obj = objects[followObject];
    return sf::Vector2i();
  }

  Game* Room::getGame() {
    return game;
  }

  void Room::cameraFollow() {
    if (!isFollow) return;
    if (objects.find(followObject) != objects.end()) {
      GameObject* obj = objects[followObject];
      b2Body* body = obj->getBody();
      // sf::Sprite sprite = obj->getSpriteSheet()->getSprite();
      int posX = body->GetPosition().x * B2ToSFML; // + sprite.getTextureRect().width / 2;
      int posY = body->GetPosition().y * B2ToSFML; // + sprite.getTextureRect().height / 2;
      camera->setPosition(sf::Vector2i(posX, posY));
    } else {
      isFollow = false;
    }
  }

  void Room::setup() {
    objectCount = 0;
    open();
  }

  void Room::update(int64_t deltaTime) {
    step(deltaTime);
    world->Step(1.f / 60.f, 2.f, 6.f);

    // Adding new objects
    for (GameObject* obj: addingObjects) {
      objects.insert(std::pair<unsigned long, GameObject*>(obj->getID(), obj));
    }
    addingObjects.clear();

    // Draw background
    if (haveBackground) {
      int posX = camera->getPosition().x;
      int posY = camera->getPosition().y;
      background.setPosition(posX, posY);
      camera->draw(background);
    }

    // Objects update loop
    for (auto& obj : objects) {
      GameObject* o = obj.second;
      if (o->isActive()) {
        o->update(deltaTime);
        o->draw(camera, deltaTime);
      }
    }

    // Move camera
    cameraFollow();

    // Removing objects
    for (unsigned long l: removingObjects) {
      if (objects[l]->haveBody())
        world->DestroyBody(objects[l]->getBody());
      delete objects[l];
      objects.erase(l);
    }
    removingObjects.clear();
  }

  void Room::tearDown() {
    close();
    addingObjects.clear();
    removingObjects.clear();
    for (auto& obj : objects) {
      if (obj.second->haveBody())
        world->DestroyBody(obj.second->getBody());
      delete obj.second;
    }
    objects.clear();
  }

  void Room::setBackground(std::string fileName) {
    haveBackground = true;
    SpriteLoader loader(fileName, sf::Vector2i(1, 0));
    background = loader.getSprite();
    int sizeX = camera->getSize().x;
    int sizeY = camera->getSize().y;
    background.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(sizeX, sizeY)));
  }

  void Room::Instantiate(GameObject* gameObject) {
    if (gameObject->haveBody()) {
      b2Body* body = world->CreateBody(gameObject->defineBody());
      body->SetUserData(gameObject);
      body->CreateFixture(gameObject->defineFixture());
      gameObject->setBody(body);
    }
    if (gameObject->haveSprite())
      gameObject->setSpriteSheet(gameObject->defineSprites());
    gameObject->setID(objectCount++);
    gameObject->setup();
    addingObjects.push_back(gameObject);
  }

  void Room::Destroy(unsigned long id) {
    objects[id]->destroy();
    removingObjects.push_back(id);
  }

  void Room::open() { }

  void Room::step(int64_t deltaTime) { }

  void Room::close() { }

}
