/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef ENDINGPOINTOBJECT_H
#define ENDINGPOINTOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class EndingPointObject : public GameObject {
    public:
      EndingPointObject(GameRoom* room);
      void onCollisionEnter(GameObject* other);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
    private:
      GameRoom* room;
  };
}

#endif