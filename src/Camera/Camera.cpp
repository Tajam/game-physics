#include "Camera.h"
#include <iostream>

namespace tjm {
  Camera::Camera(sf::RenderWindow* window, sf::Vector2<int> maxSize) {
    this->window = window;
    this->position = new sf::Vector2<int>(0, 0);
    this->maxSize = &maxSize;
  }

  void Camera::draw(sf::Sprite sprite) {
    sf::Vector2<float> pos = sprite.getPosition();
    int tx = sprite.getTexture()->getSize().x;
    int ty = sprite.getTexture()->getSize().y;
    int wx = window->getSize().x;
    int wy = window->getSize().y;
    if ((pos.x + tx < position->x) || (pos.y + ty < position->y)) {
      return;
    }
    if  ((pos.x > position->x + wx) || (pos.y > position->y + wy)) {
      return;
    }
    
    window->draw(sprite);
  }

  void Camera::setPosition(sf::Vector2<int> position) {
    this->position = &position;
  }

  int Camera::getX() {
    return this->position->x;
  }

  int Camera::getY() {
    return this->position->y;
  }
}