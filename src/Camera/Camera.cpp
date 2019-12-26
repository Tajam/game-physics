#include "Camera.h"
#include <iostream>

namespace tjm {
  Camera::Camera(sf::RenderWindow* window, sf::Vector2<int> maxSize) {
    this->window = window;
    this->position = sf::Vector2<int>(0, 0);
    this->maxSize = maxSize;

    float wx = window->getSize().x;
    float wy = window->getSize().y;
    this->view = sf::View(sf::FloatRect(0, 0, wx, wy));
    this->window->setView(this->view);
  }

  void Camera::draw(sf::Sprite sprite) {
    sf::Vector2<float> pos = sprite.getPosition();
    int tx = sprite.getTextureRect().width;
    int ty = sprite.getTextureRect().height;
    int wx = window->getSize().x;
    int wy = window->getSize().y;
    if ((pos.x + tx < position.x) || (pos.y + ty < position.y)) {
      return;
    }
    if  ((pos.x > position.x + wx) || (pos.y > position.y + wy)) {
      return;
    }
    window->draw(sprite);
  }

  void Camera::draw(sf::Text text) {
    window->draw(text);
  }

  void Camera::setPosition(sf::Vector2<int> position) {
    int wx = window->getSize().x;
    int wy = window->getSize().y;
    int posX = position.x - wx / 2;
    int posY = position.y - wy / 2;
    if (posX < 0) posX = 0;
    if (posY < 0) posY = 0;
    if (posX + wx > maxSize.x) posX = maxSize.x - wx;
    if (posY + wy > maxSize.y) posY = maxSize.y - wy;
    this->position = sf::Vector2i(posX, posY);
    this->view.setCenter(posX + wx / 2, posY + wy / 2);
    this->window->setView(this->view);
  }

  int Camera::getX() {
    return this->position.x;
  }

  int Camera::getY() {
    return this->position.y;
  }
}