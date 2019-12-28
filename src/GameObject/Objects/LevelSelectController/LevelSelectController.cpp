#include "LevelSelectController.h"
#include "../../../Audio/Audio.h"
#include <cmath>
#include <iostream>

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
    makeLabel("Play level", 80, sf::Vector2f(638, 278), sf::Color(40, 180, 180));
    makeLabel("Play level", 80, sf::Vector2f(642, 282), sf::Color(50, 50, 50));
    // left arrow
    makeLabel("<", 120, sf::Vector2f(538, 358), sf::Color(40, 180, 180));
    makeLabel("<", 120, sf::Vector2f(542, 362), sf::Color(50, 50, 50));
    // right arrow
    makeLabel(">", 120, sf::Vector2f(738, 358), sf::Color(40, 180, 180));
    makeLabel(">", 120, sf::Vector2f(742, 362), sf::Color(50, 50, 50));
    // center number
    optionObjects.push_back(makeLabel(std::to_string(selectedLevel + 1), 120, sf::Vector2f(638, 358), sf::Color(40, 180, 180)));
    optionShadows.push_back(makeLabel(std::to_string(selectedLevel + 1), 120, sf::Vector2f(642, 362), sf::Color(50, 50, 50)));
    // back
    optionObjects.push_back(makeLabel("Back", 80, sf::Vector2f(638, 638), sf::Color(40, 180, 180)));
    optionShadows.push_back(makeLabel("Back", 80, sf::Vector2f(642, 642), sf::Color(50, 50, 50)));
  }

  void LevelSelectController::update(int64_t deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      if (!pressed) {
        optionObjects[selectedOption]->setSize(80);
        optionObjects[selectedOption]->setColor(sf::Color(40, 180, 180));
        optionShadows[selectedOption]->setSize(80);
        selectedOption--;
        if (selectedOption < 0) {
          selectedOption = maxOption - 1;
        }
        Audio::playSound("../assets/sounds/coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      if (!pressed) {
        optionObjects[selectedOption]->setSize(80);
        optionObjects[selectedOption]->setColor(sf::Color(40, 180, 180));
        optionShadows[selectedOption]->setSize(80);
        selectedOption++;
        if (selectedOption >= maxOption) {
          selectedOption = 0;
        }
        Audio::playSound("../assets/sounds/coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      if (!pressed && selectedOption == 0) {
        selectedLevel--;
        if (selectedLevel < 0) {
          selectedLevel = 0;
        }
        optionObjects[selectedOption]->setText(std::to_string(selectedLevel + 1));
        optionShadows[selectedOption]->setText(std::to_string(selectedLevel + 1));
        Audio::playSound("../assets/sounds/coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      if (!pressed && selectedOption == 0) {
        selectedLevel++;
        if (selectedLevel >= maxLevel) {
          selectedLevel = maxLevel - 1;
        }
        optionObjects[selectedOption]->setText(std::to_string(selectedLevel + 1));
        optionShadows[selectedOption]->setText(std::to_string(selectedLevel + 1));
        Audio::playSound("../assets/sounds/coin.wav");
        pressed = true;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      if (!pressed) {
        runOption(selectedOption);
        Audio::playSound("../assets/sounds/bubble.wav");
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
    optionShadows[selectedOption]->setSize(90 + 20 * value);
    optionObjects[selectedOption]->setSize(90 + 20 * value);
    optionObjects[selectedOption]->setColor(sf::Color(180, 40.f + value * 100.f, 180.f + value * 40.f));
  }

  LabelObject* LevelSelectController::makeLabel(std::string text, unsigned int size, sf::Vector2f position, sf::Color color) {
    LabelObject* label = new LabelObject(getRoom());
    label->setFont("../assets/fonts/Jupiter.ttf");
    label->setText(text);
    label->setColor(color);
    label->setSize(size);
    label->setOrientation(0, position);
    getRoom()->Instantiate(label);
    return label;
  }

  void LevelSelectController::runOption(int option) {
    switch(option) {
      case 0:
        std::cout << "Play level: " << selectedLevel + 1 << std::endl;
      break;
      case 1:
        getRoom()->getGame()->switchRoom(new StartRoom(getRoom()->getGame()));
      break;
    }
  }

}