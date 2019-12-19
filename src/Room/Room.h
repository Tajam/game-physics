#ifndef ROOM_H
#define ROOM_H

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
      void setFollow(GameObject* gameObject);

      // methods
      void setup();
      void update(int64_t deltaTime);
      void tearDown();
      template<class T> void Instantiate(T* gameObject);

    private:
      // fields
      b2World* world;
      Camera* camera;
      GameObject* followObject;
      int objectCount;
      std::vector<GameObject*> addingObjects;
      std::vector<unsigned long> removingObjects;
      std::map<unsigned long, GameObject*> objects;

      // virtuals
      virtual void open();
      virtual void step();
      virtual void close();
  };
}

#endif