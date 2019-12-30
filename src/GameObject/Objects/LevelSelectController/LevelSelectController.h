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