/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef COLLISION_H
#define COLLISION_H

#include "../Box2D/Box2D.h"

namespace tjm {
  class Collision : public b2ContactListener {
    public:
      void BeginContact(b2Contact* contact);
      void EndContact(b2Contact* contact);
  };
}

#endif