/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

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
      // const
      const static float B2ToSFML;
      const static float SFMLToB2;

      // structs
      GameObject(Room* room);
      virtual ~GameObject();

      // setters
      void setSpriteSheet(SpriteSheet* spriteSheet);
      void setBody(b2Body* body);
      void setActive(bool active);
      void setID(unsigned long id);
      void setTag(std::string tag);

      // getters
      bool isActive();
      b2Body* getBody();
      SpriteSheet* getSpriteSheet();
      unsigned long getID();
      bool tagCheck(std::string tag);
      bool haveBody();
      bool haveSprite();

      // virtuals
      virtual void setup();
      virtual void update(int64_t deltaTime);
      virtual void destroy();
      virtual void onDraw(Camera* camera, int64_t deltaTime);
      virtual void onCollisionEnter(GameObject* other);
      virtual void onCollisionExit(GameObject* other);
      virtual b2BodyDef* defineBody();
      virtual b2FixtureDef* defineFixture();
      virtual SpriteSheet* defineSprites();

      // methods
      void draw(Camera* camera, int64_t deltaTime);

    protected:
      // getters
      Room* getRoom();

      // fields
      bool _haveBody;
      bool _haveSprite;

    private:
      // references
      Room* room;
      b2Body* body;
      b2Fixture* fixture;
      SpriteSheet* spriteSheet;

      // stats
      unsigned long id;
      bool haveId;
      bool active;
      std::string tag;
  };
}

#include "ObjectsHeader.h"

#endif