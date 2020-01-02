/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef STARTROOMCONTROLLER_H
#define STARTROOMCONTROLLER_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject;

  class StartRoomController : public GameObject {
    public:
      // structs
      StartRoomController(Room* room);

      // overrides
      void setup();
      void update(int64_t deltaTime);
    private:
      // fields
      int maxOption;
      int selectedOption;
      int64_t maxTiming;
      int64_t timing;
      std::vector<LabelObject*> optionObjects;
      bool pressed;

      // methods
      void runOption(int option);
  };
}

#endif