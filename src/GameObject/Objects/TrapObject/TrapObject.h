/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef TRAPOBJECT_H
#define TRAPOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class TrapObject : public GameObject {
    public:
      // structs
      TrapObject(GameRoom* room);
      
      // overrides
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
      void onCollisionEnter(GameObject* other);
      
    private:
      // fields
      GameRoom* room;
  };
}

#endif