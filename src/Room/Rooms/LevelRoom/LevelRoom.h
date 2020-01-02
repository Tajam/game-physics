/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

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