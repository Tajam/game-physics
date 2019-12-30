#include "GameFailObject.h"
#include "../../../Audio/Audio.h"

#define PI 3.14159265

namespace tjm {
  GameFailObject::GameFailObject(GameRoom* room) : GameObject(room) {
    _haveSprite = false;
    _haveBody = false;
    maxEntryTiming = 1000000;
    entryTiming = 0;
    maxTiming = 500000;
    timing = 0;
    alpha = 0;
    selectedOption = 0;
    maxOption = 2;
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    
    this->room = room;
  }

  GameFailObject::~GameFailObject() {
    delete getSpriteSheet();
    setSpriteSheet(nullptr);
  }

  void GameFailObject::setup() {
    SpriteLoader loader("panel.png", sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(320, 320));
    SpriteSheet* sheet = new SpriteSheet(loader);
    setSpriteSheet(sheet);
    // message
    messageLabel = (new LabelObject(getRoom()))->makeDefault("Level Fail!", 65, sf::Vector2f(638, 268), sf::Color(255, 30, 110, 255));
    messageLabel->makeShadow(4);
    // options
    LabelObject* label;
    label = (new LabelObject(getRoom()))->makeDefault("Retry", 70, sf::Vector2f(638, 388), sf::Color(40, 180, 180));
    label->makeShadow(4);
    optionObjects.push_back(label);
    label = (new LabelObject(getRoom()))->makeDefault("Quit", 70, sf::Vector2f(638, 448), sf::Color(40, 180, 180));
    label->makeShadow(4);
    optionObjects.push_back(label);
  }

  void GameFailObject::update(int64_t deltaTime) {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      if (!pressed) {
        optionObjects[selectedOption]->setSize(70);
        optionObjects[selectedOption]->setColor(sf::Color(40, 180, 180));
        selectedOption--;
        if (selectedOption < 0) {
          selectedOption = maxOption - 1;
        }
        Audio::playSound("coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      if (!pressed) {
        optionObjects[selectedOption]->setSize(70);
        optionObjects[selectedOption]->setColor(sf::Color(40, 180, 180));
        selectedOption++;
        if (selectedOption >= maxOption) {
          selectedOption = 0;
        }
        Audio::playSound("coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      if (!pressed) {
        runOption(selectedOption);
        Audio::playSound("bubble.wav");
        pressed = true;
      }
    } else {
      pressed = false;
    }

    messageLabel->setColor(sf::Color(255, 30, 110, alpha));

    timing += deltaTime;
    if (timing >= maxTiming) {
      timing -= maxTiming;
    }
    float rate = (float)timing / maxTiming;
    float degree = 360.f * rate;
    float value = sin(degree * PI / 180);
    optionObjects[selectedOption]->setSize(70 + 10 * value);
    optionObjects[selectedOption]->setColor(sf::Color(180, 40.f + value * 100.f, 180.f + value * 40.f, alpha));
  }

  void GameFailObject::onDraw(Camera* camera, int64_t deltaTime) {
    int posX = camera->getPosition().x;
    int posY = camera->getPosition().y;

    if (entryTiming < maxEntryTiming) {
      entryTiming += deltaTime;
      if (entryTiming >= maxEntryTiming) {
        entryTiming = maxEntryTiming;
      }
      float rate = (float)entryTiming / maxEntryTiming;
      float degree = 90.f * rate;
      float value = sin(degree * PI / 180);
      alpha = 255.f * value;
    }

    sf::Sprite sprite = getSpriteSheet()->getSprite();
    sprite.setColor(sf::Color(255, 255, 255, alpha));
    sprite.setPosition(sf::Vector2f(posX + 640, posY + 360));
    camera->draw(sprite);

    messageLabel->setOrientation(sf::Vector2f(posX + 638, posY + 268));
    optionObjects[0]->setOrientation(sf::Vector2f(posX + 638, posY + 388));
    optionObjects[1]->setOrientation(sf::Vector2f(posX + 638, posY + 448));
  }

  void GameFailObject::runOption(int option) {
    switch(option) {
      case 0:
        room->jumpLevel(0);
      break;
      case 1:
        getRoom()->getGame()->switchRoom(new StartRoom(getRoom()->getGame()));
      break;
    }
  }
}