#ifndef CREDITROOM_H
#define CREDITROOM_H

#include "../../Room.h"

namespace tjm {
  class LabelObject;

  class CreditRoom : public Room {
    public:
      CreditRoom(Game* game);
    private:
      // overrides
      void open();
      void step(int64_t deltaTime);

      // fields
      bool pressed;
      int64_t timing;
      int64_t maxTiming;
      LabelObject* backLabel;
  };
}

#endif