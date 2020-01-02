/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "../Camera/Camera.h"
#include "../GameObject/GameObject.h"
#include "../Game.h"

namespace tjm {
  class Game;
  class GameObject;

  class Room {
    public:
      // const
      const static float B2ToSFML;
      const static float SFMLToB2;

      // structs
      Room(Game* game, sf::Vector2i maxSize);
      virtual ~Room();

      // setters
      void setFollow(unsigned long id);
      void resetFollow();

      // getters
      sf::Vector2i getFollow();
      Game* getGame();

      // methods
      void setup();
      void update(int64_t deltaTime);
      void tearDown();
      void setBackground(std::string fileName);
      void Instantiate(GameObject* gameObject);
      void Destroy(unsigned long id);

    private:
      // fields
      Game* game;
      b2World* world;
      Camera* camera;
      unsigned long followObject;
      unsigned long objectCount;
      int64_t requiredTime;
      int64_t frameTime;
      bool isFollow;
      bool haveBackground;
      std::vector<GameObject*> addingObjects;
      std::vector<unsigned long> removingObjects;
      std::map<unsigned long, GameObject*> objects;
      sf::Sprite background;

      // methods
      void cameraFollow();

      // virtuals
      virtual void open();
      virtual void step(int64_t deltaTime);
      virtual void close();
  };
}

#include "RoomsHeader.h"

#endif