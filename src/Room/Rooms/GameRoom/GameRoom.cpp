#include "GameRoom.h"
#include "../../../Audio/Audio.h"
#include <fstream>
#include <sstream>

namespace tjm {
  GameRoom::GameRoom(Game* game, int level)
  : Room(game, sf::Vector2i(3200, 1600)) {
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    started = false;
    index = level;
    timing = 0;
    maxTiming = 2000000;
  }

  void GameRoom::open() {
    Audio::playMusic("level-bgm.ogg");
    setBackground("level-bg.jpg");
    loadWalls();
    loadObjects();
    loadTiles();
  }

  void GameRoom::step(int64_t deltaTime) {

    // quit
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      if (!pressed) {
        getGame()->switchRoom(new StartRoom(getGame()));
        Audio::playSound("bubble.wav");
        pressed = true;
      }
    } else {
      pressed = false;
    }

    // start countdown
    if (timing >= maxTiming && !started) {
      started = true;
      PlayerObject* player = new PlayerObject(this);
      Instantiate(player);
      player->getBody()->SetTransform(startPosition, 0);
      setFollow(player->getID());
      Audio::playSound("start.wav");
    } else {
      timing += deltaTime;
    }
  }

  void GameRoom::close() {
    resetFollow();
  }

  void GameRoom::loadWalls() {
    WallMasterObject* object = new WallMasterObject(this);
    Instantiate(object);
    std::ifstream file("../assets/data/" + std::to_string(index) + "/wall");
    int sx, sy;
    while (file >> sx >> sy) {
      std::vector<b2Vec2> vertices;
      int px, py;
      for (int i = 0; i < 4; i++) {
        file >> px >> py;
        float posX = (float)(sx + px) * SFMLToB2;
        float posY = (float)(sy + py) * SFMLToB2;
        vertices.push_back(b2Vec2(posX, posY));
      }
      object->buildWall(vertices);
    }
  }

  void GameRoom::loadObjects() {
    std::ifstream file("../assets/data/" + std::to_string(index) + "/object");
    int data;
    for (int y = 0; y < 100; y++) {
      for (int x = 0; x < 200; x++) {
        file >> data;
        switch(data) {
          // dynamic wall
          case 7:
          break;
          // air bubble
          case 11:
          break;
          // trap
          case 12:
          break;
          // enemy
          case 14:
          break;
          // start point
          case 18: {
            StartingPointObject* object = new StartingPointObject(this);
            Instantiate(object);
            startPosition = b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f) * SFMLToB2);
            object->getBody()->SetTransform(startPosition, 0);
            setFollow(object->getID());
            break;
          }
          // end point
          case 19:
          break;
          // switch
          case 21:
          break;
          // coin
          case 23:
          break;
          // blue door 
          case 34:
          break;
          // red door
          case 35:
          break;
        }
      }
    }
  }

  void GameRoom::loadTiles() {
    TileMasterObject* tileMaster = new TileMasterObject(this);
    std::ifstream file("../assets/data/" + std::to_string(index) + "/tile");
    int data;
    for (int y = 0; y < 100; y++) {
      for (int x = 0; x < 200; x++) {
        file >> data;
        if (data == -1) continue;
        tileMaster->addTile(data, sf::Vector2i(x * 16 + 8, y * 16 + 8));
      }
    }
    Instantiate(tileMaster);
  }
}