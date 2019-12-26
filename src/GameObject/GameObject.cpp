#include <iostream>
#include "GameObject.h"

namespace tjm {
  GameObject::GameObject(Room* room) {
    this->room = room;
    haveId = false;
    active = true;
    _haveBody = true;
    _haveSprite = true;
    tag = "";
  }

  GameObject::~GameObject() {
    delete spriteSheet;
    spriteSheet = NULL;
  }

  void GameObject::setSpriteSheet(SpriteSheet* spriteSheet) {
    this->spriteSheet = spriteSheet;
  }

  void GameObject::setBody(b2Body* body) {
    this->body = body;
  }

  void GameObject::setActive(bool active) {
    this->active = active;
  }

  void GameObject::setID(unsigned long id) {
    if (!haveId) {
      haveId = true;
      this->id = id;
    }
  }

  void GameObject::setTag(std::string tag) {
    this->tag = tag;
  }
  
  bool GameObject::isActive() { return active; }
  b2Body* GameObject::getBody() { return body; }
  SpriteSheet* GameObject::getSpriteSheet() { return spriteSheet; }
  unsigned long GameObject::getID() { return id; }
  bool GameObject::tagCheck(std::string tag) { return this->tag == tag; }
  bool GameObject::haveBody() { return _haveBody; }
  bool GameObject::haveSprite() { return _haveSprite; }

  void GameObject::setup() { }
  void GameObject::update(int64_t deltaTime) { }
  void GameObject::destroy() { }

  void GameObject::draw(Camera* camera, int64_t deltaTime) {
    if (_haveSprite) {
      b2Vec2 position = body->GetPosition();
      sf::Sprite sprite = spriteSheet->getSprite();
      sprite.setPosition(position.x, position.y);
      sprite.setRotation(body->GetAngle());
      camera->draw(sprite);
      spriteSheet->step(deltaTime);
    }
    onDraw(camera, deltaTime);
  }

  void GameObject::onDraw(Camera* camera, int64_t deltaTime) { }
  void GameObject::onCollisionEnter(GameObject* other) { }
  void GameObject::onCollisionExit(GameObject* other) { }

  b2BodyDef* GameObject::defineBody() {
    return new b2BodyDef();
  }

  b2FixtureDef* GameObject::defineFixture() {
    return new b2FixtureDef();
  }

  SpriteSheet* GameObject::defineSprites() {
    SpriteLoader loader;
    SpriteSheet* spriteSheet = new SpriteSheet(loader);
    return spriteSheet;
  }

  Room* GameObject::getRoom() {
    return room;
  }
}