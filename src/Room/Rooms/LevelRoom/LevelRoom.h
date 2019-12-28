#ifndef LEVELROOM_H
#define LEVELROOM_H

#include "../../Room.h"

namespace tjm {
  class LevelRoom : public Room {
    public:
      LevelRoom(Game* game);
    private:
      // overrides
      void open();
  };
}

#endif