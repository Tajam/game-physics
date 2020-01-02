#include "TimerDisplayObject.h"
#include <cmath>

namespace tjm {
  TimerDisplayObject::TimerDisplayObject(Room* room) : GameObject(room) {
    _haveBody = false;
    _haveSprite = false;
  }

  TimerDisplayObject::~TimerDisplayObject() {
    delete getSpriteSheet();
    setSpriteSheet(nullptr);
  }

  void TimerDisplayObject::setup() {
    SpriteLoader loader("objects.png", sf::Vector2i(3, 1));
    loader.setGap(sf::Vector2i(0, 0));
    loader.setSize(sf::Vector2i(2, 16));
    loader.setStartPoint(sf::Vector2i(1, 53));
    SpriteSheet* sheet = new SpriteSheet(loader);
    setSpriteSheet(sheet);

    upperLabel = new LabelObject(getRoom());
    upperLabel->makeDefault("10", 65, sf::Vector2f(640, 30), sf::Color(red, green, 65));
    upperLabel->makeShadow(4);
    getRoom()->Instantiate(upperLabel);
    lowerLabel = new LabelObject(getRoom());
    lowerLabel->makeDefault("10", 65, sf::Vector2f(640, 686), sf::Color(red, green, 65));
    lowerLabel->makeShadow(4);
    getRoom()->Instantiate(lowerLabel);
  }

  void TimerDisplayObject::update(float rate) {
    this->rate = rate;
    int number = ceil(10.f * rate);
    if (number > 0) {
      upperLabel->setText(std::to_string(number));
      lowerLabel->setText(std::to_string(number));
    } else {
      upperLabel->setText("Time Out!");
      lowerLabel->setText("Time Out!");
    }
  }

  void TimerDisplayObject::onDraw(Camera* camera, int64_t deltaTime) {
    SpriteSheet* sheet = getSpriteSheet();
    sf::Sprite sprite;
    float posX = camera->getPosition().x;
    float posY = camera->getPosition().y;
    // color
    if (rate >= 0.5f) {
      green = 255;
      red = 255.f * (float)(1.f - ((rate - 0.5f) / 0.5f));
    } else {
      green = 255.f * (float)(rate / 0.5f);
      red = 255;
    }
    upperLabel->setOrientation(sf::Vector2f(640 + posX, 30 + posY));
    lowerLabel->setOrientation(sf::Vector2f(640 + posX, 686 + posY));
    upperLabel->setColor(sf::Color(red, green, 65));
    lowerLabel->setColor(sf::Color(red, green, 65));
    if (rate <= 0) {
      return;
    }
    // left bound
    sheet->setFrame(0);
    sprite = sheet->getSprite();
    sprite.setColor(sf::Color(red, green, 65));
    sprite.setPosition(573 - 570.f * rate + posX, 10 + posY);
    camera->draw(sprite);
    sprite.setPosition(573 - 570.f * rate + posX, 710 + posY);
    camera->draw(sprite);
    sprite.setPosition(706 + posX, 10 + posY);
    camera->draw(sprite);
    sprite.setPosition(706 + posX, 710 + posY);
    camera->draw(sprite);
    // right bound
    sheet->setFrame(2);
    sprite = sheet->getSprite();
    sprite.setColor(sf::Color(red, green, 80));
    sprite.setPosition(707 + 570.f * rate + posX, 10 + posY);
    camera->draw(sprite);
    sprite.setPosition(707 + 570.f * rate + posX, 710 + posY);
    camera->draw(sprite);
    sprite.setPosition(574 + posX, 10 + posY);
    camera->draw(sprite);
    sprite.setPosition(574 + posX, 710 + posY);
    camera->draw(sprite);
    // center
    sheet->setFrame(1);
    sprite = sheet->getSprite();
    sprite.setColor(sf::Color(red, green, 80));
    sprite.scale(285.f * rate, 1);
    sprite.setPosition(288 + 285.f * (1.f - rate) + posX, 10 + posY);
    camera->draw(sprite);
    sprite.setPosition(288 + 285.f * (1.f - rate) + posX, 710 + posY);
    camera->draw(sprite);
    sprite.setPosition(992 - 285.f * (1.f - rate) + posX, 10 + posY);
    camera->draw(sprite);
    sprite.setPosition(992 - 285.f * (1.f - rate) + posX, 710 + posY);
    camera->draw(sprite);
  }
}