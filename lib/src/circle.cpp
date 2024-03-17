#include <SFML/Graphics.hpp>
#include "gc.h"
#include "record.hpp"
#include "maybe.hpp"


#ifdef __cplusplus
extern "C" {
#endif

void madsfml__drawCircle(sf::CircleShape *d, sf::RenderWindow *window) {
  window->draw(*d);
}


sf::CircleShape *madsfml__setCircleFillColor(int32_t color, sf::CircleShape *c) {
  c->setFillColor(sf::Color(color));
  return c;
}


sf::CircleShape *madsfml__setCirclePosition(double x, double y, sf::CircleShape *c) {
  c->setPosition(x, y);
  return c;
}


sf::CircleShape *madsfml__makeCircle(double radius, int32_t points) {
  return new sf::CircleShape(radius, points);
}

#ifdef __cplusplus
}
#endif
