#include "TestObject.h"
#include "../../../SFML/Window/Keyboard.hpp"
#include "../../../Audio/Audio.h"
#include <iostream>

namespace tjm {
  TestObject::TestObject(Room* room) : GameObject(room) {
    jumped = false;
  }

  void TestObject::setup() {
    getSpriteSheet()->setFrame(1);
    getRoom()->setFollow(getID());
  }

  void TestObject::update(int64_t deltaTime) {
    // Levitate
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      getBody()->ApplyForceToCenter(b2Vec2(0, -5000.f), true);
      getSpriteSheet()->setFrame(0);
      if (!jumped) {
        Audio::playSound("../assets/sounds/test.wav");
      }
      jumped = true;
    } else{
      getSpriteSheet()->setFrame(1);
      jumped = false;
    }

    // Move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      getSpriteSheet()->flipRight();
      getBody()->ApplyForceToCenter(b2Vec2(-1000.f, 0), true);
    }

    // Move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      getSpriteSheet()->flipLeft();
      getBody()->ApplyForceToCenter(b2Vec2(1000.f, 0), true);
    }
  }

  void TestObject::destroy() {
    std::cout << "Destroyed" << std::endl;
  }

  void TestObject::onCollisionEnter(GameObject* other) {
    if (other->tagCheck("coin")) {
      std::cout << "Get coin!" << std::endl;
      Audio::playSound("../assets/sounds/test.wav");
      getRoom()->Destroy(other->getID());
    }
  }

  b2BodyDef* TestObject::defineBody() {
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->position = b2Vec2(0.f, 0.f);
    bodyDef->type = b2_dynamicBody;
    return bodyDef;
  }

  b2FixtureDef* TestObject::defineFixture() {
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(9, 8);
    b2FixtureDef* fixtureDef = new b2FixtureDef();
    fixtureDef->shape = box;
    return fixtureDef;
  }

  SpriteSheet* TestObject::defineSprites() {
    SpriteLoader loader("../assets/textures/test.png", sf::Vector2<int>(2, 1));
    loader.setGap(sf::Vector2<int>(0, 0));
    loader.setSize(sf::Vector2<int>(18, 16));
    loader.setStartPoint(sf::Vector2<int>(0, 0));
    SpriteSheet* spriteSheet = new SpriteSheet(loader);
    return spriteSheet;
  }
}