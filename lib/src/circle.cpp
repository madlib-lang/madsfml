#include "gc.h"
#include <SFML/Graphics.hpp>


#ifdef __cplusplus
extern "C" {
#endif

void madsfml__circle__draw(sf::CircleShape *d, sf::RenderWindow *window) {
  window->draw(*d);
}


sf::CircleShape *madsfml__circle__setFillColor(int32_t color, sf::CircleShape *c) {
  c->setFillColor(sf::Color(color));
  return c;
}


sf::CircleShape *madsfml__circle__setPosition(double x, double y, sf::CircleShape *c) {
  c->setPosition(x, y);
  return c;
}


sf::CircleShape *madsfml__circle__setRotation(double angle, sf::CircleShape *c) {
  c->setRotation(angle);
  return c;
}


sf::CircleShape *madsfml__circle__setScale(double x, double y, sf::CircleShape *c) {
  c->setScale(x, y);
  return c;
}


sf::CircleShape *madsfml__circle__setPointCount(int32_t points, sf::CircleShape *c) {
  c->setPointCount(points);
  return c;
}


sf::CircleShape *madsfml__circle__setRadius(double radius, sf::CircleShape *c) {
  c->setRadius(radius);
  return c;
}


sf::CircleShape *madsfml__circle__make(double radius) {
  return new sf::CircleShape(radius);
}

#ifdef __cplusplus
}
#endif
