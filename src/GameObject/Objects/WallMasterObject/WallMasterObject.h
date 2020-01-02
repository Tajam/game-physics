/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef WALLMASTEROBJECT_H
#define WALLMASTEROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class WallMasterObject : public GameObject {
    public:
      // structs
      WallMasterObject(Room* room);

      // overrides
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();

      // methods
      void buildWall(b2Vec2 position, b2Vec2 size);
  };
}

#endif