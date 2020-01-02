/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

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