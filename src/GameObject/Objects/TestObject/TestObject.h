#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include "../../GameObject.h"
#include "../../../Audio/Audio.h"

namespace tjm {
  class TestObject: public GameObject {
    public:
      TestObject(Room* room);
      ~TestObject();
      void update();
    private:
      Audio* jumpSound;
      bool jumped;
  };
}

#endif