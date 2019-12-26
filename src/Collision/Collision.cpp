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