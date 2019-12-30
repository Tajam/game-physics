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
    Audio::playMusic("main-bgm.ogg");
    setBackground("main-bg.jpg");
    LabelObject* label;
    // the "5" at the top
    for (int i = 0; i < 3; i++) {
      int alpha = 25 + i * 75;
      label = (new LabelObject(this))->makeDefault("10", 180, sf::Vector2f(642, 122), sf::Color(50, 50, 50, alpha));
      fiveLabels.push_back(label);
    }
    label = (new LabelObject(this))->makeDefault("10", 180, sf::Vector2f(638, 118), sf::Color(40, 255, 140, 255));
    fiveLabels.push_back(label);
    // title
    label = (new LabelObject(this))->makeDefault("Seconds Diver", 120, sf::Vector2f(638, 238), sf::Color(40, 140, 255, 255));
    label->makeShadow(4);
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
}