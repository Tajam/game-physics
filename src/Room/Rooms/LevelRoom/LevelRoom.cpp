#include "LevelRoom.h"

namespace tjm {
  LevelRoom::LevelRoom(Game* game)
  : Room(game, sf::Vector2<int>(1280, 720)) { }

  void LevelRoom::open() {
    setBackground("main-bg.jpg");
    Instantiate(new LevelSelectController(this));
  }
}