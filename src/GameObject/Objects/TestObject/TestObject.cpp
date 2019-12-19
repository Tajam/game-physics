#include "TestObject.h"
#include "../../../SFML/Window/Keyboard.hpp"
#include <iostream>

namespace tjm {
  TestObject::TestObject(Room* room) : GameObject(room) { 
    jumpSound = new Audio("../assets/sounds/test.wav");
    jumped = false;
  }

  TestObject::~TestObject() {
    delete jumpSound;
    jumpSound = NULL;
  }

  void TestObject::update() {
    // Levitate
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      getBody()->ApplyForceToCenter(b2Vec2(0, -5000.f), true);
      getSpriteSheet()->setFrame(0);
      if (!jumped) {
        jumpSound->getSound()->play();
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
}