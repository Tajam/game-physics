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
    setBackground("../assets/textures/main-bg.jpg");
    Audio::playMusic("../assets/sounds/main-bgm.ogg");
    std::ifstream file("../assets/data/credit.5sd");
    std::string line;
    int height = 192;
    while(std::getline(file, line)) {
      makeLabel(line, 48, sf::Vector2f(641, height + 1), sf::Color(50, 50, 50));
      makeLabel(line, 48, sf::Vector2f(639, height - 1), sf::Color(75, 160, 205));
      height += 48;
    }
    backLabel = makeLabel("Back", 80, sf::Vector2f(638, 638), sf::Color(40, 180, 180));
    backShadow = makeLabel("Back", 80, sf::Vector2f(642, 642), sf::Color(50, 50, 50));
  }

  void CreditRoom::step(int64_t deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      if (!pressed) {
        getGame()->switchRoom(new StartRoom(getGame()));
        Audio::playSound("../assets/sounds/bubble.wav");
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
    backShadow->setSize(90 + 20 * value);
    backLabel->setColor(sf::Color(180, 40.f + value * 100.f, 180.f + value * 40.f));
  }

  LabelObject*  CreditRoom::makeLabel(std::string text, unsigned int size, sf::Vector2f position, sf::Color color) {
    LabelObject* label = new LabelObject(this);
    label->setFont("../assets/fonts/Jupiter.ttf");
    label->setText(text);
    label->setColor(color);
    label->setSize(size);
    label->setOrientation(0, position);
    Instantiate(label);
    return label;
  }
}