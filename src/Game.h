#ifndef GAME_H
#define GAME_H

#include "Room/Room.h"
#include "Collision/Collision.h"
#include "SFML/System/Clock.hpp"

namespace tjm {
  class Game {
    public:
      // struct
      Game();
      ~Game();
      
      // method
      void run();
      void stop();
      void switchRoom(Room* room);

    private:
      // physics world and window
      b2World* world;
      sf::RenderWindow* window;
      sf::Clock* clock;

      // fields
      Room* currentRoom;
      Room* nextRoom;
      bool isSwitching;
      bool isStopping;

      // methods
      void _switchRoom();
  };
}

#endif