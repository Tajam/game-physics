#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include "../../GameObject.h"
#include "../../../Audio/Audio.h"

namespace tjm {
  class TestObject: public GameObject {
    public:
      TestObject(Room* room);
      ~TestObject();
      void setup();
      void update(int64_t deltaTime);
      void destroy();
      void onCollisionEnter(GameObject* other);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
    private:
      Audio* jumpSound;
      bool jumped;
  };
}

#endif