#include <SFML/Graphics.hpp>

#include "./math.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void madsfml__circle__draw(sf::CircleShape *d, sf::RenderWindow *window) { window->draw(*d); }

void madsfml__circle__drawWithRenderStates(sf::CircleShape *d, sf::RenderStates *rs, sf::RenderWindow *window) {
  window->draw(*d, *rs);
}

int32_t madsfml__circle__getFillColor(sf::CircleShape *circle) { return circle->getFillColor().toInteger(); }

sf::CircleShape *madsfml__circle__setFillColor(int32_t color, sf::CircleShape *c) {
  c->setFillColor(sf::Color(color));
  return c;
}

int32_t madsfml__circle__getOutlineColor(sf::CircleShape *circle) { return circle->getOutlineColor().toInteger(); }

sf::CircleShape *madsfml__circle__setOutlineColor(int32_t color, sf::CircleShape *c) {
  c->setOutlineColor(sf::Color(color));
  return c;
}

double madsfml__circle__getOutlineThickness(sf::CircleShape *circle) { return circle->getOutlineThickness(); }

sf::CircleShape *madsfml__circle__setOutlineThickness(double thickness, sf::CircleShape *c) {
  c->setOutlineThickness(thickness);
  return c;
}

sf::CircleShape *madsfml__circle__setTexture(sf::Texture *texture, sf::CircleShape *c) {
  c->setTexture(texture);
  return c;
}

madsfml__math__rect_t *madsfml__circle__getTextureRect(sf::CircleShape *circle) {
  return madsfml__math__toMadlibIntRect(circle->getTextureRect());
}

sf::CircleShape *madsfml__circle__setTextureRect(int32_t left, int32_t top, int32_t width, int32_t height,
                                                 sf::CircleShape *circle) {
  circle->setTextureRect(sf::IntRect(left, top, width, height));
  return circle;
}

sf::CircleShape *madsfml__circle__setOrigin(double x, double y, sf::CircleShape *c) {
  c->setOrigin(x, y);
  return c;
}

madsfml__math__vector2_t *madsfml__circle__getPosition(sf::CircleShape *circle) {
  return madsfml__math__toMadlibFloatVector2(circle->getPosition());
}

sf::CircleShape *madsfml__circle__setPosition(double x, double y, sf::CircleShape *c) {
  c->setPosition(x, y);
  return c;
}

double madsfml__circle__getRotation(sf::CircleShape *circle) {
  return circle->getRotation();
}

sf::CircleShape *madsfml__circle__setRotation(double angle, sf::CircleShape *c) {
  c->setRotation(angle);
  return c;
}

madsfml__math__vector2_t *madsfml__circle__getScale(sf::CircleShape *circle) {
  return madsfml__math__toMadlibFloatVector2(circle->getScale());
}

sf::CircleShape *madsfml__circle__setScale(double x, double y, sf::CircleShape *c) {
  c->setScale(x, y);
  return c;
}

int32_t madsfml__circle__getPointCount(sf::CircleShape *circle) { return circle->getPointCount(); }

sf::CircleShape *madsfml__circle__setPointCount(int32_t points, sf::CircleShape *c) {
  c->setPointCount(points);
  return c;
}

double madsfml__circle__getRadius(double radius, sf::CircleShape *c) {
  c->getRadius();
}

sf::CircleShape *madsfml__circle__setRadius(double radius, sf::CircleShape *c) {
  c->setRadius(radius);
  return c;
}

sf::Transform *madsfml__circle__getTransform(sf::CircleShape *circle) {
  return (sf::Transform *)&circle->getTransform();
}

madsfml__math__rect_t *madsfml__circle__getLocalBounds(sf::CircleShape *circle) {
  return madsfml__math__toMadlibFloatRect(circle->getLocalBounds());
}

madsfml__math__rect_t *madsfml__circle__getGlobalBounds(sf::CircleShape *circle) {
  return madsfml__math__toMadlibFloatRect(circle->getGlobalBounds());
}

sf::CircleShape *madsfml__circle__make(double radius) { return new sf::CircleShape(radius, 30); }

#ifdef __cplusplus
}
#endif
