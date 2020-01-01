#include "DoorObject.h"

namespace tjm {
  DoorObject::DoorObject(Room* room, bool isRed) : GameObject(room) {
    this->isRed = isRed;
  }

  void DoorObject::setup() {
    if (isRed) {
      toggle();
    }
  }

  b2BodyDef* DoorObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    def->allowSleep = true;
    return def;
  }

  b2FixtureDef* DoorObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8.f * SFMLToB2, 8.f * SFMLToB2);
    def->shape = box;
    return def;
  }

  SpriteSheet* DoorObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(4, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setGap(sf::Vector2i(1, 1));
    loader.setStartPoint(sf::Vector2i(86, 53));
    SpriteSheet* sheet = new SpriteSheet(loader);
    sheet->setFrame(isRed);
    return sheet;
  }

  void DoorObject::toggle() {
    bool open = getBody()->GetFixtureList()[0].IsSensor();
    getSpriteSheet()->setFrame(isRed + 2 * !open);
    getBody()->GetFixtureList()[0].SetSensor(!open);
  }
}