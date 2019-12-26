#ifndef TESTOBJECT2_H
#define TESTOBJECT2_H

#include "../../GameObject.h"

namespace tjm {
  class TestObject2 : public GameObject {
     public:
      TestObject2(Room* room);
      void setup();
      void update(int64_t deltaTime);
      void destroy();
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
  };
}

#endif