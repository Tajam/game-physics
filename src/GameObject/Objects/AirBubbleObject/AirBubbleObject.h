/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef AIRBUBBLEOBJECT_H
#define AIRBUBBLEOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class AirBubbleObject : public GameObject {
    public:
      // structs
      AirBubbleObject(GameRoom* room);

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