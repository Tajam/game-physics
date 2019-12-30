#include "LevelSelectController.h"
#include "../../../Audio/Audio.h"
#include <cmath>

#define PI 3.14159265

namespace tjm {
  LevelSelectController::LevelSelectController(Room* room) : GameObject(room) {
    _haveBody = false;
    _haveSprite = false;
    maxOption = 2;
    selectedOption = 0;
    maxLevel = 4;
    selectedLevel = 0;
    timing = 0;
    maxTiming = 500000;
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    setTag("controller");
  }

  void LevelSelectController::setup() {
    // center text
    LabelObject* label;
    label = (new LabelObject(getRoom()))->makeDefault("Play level", 80, sf::Vector2f(638, 278), sf::Color(40, 180, 180));
    label->makeShadow(4);
    // left arrow
    label = (new LabelObject(getRoom()))->makeDefault("<", 120, sf::Vector2f(538, 358), sf::Color(40, 180, 180));
    label->makeShadow(4);
    // right arrow
    label = (new LabelObject(getRoom()))->makeDefault(">", 120, sf::Vector2f(738, 358), sf::Color(40, 180, 180));
    label->makeShadow(4);
    // center number
    label = (new LabelObject(getRoom()))->makeDefault(std::to_string(selectedLevel + 1), 120, sf::Vector2f(638, 358), sf::Color(40, 180, 180));
    label->makeShadow(4);
    optionObjects.push_back(label);
    // back
    label = (new LabelObject(getRoom()))->makeDefault("Back", 80, sf::Vector2f(638, 638), sf::Color(40, 180, 180));
    label->makeShadow(4);
    optionObjects.push_back(label);
  }

  void LevelSelectController::update(int64_t deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      if (!pressed) {
        optionObjects[selectedOption]->setSize(80);
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
        optionObjects[selectedOption]->setSize(80);
        optionObjects[selectedOption]->setColor(sf::Color(40, 180, 180));
        selectedOption++;
        if (selectedOption >= maxOption) {
          selectedOption = 0;
        }
        Audio::playSound("coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      if (!pressed && selectedOption == 0) {
        selectedLevel--;
        if (selectedLevel < 0) {
          selectedLevel = maxLevel - 1;
        }
        optionObjects[selectedOption]->setText(std::to_string(selectedLevel + 1));
        Audio::playSound("coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      if (!pressed && selectedOption == 0) {
        selectedLevel++;
        if (selectedLevel >= maxLevel) {
          selectedLevel = 0;
        }
        optionObjects[selectedOption]->setText(std::to_string(selectedLevel + 1));
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

    // effect
    timing += deltaTime;
    if (timing >= maxTiming) {
      timing -= maxTiming;
    }
    float rate = (float)timing / maxTiming;
    float degree = 360.f * rate;
    float value = sin( degree * PI / 180);
    optionObjects[selectedOption]->setSize(90 + 20 * value);
    optionObjects[selectedOption]->setColor(sf::Color(180, 40.f + value * 100.f, 180.f + value * 40.f));
  }

  void LevelSelectController::runOption(int option) {
    switch(option) {
      case 0:
        getRoom()->getGame()->switchRoom(new GameRoom(getRoom()->getGame(), selectedLevel));
      break;
      case 1:
        getRoom()->getGame()->switchRoom(new StartRoom(getRoom()->getGame()));
      break;
    }
  }

}