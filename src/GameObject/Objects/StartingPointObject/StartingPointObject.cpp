/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "StartingPointObject.h"

namespace tjm {
  StartingPointObject::StartingPointObject(Room* room) : GameObject(room) { }

  b2BodyDef* StartingPointObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    return def;
  }

  b2FixtureDef* StartingPointObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8.f * SFMLToB2, 16.f * SFMLToB2);
    def->shape = box;
    def->isSensor = true;
    return def;
  }

  SpriteSheet* StartingPointObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(16, 32));
    loader.setStartPoint(sf::Vector2i(1, 18));
    SpriteSheet* sheet = new SpriteSheet(loader);
    return sheet;
  }

}