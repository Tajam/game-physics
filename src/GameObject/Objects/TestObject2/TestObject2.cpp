#include "TestObject2.h"

namespace tjm {
  TestObject2::TestObject2(Room* room) : GameObject(room) { }

  void TestObject2::setup() {
    setTag("coin");
  }

  void TestObject2::update(int64_t deltaTime) { }

  void TestObject2::destroy() { }

  b2BodyDef* TestObject2::defineBody() {
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->position = b2Vec2(1250.f, 1250.f);
    bodyDef->type = b2_kinematicBody;
    return bodyDef;
  }

  b2FixtureDef* TestObject2::defineFixture() {
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8, 8);
    b2FixtureDef* fixtureDef = new b2FixtureDef();
    fixtureDef->shape = box;
    return fixtureDef;
  }

  SpriteSheet* TestObject2::defineSprites() {
    SpriteLoader loader("../assets/textures/test2.png", sf::Vector2<int>(4, 1));
    loader.setGap(sf::Vector2<int>(1, 0));
    loader.setSize(sf::Vector2<int>(16, 16));
    loader.setStartPoint(sf::Vector2<int>(0, 0));
    SpriteSheet* spriteSheet = new SpriteSheet(loader);
    spriteSheet->setLoop(0, 3, 1);
    spriteSheet->setInterval(83333);
    spriteSheet->play();
    return spriteSheet;
  }
}