#ifndef WALLMASTEROBJECT_H
#define WALLMASTEROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class WallMasterObject : public GameObject {
    public:
      // structs
      WallMasterObject(Room* room);

      // overrides
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();

      // methods
      void buildWall(std::vector<b2Vec2> points);
  };
}

#endif