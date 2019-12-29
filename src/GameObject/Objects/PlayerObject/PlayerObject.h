#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class PlayerObject : public GameObject {
    public:
      // structs
      PlayerObject(Room* room);

      // overrides
      void setup();
      void update(int64_t deltaTime);
      void onCollisionEnter(GameObject* other);
      void onCollisionExit(GameObject* other);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
    private:
      // fields
      bool jumped;

  };
}

#endif