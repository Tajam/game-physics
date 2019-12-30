#ifndef TRAPOBJECT_H
#define TRAPOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class TrapObject : public GameObject {
    public:
      // structs
      TrapObject(GameRoom* room);
      
      // overrides
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
      void onCollisionEnter(GameObject* other);
      
    private:
      // fields
      GameRoom* room;
  };
}

#endif