/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "GameRoom.h"
#include "../../../Audio/Audio.h"
#include <fstream>
#include <sstream>

#define PATH_LIST std::vector<std::vector<std::pair<sf::Vector2i, int64_t>>>
#define PATH std::vector<std::pair<sf::Vector2i, int64_t>>

namespace tjm {
  GameRoom::GameRoom(Game* game, int level)
  : Room(game, sf::Vector2i(3200, 1600)) {
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    started = false;
    spawned = false;
    index = level;
    maxLevel = 4;
    timing = 0;
    maxTiming = 2000000;

    coins = 0;
    score = 0;
    totalTiming = 0;
    gameTiming = 10000000;
    expectedTiming = 10000000;
    timeLimit = true;
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

      // timer
      timer = new TimerDisplayObject(this);
      Instantiate(timer);
    } else {
      timing += deltaTime;
    }

    // time limitation
    if (started) {
      totalTiming += deltaTime;
      gameTiming -= deltaTime;
      float rate = (float)gameTiming / 10000000;
      timer->update(rate);
      if (gameTiming <= 0 && timeLimit) {
        gameFail();
        timer->update(0);
      }
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
    PATH_LIST paths = loadPath();
    int enemyCount = 0;
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
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            break;
          }
          // air bubble
          case 11: {
            AirBubbleObject* object = new AirBubbleObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            expectedTiming += 10000000;
            break;
          }
          // trap
          case 12: {
            TrapObject* object = new TrapObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            break;
          }
          // enemy
          case 14: {
            EnemyObject* object = new EnemyObject(this, paths[enemyCount]);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            object->setAnchor();
            enemyCount++;
            break;
          }
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
          case 21: {
            SwitchObject* object = new SwitchObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            switches.push_back(object);
            break;
          }
          // coin
          case 23: {
            CoinObject* object = new CoinObject(this);
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            break;
          }
          // red door
          case 32:
          case 33: {
            DoorObject* object = new DoorObject(this, (data == 33));
            Instantiate(object);
            object->getBody()->SetTransform(b2Vec2(((float)x * 16.f + 8.f) * SFMLToB2, ((float)y * 16.f + 8.f) * SFMLToB2), 0);
            doors.push_back(object);
            break;
          }
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

  PATH_LIST GameRoom::loadPath() {
    std::ifstream file("../assets/data/" + std::to_string(index) + "/path");
    PATH_LIST paths;
    int c;
    while(file >> c) {
      PATH path;
      for (int i = 0; i < c; i++) {
        int x, y;
        int64_t t;
        file >> x >> y >> t;
        sf::Vector2i position(x, y);
        std::pair<sf::Vector2i, int64_t> p(position, t);
        path.push_back(p);
      }
      paths.push_back(path);
    }
    return paths;
  }

  void GameRoom::gainCoin() {
    coins++;
  }

  void GameRoom::toggleSwitch() {
    for (int i = 0; i < doors.size(); i++) {
      doors[i]->toggle();
    }
    for (int i = 0; i < switches.size(); i++) {
      switches[i]->toggle();
    }
  }

  void GameRoom::resetGameTiming() {
    gameTiming = 10000000;
  }

  void GameRoom::gameClear() {
    if (started) {
      Destroy(playerID);
      int maxScore = 1000000 + coins * 250000;
      int score = (float)maxScore * ((float)(expectedTiming - totalTiming) / expectedTiming);
      Instantiate(new GameClearObject(this, score));
      Audio::playSound("win.wav");
      started = false;
    }
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