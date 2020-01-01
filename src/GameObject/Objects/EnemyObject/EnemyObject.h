#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#define PATH std::vector<std::pair<sf::Vector2i, int64_t>>

#include "../../GameObject.h"

namespace tjm {
  class GameRoom;

  class EnemyObject : public GameObject {
    public:
      // structs
      EnemyObject(GameRoom* room, PATH paths);
      
      // overrides
      void update(int64_t deltaTime);
      b2BodyDef* defineBody();
      b2FixtureDef* defineFixture();
      SpriteSheet* defineSprites();
      void onCollisionEnter(GameObject* other);

      // methods
      void setAnchor();
      
    private:
      // fields
      GameRoom* room;
      int64_t timing;
      b2Vec2 anchor;
      int index;
      PATH paths;
  };
}

#endif