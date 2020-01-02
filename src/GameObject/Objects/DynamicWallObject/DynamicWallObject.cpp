#include "DynamicWallObject.h"
#include "../../../Audio/Audio.h"

namespace tjm {
  DynamicWallObject::DynamicWallObject(Room* room) : GameObject(room) { }
      
  b2BodyDef* DynamicWallObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_dynamicBody;
    def->allowSleep = true;
    return def;
  }

  b2FixtureDef* DynamicWallObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(7.6f * SFMLToB2, 7.6f * SFMLToB2);
    def->shape = box;
    def->density = 25.f;
    def->friction = 0.1f;
    def->restitution = 0.f;
    return def;
  }

  SpriteSheet* DynamicWallObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setStartPoint(sf::Vector2i(119, 1));
    SpriteSheet* sheet = new SpriteSheet(loader);
    return sheet;
  }
}