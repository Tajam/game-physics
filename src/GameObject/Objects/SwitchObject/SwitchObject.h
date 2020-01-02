/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef SWTICHOBJECT_H
#define SWTICHOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class SwitchObject : public GameObject {
    public:
      // structs
      SwitchObject(GameRoom* room);

      // overrides
      void onCollisionEnter(GameObject* other);
      void onCollisionExit(GameObject* other);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();

      // methods
      void toggle();

    private:
      // fields
      GameRoom* room;
      bool isRed;
      bool isEntered;
  };
}

#endif