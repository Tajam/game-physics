#ifndef DOOROBJECT_H
#define DOOROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class DoorObject : public GameObject {
    public:
      // structs
      DoorObject(Room* room, bool isRed);

      // overrides
      void setup();
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();

      // methods
      void toggle();
    private:
      bool isRed;
  };
}

#endif