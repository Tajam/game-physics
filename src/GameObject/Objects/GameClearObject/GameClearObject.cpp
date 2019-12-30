#include "GameClearObject.h"
#include "../../../Audio/Audio.h"

#define PI 3.14159265

namespace tjm {
  GameClearObject::GameClearObject(GameRoom* room, int score) : GameObject(room) {
    _haveSprite = false;
    _haveBody = false;
    maxEntryTiming = 1000000;
    entryTiming = 0;
    maxTiming = 500000;
    timing = 0;
    alpha = 0;
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    
    this->room = room;
    this->score = score;
  }

  GameClearObject::~GameClearObject() {
    delete getSpriteSheet();
    setSpriteSheet(nullptr);
  }

  void GameClearObject::setup() {
    SpriteLoader loader("panel.png", sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(320, 320));
    SpriteSheet* sheet = new SpriteSheet(loader);
    setSpriteSheet(sheet);
    // message
    messageLabel = (new LabelObject(getRoom()))->makeDefault("Level Clear!", 65, sf::Vector2f(638, 268), sf::Color(40, 140, 255, 255));
    messageLabel->makeShadow(4);
    // score
    scoreLabel = (new LabelObject(getRoom()))->makeDefault(std::to_string(score), 60, sf::Vector2f(638, 401), sf::Color(40, 140, 255, 255));
    scoreLabel->makeShadow(4);
    // continue
    continueLabel = (new LabelObject(getRoom()))->makeDefault("Continue", 70, sf::Vector2f(638, 428), sf::Color(40, 180, 180));
    continueLabel->makeShadow(4);
  }

  void GameClearObject::update(int64_t deltaTime) {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      if (!pressed) {
        room->jumpLevel(1);
        Audio::playSound("bubble.wav");
        pressed = true;
      }
    } else {
      pressed = false;
    }

    messageLabel->setColor(sf::Color(40, 140, 255, alpha));
    scoreLabel->setColor(sf::Color(40, 140, 255, alpha));

    timing += deltaTime;
    if (timing >= maxTiming) {
      timing -= maxTiming;
    }
    float rate = (float)timing / maxTiming;
    float degree = 360.f * rate;
    float value = sin(degree * PI / 180);
    continueLabel->setSize(70 + 10 * value);
    continueLabel->setColor(sf::Color(180, 40.f + value * 100.f, 180.f + value * 40.f, alpha));
  }

  void GameClearObject::onDraw(Camera* camera, int64_t deltaTime) {
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
    scoreLabel->setOrientation(sf::Vector2f(posX + 639, posY + 401));
    continueLabel->setOrientation(sf::Vector2f(posX + 638, posY + 448));
  }
}