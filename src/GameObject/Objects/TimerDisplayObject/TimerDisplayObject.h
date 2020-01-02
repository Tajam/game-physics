#ifndef TIMERDISPLAYOBJECT
#define TIMERDISPLAYOBJECT

#include "../../GameObject.h"

namespace tjm {
  class LabelObject;

  class TimerDisplayObject : public GameObject {
    public:
      // structs
      TimerDisplayObject(Room* room);
      ~TimerDisplayObject();

      // overrides
      void setup();
      void onDraw(Camera* camera, int64_t deltaTime);

      // methods
      void update(float rate);
      
    private:
      // colours
      float red;
      float green;
      
      // fields
      float rate;
      LabelObject* upperLabel;
      LabelObject* lowerLabel;

  };
}

#endif