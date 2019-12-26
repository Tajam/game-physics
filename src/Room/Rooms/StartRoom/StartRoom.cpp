#include "StartRoom.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265

namespace tjm {
  StartRoom::StartRoom(b2World* world, sf::RenderWindow* window) 
  : Room(world, window, sf::Vector2<int>(1280, 720)) { 
    timing = 0;
    maxTiming = 2500000;
  }

  void StartRoom::open() {
    setBackground("../assets/textures/testbg.jpg");
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
      sf::Text* text = fiveLabels[i]->getText();
      text->setCharacterSize(180 + 80 * abs(value));
      sf::FloatRect textRect = text->getLocalBounds();
      text->setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
      text->setRotation(value * ( 5.f + i * 10.f ));
    }
  }

  LabelObject* StartRoom::makeLabel(std::string text, unsigned int size, sf::Vector2i position, sf::Color color) {
    LabelObject* titleLabel = new LabelObject(this, false);
    titleLabel->setFont("../assets/fonts/Jupiter.ttf");
    sf::Text* txt = titleLabel->getText();
    txt->setString(text);
    txt->setCharacterSize(size);
    txt->setStyle(sf::Text::Bold);
    txt->setFillColor(color);

    // set origin to center
    sf::FloatRect textRect = txt->getLocalBounds();
    txt->setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    txt->setPosition(position.x, position.y);

    Instantiate(titleLabel);
    return titleLabel;
  }
}