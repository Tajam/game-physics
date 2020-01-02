/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "TileMasterObject.h"

namespace tjm {
  TileMasterObject::TileMasterObject(Room* room) : GameObject(room) {
    _haveBody = false;
    _haveSprite = false;
  }

  TileMasterObject::~TileMasterObject() {
    delete getSpriteSheet();
    setSpriteSheet(nullptr);
  }

  void TileMasterObject::setup() {
    SpriteLoader loader("tiles.png", sf::Vector2i(20, 15));
    loader.setStartPoint(sf::Vector2i(1, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setGap(sf::Vector2i(1, 1));
    SpriteSheet* sheet = new SpriteSheet(loader);
    setSpriteSheet(sheet);
  }

  void TileMasterObject::onDraw(Camera* camera, int64_t deltaTime) {
    for (int i = 0; i < tiles.size(); i++) {
      getSpriteSheet()->setFrame(tiles[i].first);
      sf::Sprite sprite = getSpriteSheet()->getSprite();
      sprite.setPosition(tiles[i].second.x, tiles[i].second.y);
      camera->draw(sprite);
    }
  }

  void TileMasterObject::addTile(int index, sf::Vector2i position) {
    tiles.push_back(std::pair<int, sf::Vector2i>(index, position));
  }
}