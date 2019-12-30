#ifndef STARTROOMCONTROLLER_H
#define STARTROOMCONTROLLER_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject;

  class StartRoomController : public GameObject {
    public:
      // structs
      StartRoomController(Room* room);

      // overrides
      void setup();
      void update(int64_t deltaTime);
    private:
      // fields
      int maxOption;
      int selectedOption;
      int64_t maxTiming;
      int64_t timing;
      std::vector<LabelObject*> optionObjects;
      bool pressed;

      // methods
      void runOption(int option);
  };
}

#endif