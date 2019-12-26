#include "Game.h"

namespace tjm {
  Game::Game() {
    isSwitching = false;
    isStopping = false;

    // physic world
    b2Vec2 gravity(0.0f, 100.f);
    world = new b2World(gravity);
    world->SetContactListener(new Collision());

    // render window
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "My framework works!");
    window->setFramerateLimit(60);

    // clock
    clock = new sf::Clock();

    // initial room
    currentRoom = new StartRoom(world, window);
    currentRoom->setup();
  }

  Game::~Game() {
    delete world;
    world = NULL;
    delete window;
    window = NULL;
    delete clock;
    clock = NULL;
    delete currentRoom;
    currentRoom = NULL;
    delete nextRoom;
    nextRoom = NULL;
  }

  void Game::run() {
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
      nextRoom = NULL;
    }
  }
}