#include <iostream>
#include "GameObject.h"

namespace tjm {
  GameObject::GameObject(Room* room) {
    this->room = room;
    active = true;
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

  bool GameObject::isActive() {
    return active;
  }

  b2Body* GameObject::getBody() {
    return body;
  }

  SpriteSheet* GameObject::getSpriteSheet() {
    return spriteSheet;
  }

  void GameObject::setup() { 
    spriteSheet->setFrame(1);
  }

  void GameObject::update() { }

  b2BodyDef* GameObject::defineBody() {
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->position = b2Vec2(0.f, 0.f);
    bodyDef->type = b2_dynamicBody;
    return bodyDef;
  }

  b2FixtureDef* GameObject::defineFixture() {
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(18, 16);
    b2FixtureDef* fixtureDef = new b2FixtureDef();
    fixtureDef->shape = box;
    fixtureDef->density = 0.00347f;
    return fixtureDef;
  }

  SpriteSheet* GameObject::defineSprites() {
    SpriteLoader loader("../assets/textures/test.png", sf::Vector2<int>(2, 1));
    loader.setGap(sf::Vector2<int>(0, 0));
    loader.setSize(sf::Vector2<int>(18, 16));
    loader.setStartPoint(sf::Vector2<int>(0, 0));
    SpriteSheet* spriteSheet = new SpriteSheet(loader);
    return spriteSheet;
  }
}