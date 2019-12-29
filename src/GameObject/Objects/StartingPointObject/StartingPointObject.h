#ifndef STARTPOINTOBJECT_H
#define STARTPOINTOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class StartingPointObject : public GameObject {
    public:
      StartingPointObject(Room* room);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
  };
}

#endif