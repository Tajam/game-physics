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

      // methods
      LabelObject* makeLabel(std::string text, unsigned int size, sf::Vector2f position, sf::Color color);

      // fields
      bool pressed;
      int64_t timing;
      int64_t maxTiming;
      LabelObject* backLabel;
      LabelObject* backShadow;
  };
}

#endif