#include "CreditRoom.h"
#include "../../../Audio/Audio.h"
#include <fstream>
#include <cmath>

#define PI 3.14159265

namespace tjm {
  CreditRoom::CreditRoom(Game* game)
  : Room(game, sf::Vector2<int>(1280, 720)) {
    timing = 0;
    maxTiming = 500000;
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
  }

  void CreditRoom::open() {
    setBackground("main-bg.jpg");
    Audio::playMusic("main-bgm.ogg");
    std::ifstream file("../assets/data/credit");
    std::string line;
    int height = 192;
    while(std::getline(file, line)) {
      LabelObject* label = (new LabelObject(this))->makeDefault(line, 48, sf::Vector2f(639, height - 1), sf::Color(40, 140, 255));
      label->makeShadow(2);
      height += 48;
    }
    backLabel = (new LabelObject(this))->makeDefault("Back", 80, sf::Vector2f(642, 642), sf::Color(40, 180, 180));
    backLabel->makeShadow(4);
  }

  void CreditRoom::step(int64_t deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      if (!pressed) {
        getGame()->switchRoom(new StartRoom(getGame()));
        Audio::playSound("bubble.wav");
        pressed = true;
      }
    } else {
      pressed = false;
    }

    timing += deltaTime;
    if (timing >= maxTiming) {
      timing -= maxTiming;
    }
    float rate = (float)timing / maxTiming;
    float degree = 360.f * rate;
    float value = sin( degree * PI / 180);
    backLabel->setSize(90 + 20 * value);
    backLabel->setColor(sf::Color(180, 40.f + value * 100.f, 180.f + value * 40.f));
  }
}