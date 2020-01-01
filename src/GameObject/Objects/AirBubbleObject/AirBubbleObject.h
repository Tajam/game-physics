#ifndef AIRBUBBLEOBJECT_H
#define AIRBUBBLEOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class AirBubbleObject : public GameObject {
    public:
      // structs
      AirBubbleObject(GameRoom* room);

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