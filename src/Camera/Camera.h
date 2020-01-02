/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef CAMERA_H
#define CAMERA_H


#include "../SFML/Graphics.hpp"

namespace tjm {
  class Camera {
    public:
      // functions
      Camera(sf::RenderWindow* window, sf::Vector2i maxSize);
      void draw(sf::Sprite sprite);
      void draw(sf::Text text);
      void draw(sf::RectangleShape rect);

      // setter
      void setPosition(sf::Vector2i position);

      // getter
      sf::Vector2i getPosition();
      sf::Vector2u getSize();

    private:
      // fields
      sf::RenderWindow* window;
      sf::View view;
      sf::Vector2i position;
      sf::Vector2i maxSize;

  };
}

#endif
