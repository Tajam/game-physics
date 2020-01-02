/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class PlayerObject : public GameObject {
    public:
      // structs
      PlayerObject(Room* room);

      // overrides
      void setup();
      void update(int64_t deltaTime);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
    private:
      // fields
      bool jumped;

  };
}

#endif