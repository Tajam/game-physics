/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "SwitchObject.h"
#include "../../../Audio/Audio.h"

namespace tjm {
  SwitchObject::SwitchObject(GameRoom* room) : GameObject(room) {
    isRed = true;
    isEntered = false;
    this->room = room;
  }

  void SwitchObject::onCollisionEnter(GameObject* other) {
    if (other->tagCheck("player")) {
      if (!isEntered) {
        isEntered = true;
        room->toggleSwitch();
        Audio::playSound("toggle.wav");
      }
    }
  }

  void SwitchObject::onCollisionExit(GameObject* other) {
    if (other->tagCheck("player")) {
      isEntered = false;
    }
  }

  b2BodyDef* SwitchObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    def->allowSleep = true;
    return def;
  }

  b2FixtureDef* SwitchObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8.f * SFMLToB2, 8.f * SFMLToB2);
    def->shape = box;
    return def;
  }

  SpriteSheet* SwitchObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(2, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setGap(sf::Vector2i(1, 1));
    loader.setStartPoint(sf::Vector2i(52, 35));
    SpriteSheet* sheet = new SpriteSheet(loader);
    sheet->setFrame(isRed);
    return sheet;
  }

  void SwitchObject::toggle() {
    isRed = !isRed;
    getSpriteSheet()->setFrame(isRed);
  }
}