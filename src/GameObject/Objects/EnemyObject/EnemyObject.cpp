/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "EnemyObject.h"
#include "../../../Audio/Audio.h"

#define PATH std::vector<std::pair<sf::Vector2i, int64_t>>

namespace tjm {
  EnemyObject::EnemyObject(GameRoom* room, PATH paths) : GameObject(room) {
    this->room = room;
    this->paths = paths;
    timing = 0;
    index = 0;
  }

  void EnemyObject::setAnchor() {
    anchor = getBody()->GetPosition();
  }

  void EnemyObject::update(int64_t deltaTime) {
    timing += deltaTime;
    sf::Vector2i position = paths[index].first;
    int64_t maxTime = paths[index].second;
    float t = ((float)timing / maxTime);
    float posX = (float)position.x * SFMLToB2;
    float posY = (float)position.y * SFMLToB2;
    getBody()->SetTransform(anchor + b2Vec2(posX * t, posY * t), 0);
    if (timing >= maxTime) {
      timing -= maxTime;
      index++;
      if (index >= paths.size()) {
        index = 0;
      }
      getBody()->SetTransform(anchor + b2Vec2(posX, posY), 0);
      anchor = getBody()->GetPosition();

      // change facing direction
      sf::Vector2i facePos = paths[index].first;
      if (facePos.x > 0) {
        getSpriteSheet()->setFrame(1);
      } else if (facePos.x < 0) {
        getSpriteSheet()->setFrame(3);
      } else if (facePos.y > 0) {
        getSpriteSheet()->setFrame(2);
      } else if (facePos.y < 0) {
        getSpriteSheet()->setFrame(0);
      }
    }
  }
      
  b2BodyDef* EnemyObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    return def;
  }

  b2FixtureDef* EnemyObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8.f * SFMLToB2, 8.f * SFMLToB2);
    def->shape = box;
    def->isSensor = true;
    return def;
  }

  SpriteSheet* EnemyObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(4, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setStartPoint(sf::Vector2i(86, 18));
    loader.setGap(sf::Vector2i(1, 1));
    SpriteSheet* sheet = new SpriteSheet(loader);
    return sheet;
  }
  
  void EnemyObject::onCollisionEnter(GameObject* other) {
    if (other->tagCheck("player")) {
      room->gameFail();
    }
  }

}