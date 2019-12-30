#ifndef GAMEROOM_H
#define GAMEROOM_H

#include "../../Room.h"

namespace tjm {
  class GameRoom : public Room {
    public:
      // structs
      GameRoom(Game* game, int level);

      // methods
      void gainCoin();
      void resetGameTiming();
      void gameClear();
      void gameFail();
      void jumpLevel(int jump);
    private:
      // fields
      bool pressed;
      bool started;
      bool spawned;
      int index;
      int maxLevel;
      int64_t timing;
      int64_t maxTiming;
      b2Vec2 startPosition;

      unsigned long playerID;
      int coins;
      int score;
      int64_t gameTiming;
      int64_t gameMaxTiming;
      int64_t totalTiming;
      int64_t expectedTiming;
      bool timeLimit;

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