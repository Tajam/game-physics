#ifndef CAMERA_H
#define CAMERA_H


#include "../SFML/Graphics.hpp"

namespace tjm {
  class Camera {
    public:
      // functions
      Camera(sf::RenderWindow* window, sf::Vector2<int> maxSize);
      void draw(sf::Sprite sprite);

      // setter
      void setPosition(sf::Vector2<int> position);

      // getter
      int getX();
      int getY();

    private:
      // fields
      sf::RenderWindow* window;
      sf::Vector2<int>* position;
      sf::Vector2<int>* maxSize;

  };
}

#endif
