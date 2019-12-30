#ifndef ENDINGPOINTOBJECT_H
#define ENDINGPOINTOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class EndingPointObject : public GameObject {
    public:
      EndingPointObject(GameRoom* room);
      void onCollisionEnter(GameObject* other);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
    private:
      GameRoom* room;
  };
}

#endif