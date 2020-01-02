/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "SpriteLoader.h"

namespace tjm {

  std::map<std::string, sf::Texture*> SpriteLoader::textureCache;

  SpriteLoader::SpriteLoader(std::string fileName, sf::Vector2<int> number) {
    startPoint = sf::Vector2<int>(0, 0);
    size = sf::Vector2<int>(16, 16);
    gap = sf::Vector2<int>(0, 0);
    this->number = number;
    this->fileName = "../assets/textures/" + fileName;
  }

  SpriteLoader::SpriteLoader() {
    startPoint = sf::Vector2<int>(0, 0);
    size = sf::Vector2<int>(16, 16);
    gap = sf::Vector2<int>(0, 0);
    this->number = sf::Vector2i(1, 0);
    this->fileName = "/";
  }

  void SpriteLoader::setStartPoint(sf::Vector2<int> startPoint) {
    this->startPoint = startPoint;
  }

  void SpriteLoader::setSize(sf::Vector2<int> size) {
    this->size = size;
  }

  void SpriteLoader::setGap(sf::Vector2<int> gap) {
    this->gap = gap;
  }

  std::vector<sf::IntRect> SpriteLoader::getRect() {
    std::vector<sf::IntRect> rects;
    for (int y = 0; y < number.y; y++) {
      for (int x = 0; x < number.x; x++) {
        int sx = startPoint.x + x * size.x + x * gap.x;
        int sy = startPoint.y + y * size.y + y * gap.y;
        sf::IntRect rect(sx, sy, size.x ,size.y);
        rects.push_back(rect);
      }
    }
    return rects;
  }

  sf::Sprite SpriteLoader::getSprite() {
    if (SpriteLoader::textureCache.find(fileName) != SpriteLoader::textureCache.end()) {
      return sf::Sprite(*SpriteLoader::textureCache[fileName]);
    } else {
      sf::Image image;
      if (!image.loadFromFile(fileName.c_str())) {
        image.create(16, 16);
      }
      image.createMaskFromColor(sf::Color(195, 195, 195));
      sf::Texture* texture = new sf::Texture();
      texture->loadFromImage(image);
      texture->setRepeated(true);
      SpriteLoader::textureCache.insert(std::pair<std::string, sf::Texture*>(fileName, texture));
      return sf::Sprite(*texture);
    }
  }
}