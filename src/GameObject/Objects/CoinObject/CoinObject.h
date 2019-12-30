#ifndef COINOBJECT_H
#define COINOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class CoinObject : public GameObject {
    public:
      // structs
      CoinObject(GameRoom* room);
      
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