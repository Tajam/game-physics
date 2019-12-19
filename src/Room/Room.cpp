#include "Room.h"
#include <iostream>

namespace tjm {

  Room::Room(b2World* world, sf::RenderWindow* window, sf::Vector2<int> roomSize) {
    this->world = world;
    Camera camera(window, roomSize);
    this->camera = new Camera(window, roomSize);
  }

  Room::~Room() {
    delete camera;
    camera = NULL;
  }

  void Room::setFollow(GameObject* gameObject) {
    followObject = gameObject;
  }

  void Room::setup() {
    open();
    objectCount = 0;
  }

  void Room::update(int64_t deltaTime) {
    step();
    for (GameObject* obj: addingObjects) {
      obj->setup();
      objects.insert(std::pair<unsigned long, GameObject*>(objectCount, obj));
      objectCount++;
    }
    addingObjects.clear();
    for (auto& obj : objects) {
      GameObject* o = obj.second;
      o->update();
      b2Body* body = o->getBody();
      float posX = body->GetPosition().x;
      float posY = body->GetPosition().y;
      float rot = body->GetAngle();
      SpriteSheet* sheet = o->getSpriteSheet();
      sf::Sprite s = sheet->getSprite();
      s.setPosition(posX, posY);
      s.setRotation(rot);
      camera->draw(s);
      sheet->step(deltaTime);
    }
    for (unsigned long l: removingObjects) {
      delete objects[l];
      objects.erase(l);
    }
    removingObjects.clear();
  }

  void Room::tearDown() {
    close();
    delete camera;
    camera = NULL;
  }

  template<class T>
  void Room::Instantiate(T* gameObject) {
    b2Body* body = world->CreateBody(gameObject->defineBody());
    body->CreateFixture(gameObject->defineFixture());
    gameObject->setBody(body);
    gameObject->setSpriteSheet(gameObject->defineSprites());
    addingObjects.push_back(gameObject);
  }

  void Room::open() {
    Instantiate<TestObject>(new TestObject(this));
  }

  void Room::step() { }

  void Room::close() { }

}
