#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "../Camera/Camera.h"
#include "../GameObject/GameObject.h"

namespace tjm {
  class GameObject;

  class Room {
    public:
      // structs
      Room(b2World* world, sf::RenderWindow* window, sf::Vector2<int> maxSize);
      ~Room();

      // setters
      void setFollow(unsigned long id);

      // getters
      sf::Vector2i getFollow();

      // methods
      void setup();
      void update(int64_t deltaTime);
      void tearDown();
      void setBackground(std::string fileName);
      void Instantiate(GameObject* gameObject);
      void Destroy(unsigned long id);

    private:
      // fields
      b2World* world;
      Camera* camera;
      unsigned long followObject;
      unsigned long objectCount;
      bool isFollow;
      std::vector<GameObject*> addingObjects;
      std::vector<unsigned long> removingObjects;
      std::map<unsigned long, GameObject*> objects;
      sf::Sprite background;
      sf::Vector2i roomSize;

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