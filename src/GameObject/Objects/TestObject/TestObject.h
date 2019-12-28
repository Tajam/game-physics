#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class TestObject: public GameObject {
    public:
      TestObject(Room* room);
      void setup();
      void update(int64_t deltaTime);
      void destroy();
      void onCollisionEnter(GameObject* other);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
    private:
      bool jumped;
  };
}

#endif