#include "StartRoom.h"
#include "../../../Audio/Audio.h"
#include <cmath>

#define PI 3.14159265

namespace tjm {
  StartRoom::StartRoom(Game* game) 
  : Room(game, sf::Vector2<int>(1280, 720)) { 
    timing = 0;
    maxTiming = 2500000;
  }

  void StartRoom::open() {
    Audio::playMusic("../assets/sounds/main-bgm.ogg");
    setBackground("../assets/textures/main-bg.jpg");
    // the "5" at the top
    for (int i = 0; i < 3; i++) {
      fiveLabels.push_back(
        makeLabel("5", 180, sf::Vector2i(638, 118), sf::Color(50, 50, 50, 25 + i * 75))
      );
    }
    fiveLabels.push_back(
      makeLabel("5", 180, sf::Vector2i(642, 122), sf::Color(0, 255, 160, 255))
    );
    // title and its shadow
    makeLabel("Seconds Diver", 120, sf::Vector2i(638, 238), sf::Color(50, 50, 50, 255));
    makeLabel("Seconds Diver", 120, sf::Vector2i(642, 242), sf::Color(0, 140, 255, 255));

    Instantiate(new StartRoomController(this));
  }

  void StartRoom::step(int64_t deltaTime) {
    timing += deltaTime;
    if (timing >= maxTiming) {
      timing -= maxTiming;
    }
    float rate = (float)timing / maxTiming;
    float degree = 360.f * rate;
    float value = sin( degree * PI / 180);
    for (int i = 0; i < fiveLabels.size(); i++) {
      fiveLabels[i]->setSize(180 + 80 * abs(value));
      fiveLabels[i]->setOrientation((5.f + i * 10.f) * value);
    }
  }

  LabelObject* StartRoom::makeLabel(std::string text, unsigned int size, sf::Vector2i position, sf::Color color) {
    LabelObject* label = new LabelObject(this);
    label->setFont("../assets/fonts/Jupiter.ttf");
    label->setText(text);
    label->setColor(color);
    label->setSize(size);
    label->setOrientation(0, sf::Vector2f(position.x, position.y));
    label->setStyle(sf::Text::Bold);
    Instantiate(label);
    return label;
  }
}