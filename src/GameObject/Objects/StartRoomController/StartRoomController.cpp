/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "StartRoomController.h"
#include "../../../Audio/Audio.h"
#include <cmath>

#define PI 3.14159265

namespace tjm {
  StartRoomController::StartRoomController(Room* room) : GameObject(room) {
    _haveBody = false;
    _haveSprite = false;
    maxOption = 4;
    selectedOption = 0;
    timing = 0;
    maxTiming = 500000;
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    setTag("controller");
  }

  void StartRoomController::setup() {
    std::vector<std::string> items {
      "Start",
      "Select Level",
      "Credit",
      "Exit"
    };

    for (int i = 0; i < items.size(); i++) {
      LabelObject* label = (new LabelObject(getRoom()))->makeDefault(items[i], 80, sf::Vector2f(638, 368 + i * 60), sf::Color(40, 180, 180));
      label->makeShadow(4);
      optionObjects.push_back(label);
    }
  }

  void StartRoomController::update(int64_t deltaTime) {
    
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

  void StartRoomController::runOption(int option) {
    switch(option) {
      case 0:
        getRoom()->getGame()->switchRoom(new GameRoom(getRoom()->getGame(), 0));
      break;
      case 1:
        getRoom()->getGame()->switchRoom(new LevelRoom(getRoom()->getGame()));
      break;
      case 2:
        getRoom()->getGame()->switchRoom(new CreditRoom(getRoom()->getGame()));
      break;
      case 3:
        getRoom()->getGame()->stop();
      break;
    }
  }
}