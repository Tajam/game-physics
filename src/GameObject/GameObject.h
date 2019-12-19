#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <map> 
#include <string>
#include "../Box2D/Box2D.h"
#include "../Room/Room.h"
#include "../Textures/SpriteSheet.h"

namespace tjm {
  class Room;

  class GameObject {
    public:
      // structs
      GameObject(Room* room);
      ~GameObject();

      // setters
      void setSpriteSheet(SpriteSheet* spriteSheet);
      void setBody(b2Body* body);
      void setActive(bool active);

      // getter
      bool isActive();
      b2Body* getBody();
      SpriteSheet* getSpriteSheet();

      // virtuals
      virtual void setup();
      virtual void update();
      virtual b2BodyDef* defineBody();
      virtual b2FixtureDef* defineFixture();
      virtual SpriteSheet* defineSprites();

    private:
      // references
      Room* room;
      b2Body* body;
      b2Fixture* fixture;
      SpriteSheet* spriteSheet;

      // stats
      bool active;
  };
}

#include "ObjectsHeader.h"

#endif