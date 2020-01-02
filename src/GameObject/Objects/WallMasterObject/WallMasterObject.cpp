/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "WallMasterObject.h"

namespace tjm {

  WallMasterObject::WallMasterObject(Room* room) : GameObject(room) {
    _haveSprite = false;
  }

  b2BodyDef* WallMasterObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->position = b2Vec2(0, 0);
    def->type = b2BodyType::b2_staticBody;
    def->allowSleep = true;
    return def;
  }

  b2FixtureDef* WallMasterObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* shape = new b2PolygonShape();
    shape->SetAsBox(0, 0);
    def->shape = shape;
    def->isSensor = true;
    return def;
  }

  void WallMasterObject::buildWall(b2Vec2 position, b2Vec2 size) {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* shape = new b2PolygonShape();
    b2Vec2 _size(size.x / 2, size.y / 2);
    b2Vec2 _position(position.x + _size.x, position.y + _size.y);
    shape->SetAsBox(_size.x, _size.y, _position, 0);
    def->shape = shape;
    getBody()->CreateFixture(def);
  }
}