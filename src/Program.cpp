#include "Room/Room.h"
#include "SFML/System/Clock.hpp"

int main() {
  b2Vec2 gravity(0.0f, 100.f);
	b2World world(gravity);

  float timeStep = 1.0f / 60.0f;
	int velocityIterations = 6;
	int positionIterations = 2;

  sf::RenderWindow window(sf::VideoMode(640, 480), "My framework works!");
  window.setFramerateLimit(60);
  tjm::Room Room(&world, &window, sf::Vector2<int>(1280, 960));
  Room.setup();

  sf::Clock clock;
  while (window.isOpen()) {
		world.Step(timeStep, velocityIterations, positionIterations);
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();

    sf::Time time = clock.restart();
    Room.update(time.asMicroseconds());
    
    window.display();
  }
}