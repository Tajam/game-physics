#ifndef COLLISION_H
#define COLLISION_H

#include "../Box2D/Box2D.h"

namespace tjm {
  class Collision : public b2ContactListener {
    public:
      void BeginContact(b2Contact* contact);
      void EndContact(b2Contact* contact);
  };
}

#endif