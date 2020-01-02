/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "PlayerObject.h"
#include "../../../Audio/Audio.h"

namespace tjm {
  PlayerObject::PlayerObject(Room* room) : GameObject(room) {
    setTag("player");
  }

  void PlayerObject::setup() {
    this->jumped = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
  }

  void PlayerObject::update(int64_t deltaTime) {
    // swim
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      if (!jumped) {
        getBody()->ApplyForceToCenter(b2Vec2(0, -80.f), true);
        getSpriteSheet()->stop();
        getSpriteSheet()->play();
        Audio::playSound("swim.wav");
        jumped = true;
      }
    } else {
      jumped = false;
    }

    // sink faster
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      getBody()->ApplyForceToCenter(b2Vec2(0, 2.5f), true);
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
      // move left
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        getBody()->ApplyForceToCenter(b2Vec2(-2.f, 0), true);
        getSpriteSheet()->flipLeft();
      }
      // move right
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        getBody()->ApplyForceToCenter(b2Vec2(2.f, 0), true);
        getSpriteSheet()->flipRight();
      }
    }

    // drag
    b2Vec2 velocity = getBody()->GetLinearVelocity();
    getBody()->ApplyForceToCenter(0.25f * -velocity, true);
  }

  b2BodyDef* PlayerObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_dynamicBody;
    return def;
  }

  b2FixtureDef* PlayerObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(7.6f * SFMLToB2, 7.6f * SFMLToB2);
    def->shape = box;
    return def;
  }

  SpriteSheet* PlayerObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(6, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setStartPoint(sf::Vector2i(1, 1));
    loader.setGap(sf::Vector2i(1, 1));
    SpriteSheet* sheet = new SpriteSheet(loader);
    sheet->setFrame(0);
    sheet->setInterval(83333);
    sheet->setTimeline(0, 4, 1);
    sheet->setLoop(false);
    return sheet;
  }
}