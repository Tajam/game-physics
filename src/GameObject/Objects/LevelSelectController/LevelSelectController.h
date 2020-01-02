/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef LEVELSELECTCONTROLLER_H
#define LEVELSELECTCONTROLLER_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject;

  class LevelSelectController : public GameObject {
    public:
      LevelSelectController(Room* room);

      // overrides
      void setup();
      void update(int64_t deltaTime);
    private:
      // fields
      int maxOption;
      int selectedOption;
      int maxLevel;
      int selectedLevel;
      int64_t maxTiming;
      int64_t timing;
      std::vector<LabelObject*> optionObjects;
      bool pressed;

      // methods
      void runOption(int option);
  };
}

#endif