#ifndef GAMEROOM_H
#define GAMEROOM_H

#include "../../Room.h"

namespace tjm {
  class GameRoom : public Room {
    public:
      GameRoom(Game* game, int level);
    private:
      // fields
      bool pressed;
      bool started;
      int index;
      int64_t timing;
      int64_t maxTiming;
      b2Vec2 startPosition;

      // overrides
      void open();
      void step(int64_t deltaTime);
      void close();

      // methods
      void loadWalls();
      void loadObjects();
      void loadTiles();
  };
}

#endif