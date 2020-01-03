/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "Game.h"
#include <ctime>

namespace tjm {
  Game::Game() {
    isSwitching = false;
    isStopping = false;
    isRunning = false;
    pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::F12);

    // physic world
    b2Vec2 gravity(0.0f, .5f);
    world = new b2World(gravity);
    world->SetContactListener(new Collision());

    // render window
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "5 Seconds Diver");
    window->setFramerateLimit(60);

    // clock
    clock = new sf::Clock();

    // initial room
    currentRoom = new StartRoom(this);
    currentRoom->setup();
  }

  Game::~Game() {
    delete world;
    world = nullptr;
    delete window;
    window = nullptr;
    delete clock;
    clock = nullptr;
    delete currentRoom;
    currentRoom = nullptr;
    delete nextRoom;
    nextRoom = nullptr;
  }

  b2World* Game::getWorld() {
    return world;
  }

  sf::RenderWindow* Game::getWindow() {
    return window;
  }

  void Game::run() {
    if (isRunning) return;
    isRunning = true;
    while (window->isOpen()) {
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window->close();
      }
      window->clear();

      sf::Time time = clock->restart();
      currentRoom->update(time.asMicroseconds());
      
      window->display();

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) {
        if (!pressed) {
          pressed = true;
          sf::Texture texture;
          texture.create(window->getSize().x, window->getSize().y);
          texture.update(*window);
          std::time_t result = std::time(nullptr);
          texture.copyToImage().saveToFile("../ss/" + std::to_string(result) + ".png");
        }
      } else {
        pressed = false;
      }

      if (isStopping) {
        break;
      }
      _switchRoom();
    }
  }

  void Game::stop() {
    isStopping = true;
  }

  void Game::switchRoom(Room* room) {
    nextRoom = room;
    isSwitching = true;
  }

  void Game::_switchRoom() {
    if (isSwitching) {
      isSwitching = false;
      currentRoom->tearDown();
      delete currentRoom;
      currentRoom = nextRoom;
      currentRoom->setup();
    }
  }
}