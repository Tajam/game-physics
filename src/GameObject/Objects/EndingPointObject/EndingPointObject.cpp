#include "EndingPointObject.h"

namespace tjm {
  EndingPointObject::EndingPointObject(GameRoom* room) :  GameObject(room) {
    this->room = room;
  }

  void EndingPointObject::onCollisionEnter(GameObject* other) {
    if (other->tagCheck("player")) {
      room->gameClear();
    }
  }

  b2BodyDef* EndingPointObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    return def;
  }

  b2FixtureDef* EndingPointObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8.f * SFMLToB2, 16.f * SFMLToB2);
    def->shape = box;
    def->isSensor = true;
    return def;
  }

  SpriteSheet* EndingPointObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(16, 32));
    loader.setStartPoint(sf::Vector2i(18, 18));
    SpriteSheet* sheet = new SpriteSheet(loader);
    return sheet;
  }
}