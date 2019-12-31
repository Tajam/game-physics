#include "GameRoom.h"
#include "../../../Audio/Audio.h"
#include <fstream>
#include <sstream>

namespace tjm {
  GameRoom::GameRoom(Game* game, int level)
  : Room(game, sf::Vector2i(3200, 1600)) {
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    started = false;
    spawned = false;
    index = level;
    maxLevel = 1;
    timing = 0;
    maxTiming = 2000000;

    coins = 0;
    score = 0;
    totalTiming = 0;
    gameTiming = 0;
    gameMaxTiming = 10000000;
    expectedTiming = 10000000;
    timeLimit = false;
  }

  void GameRoom::open() {
    if (index >= maxLevel) {
      getGame()->switchRoom(new CreditRoom(getGame()));
      return;
    }
    Audio::playMusic("level-bgm.ogg");
    setBackground("level-bg.jpg");
    loadWalls();
    loadTiles();
    loadObjects();
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
    if (timing >= maxTiming && !spawned) {
      spawned = true;
      started = true;
      PlayerObject* player = new PlayerObject(this);
      Instantiate(player);
      player->getBody()->SetTransform(startPosition, 0);
      setFollow(player->getID());
      Audio::playSound("start.wav");
      playerID = player->getID();
    } else {
      timing += deltaTime;
    }

    // time limitation
    if (started) {

    }
  }

  void GameRoom::close() {
    resetFollow();
  }

  void GameRoom::loadWalls() {
    WallMasterObject* object = new WallMasterObject(this);
    Instantiate(object);
    std::ifstream file("../assets/data/" + std::to_string(index) + "/wall");
    int px, py, sx, sy;
    while (file >> px >> py >> sx >> sy) {
      float _px = (float)px * SFMLToB2;
      float _py = (float)py * SFMLToB2;
      float _sx = (float)sx * SFMLToB2;
      float _sy = (float)sy * SFMLToB2;
      b2Vec2 position(_px, _py);
      b2Vec2 size(_sx, _sy);
      object->buildWall(position, size);
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
          case 7: {
            DynamicWallObject* object = new DynamicWallObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f) * SFMLToB2), 0);
            break;
          }
          // air bubble
          case 11:
          break;
          // trap
          case 12: {
            TrapObject* object = new TrapObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f) * SFMLToB2), 0);
            break;
          }
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
          case 19: {
            EndingPointObject* object = new EndingPointObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f) * SFMLToB2), 0);
            break;
          }
          // switch
          case 21:
          break;
          // coin
          case 23: {
            CoinObject* object = new CoinObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f) * SFMLToB2), 0);
            break;
          }
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

  void GameRoom::gainCoin() {
    coins++;
  }

  void GameRoom::resetGameTiming() {
    gameTiming = gameMaxTiming;
  }

  void GameRoom::gameClear() {
    Destroy(playerID);
    int maxScore = 1000000 + coins * 250000;
    int score = (float)maxScore * ((float)(expectedTiming - totalTiming) / expectedTiming);
    Instantiate(new GameClearObject(this, score));
    Audio::playSound("win.wav");
  }

  void GameRoom::gameFail() {
    if (started) {
      Destroy(playerID);
      Instantiate(new GameFailObject(this));
      Audio::playSound("lose.wav");
      started = false;
    }
  }

  void GameRoom::jumpLevel(int jump) {
    getGame()->switchRoom(new GameRoom(getGame(), index + jump));
  }
}