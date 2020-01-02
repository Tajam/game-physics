/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef STARTROOM_H
#define STARTROOM_H

#include "../../Room.h"

namespace tjm {
  class LabelObject;

  class StartRoom : public Room {
    public:
      StartRoom(Game* game);
    private:
      // overrides
      void open();
      void step(int64_t deltaTime);

      // fields
      int64_t timing;
      int64_t maxTiming;
      std::vector<LabelObject*> fiveLabels;
  };
}

#endif