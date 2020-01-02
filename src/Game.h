/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef GAME_H
#define GAME_H

#include "Room/Room.h"
#include "Collision/Collision.h"
#include "SFML/System/Clock.hpp"

namespace tjm {
  class Room;
  
  class Game {
    public:
      // struct
      Game();
      ~Game();

      // getters
      b2World* getWorld();
      sf::RenderWindow* getWindow();
      
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
      bool isRunning;
      bool isSwitching;
      bool isStopping;

      // methods
      void _switchRoom();
  };
}

#endif