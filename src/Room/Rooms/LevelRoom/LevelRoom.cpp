/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "LevelRoom.h"

namespace tjm {
  LevelRoom::LevelRoom(Game* game)
  : Room(game, sf::Vector2<int>(1280, 720)) { }

  void LevelRoom::open() {
    setBackground("main-bg.jpg");
    Instantiate(new LevelSelectController(this));
  }
}