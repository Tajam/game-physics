/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef COINOBJECT_H
#define COINOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class CoinObject : public GameObject {
    public:
      // structs
      CoinObject(GameRoom* room);
      
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