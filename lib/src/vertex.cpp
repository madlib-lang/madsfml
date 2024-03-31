#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::Vertex *madsfml__vertex__new() { return new sf::Vertex(); }

sf::Vertex *madsfml__vertex__fromPosition(double x, double y) {
  return new sf::Vertex(sf::Vector2f(x, y));
}

sf::Vertex *madsfml__vertex__fromPositionAndTexCoords(double x, double y,
                                                      double u, double v) {
  return new sf::Vertex(sf::Vector2f(x, y), sf::Vector2f(u, v));
}

sf::Vertex *madsfml__vertex__fromPositionAndColor(double x, double y,
                                                  int32_t color) {
  return new sf::Vertex(sf::Vector2f(x, y), sf::Color(color));
}

sf::Vertex *madsfml__vertex__setPosition(double x, double y, sf::Vertex *v) {
  v->position = sf::Vector2f(x, y);
  return v;
}

sf::Vertex *madsfml__vertex__setColor(int32_t c, sf::Vertex *v) {
  v->color = sf::Color(c);
  return v;
}

sf::Vertex *madsfml__vertex__setTexCoords(double u, double v, sf::Vertex *vec) {
  vec->texCoords = sf::Vector2f(u, v);
  return vec;
}

#ifdef __cplusplus
}
#endif
