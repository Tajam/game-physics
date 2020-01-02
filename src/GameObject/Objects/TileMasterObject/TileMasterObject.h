/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

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