#include "Room.h"
#include <iostream>

namespace tjm {

  Room::Room(b2World* world, sf::RenderWindow* window, sf::Vector2<int> roomSize) {
    this->world = world;
    Camera camera(window, roomSize);
    this->roomSize = roomSize;
    this->camera = new Camera(window, roomSize);
    this->isFollow = false;
  }

  Room::~Room() {
    delete camera;
    camera = NULL;
  }

  void Room::setFollow(unsigned long id) {
    followObject = id;
    isFollow = true;
  }

  void Room::cameraFollow() {
    if (!isFollow) return;
    if (objects.find(followObject) != objects.end()) {
      GameObject* obj = objects[followObject];
      b2Body* body = obj->getBody();
      sf::Sprite sprite = obj->getSpriteSheet()->getSprite();
      int posX = body->GetPosition().x + sprite.getTextureRect().width / 2;
      int posY = body->GetPosition().y + sprite.getTextureRect().height / 2;
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
    camera->draw(background);

    // Objects update loop
    for (auto& obj : objects) {
      GameObject* o = obj.second;
      o->update(deltaTime);
      o->draw(camera, deltaTime);
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
    SpriteLoader loader(fileName, sf::Vector2i(1, 0));
    background = loader.getSprite();
    background.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), roomSize));
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
    gameObject->setID(++objectCount);
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
