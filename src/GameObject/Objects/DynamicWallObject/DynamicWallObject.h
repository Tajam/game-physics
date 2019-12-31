#ifndef DYNAMICWALLOBJECT_H
#define DYNAMICWALLOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class DynamicWallObject : public GameObject {
    public:
      // structs
      DynamicWallObject(Room* room);
      
      // overrides
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
  };
}

#endif