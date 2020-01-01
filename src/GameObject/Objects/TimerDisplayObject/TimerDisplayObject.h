#ifndef TIMERDISPLAYOBJECT
#define TIMERDISPLAYOBJECT

#include "../../GameObject.h"

namespace tjm {
  class TimerDisplayObject : public GameObject {
    public:
      // structs
      TimerDisplayObject(Room room);

      // methods
      void update(float rate);
    private:
      // colours
      int red;
      int green;


  };
}

#endif