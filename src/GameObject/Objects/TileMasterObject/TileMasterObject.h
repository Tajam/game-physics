#ifndef TILEMASTEROBJECT_H
#define TILEMASTEROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class TileMasterObject : public GameObject {
    public:
      // structs
      TileMasterObject(Room* room);
      ~TileMasterObject();

      // overrides
      void setup();
      void onDraw(Camera* camera, int64_t deltaTime);

      // methods
      void addTile(int index, sf::Vector2i position);

    private:
      // fields
      std::vector<std::pair<int, sf::Vector2i>> tiles;
  };
}

#endif