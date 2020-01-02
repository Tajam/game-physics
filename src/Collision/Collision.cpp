/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "Collision.h"
#include "../GameObject/GameObject.h"

namespace tjm {
  void Collision::BeginContact(b2Contact* contact) {
    void* aObjectData = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bObjectData = contact->GetFixtureB()->GetBody()->GetUserData();
    if (aObjectData && bObjectData) {
      GameObject* gameObjectA = static_cast<GameObject*>(aObjectData);
      GameObject* gameObjectB = static_cast<GameObject*>(bObjectData);
      gameObjectA->onCollisionEnter(gameObjectB);
      gameObjectB->onCollisionEnter(gameObjectA);
    }
  }

  void Collision::EndContact(b2Contact* contact) {
    void* aObjectData = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bObjectData = contact->GetFixtureB()->GetBody()->GetUserData();
    if (aObjectData && bObjectData) {
      GameObject* gameObjectA = static_cast<GameObject*>(aObjectData);
      GameObject* gameObjectB = static_cast<GameObject*>(bObjectData);
      gameObjectA->onCollisionExit(gameObjectB);
      gameObjectB->onCollisionExit(gameObjectA);
    }
  }
}