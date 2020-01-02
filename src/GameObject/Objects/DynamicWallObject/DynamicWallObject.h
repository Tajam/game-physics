/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef DYNAMICWALLOBJECT_H
#define DYNAMICWALLOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class DynamicWallObject : public GameObject {
    public:
      // structs
      DynamicWallObject(Room* room);
      
      // overrides
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
  };
}

#endif