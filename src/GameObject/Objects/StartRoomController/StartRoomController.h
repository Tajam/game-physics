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
      std::vector<LabelObject*> optionShadows;
      bool pressed;

      // methods
      LabelObject* makeLabel(std::string text, sf::Vector2f position, sf::Color color);
      void runOption(int option);
  };
}

#endif