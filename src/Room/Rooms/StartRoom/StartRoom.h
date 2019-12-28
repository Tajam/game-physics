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

      // methods
      LabelObject* makeLabel(std::string text, unsigned int size, sf::Vector2i position, sf::Color color);

      // fields
      int64_t timing;
      int64_t maxTiming;
      std::vector<LabelObject*> fiveLabels;
  };
}

#endif