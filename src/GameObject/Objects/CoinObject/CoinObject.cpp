/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "CoinObject.h"
#include "../../../Audio/Audio.h"

namespace tjm {
  CoinObject::CoinObject(GameRoom* room) : GameObject(room) {
    this->room = room;
  }
      
  b2BodyDef* CoinObject::defineBody() {
    b2BodyDef* def = new b2BodyDef();
    def->type = b2BodyType::b2_staticBody;
    return def;
  }

  b2FixtureDef* CoinObject::defineFixture() {
    b2FixtureDef* def = new b2FixtureDef();
    b2PolygonShape* box = new b2PolygonShape();
    box->SetAsBox(8.f * SFMLToB2, 8.f * SFMLToB2);
    def->shape = box;
    def->isSensor = true;
    return def;
  }

  SpriteSheet* CoinObject::defineSprites() {
    SpriteLoader loader("objects.png", sf::Vector2i(4, 1));
    loader.setSize(sf::Vector2i(16, 16));
    loader.setStartPoint(sf::Vector2i(86, 35));
    loader.setGap(sf::Vector2i(1, 1));
    SpriteSheet* sheet = new SpriteSheet(loader);
    sheet->setFrame(0);
    sheet->setInterval(83333);
    sheet->setTimeline(0, 3, 1);
    sheet->setLoop(true);
    sheet->play();
    return sheet;
  }
  
  void CoinObject::onCollisionEnter(GameObject* other) {
    if (other->tagCheck("player")) {
      room->gainCoin();
      getRoom()->Destroy(getID());
      Audio::playSound("coin.wav");
    }
  }

}