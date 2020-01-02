/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "AirBubbleObject.h"

namespace tjm {
  AirBubbleObject::AirBubbleObject(GameRoom* room) : GameObject(room) {
    this->room = room;
  }

  b2BodyDef* AirBubbleObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    return def;
  }

  b2FixtureDef* AirBubbleObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(4.f * SFMLToB2, 4.f * SFMLToB2);
    def->shape = box;
    def->isSensor = true;
    return def;
  }

  SpriteSheet* AirBubbleObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setStartPoint(sf::Vector2i(35, 18));
    SpriteSheet* sheet = new SpriteSheet(loader);
    return sheet;
  }

  void AirBubbleObject::onCollisionEnter(GameObject* other) {
    if (other->tagCheck("player")) {
      room->resetGameTiming();
      getRoom()->Destroy(getID());
    }
  }

}