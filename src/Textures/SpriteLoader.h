#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <string>
#include <vector>
#include <map>
#include "../SFML/Graphics.hpp"

namespace tjm {
  class SpriteLoader {
    public:
      // methods
      SpriteLoader(std::string fileName, sf::Vector2<int> number);
      void setStartPoint(sf::Vector2<int> startPoint);
      void setSize(sf::Vector2<int> size);
      void setGap(sf::Vector2<int> gap);
      std::vector<sf::IntRect> getRect();
      sf::Sprite getSprite();
    private:
      // cache
      static std::map<std::string, sf::Texture*> textureCache;
      // fields
      sf::Vector2<int> startPoint;
      sf::Vector2<int> size;
      sf::Vector2<int> gap;
      sf::Vector2<int> number;
      std::string fileName;
  };
}

#endif