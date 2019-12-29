#include "WallMasterObject.h"

namespace tjm {

  WallMasterObject::WallMasterObject(Room* room) : GameObject(room) {
    _haveSprite = false;
  }

  b2BodyDef* WallMasterObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->position = b2Vec2(0, 0);
    def->type = b2BodyType::b2_staticBody;
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

  void WallMasterObject::buildWall(std::vector<b2Vec2> points) {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* shape = new b2PolygonShape();
    b2Vec2* vertices = points.data();
    shape->Set(vertices, points.size());
    def->shape = shape;
    getBody()->CreateFixture(def);
  }
}