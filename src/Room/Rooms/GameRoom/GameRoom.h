#ifndef GAMEROOM_H
#define GAMEROOM_H

#define PATH_LIST std::vector<std::vector<std::pair<sf::Vector2i, int64_t>>>

#include "../../Room.h"

namespace tjm {
  class DoorObject;
  class SwitchObject;

  class GameRoom : public Room {
    public:
      // structs
      GameRoom(Game* game, int level);

      // methods
      void gainCoin();
      void toggleSwitch();
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
      int64_t totalTiming;
      int64_t expectedTiming;
      bool timeLimit;

      std::vector<DoorObject*> doors;
      std::vector<SwitchObject*> switches;

      // overrides
      void open();
      void step(int64_t deltaTime);
      void close();

      // methods
      void loadWalls();
      void loadObjects();
      void loadTiles();
      PATH_LIST loadPath();
  };
}

#endif