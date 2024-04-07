#include <SFML/Graphics.hpp>

#include "./math.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void madsfml__rectangle__draw(sf::RectangleShape *d, sf::RenderWindow *window) { window->draw(*d); }

void madsfml__rectangle__drawWithRenderStates(sf::RectangleShape *d, sf::RenderStates *rs, sf::RenderWindow *window) {
  window->draw(*d, *rs);
}

void madsfml__rectangle__drawToTextureWithRenderStates(sf::RectangleShape *d, sf::RenderStates *rs, sf::RenderTexture *renderTexture) {
  renderTexture->draw(*d, *rs);
}

int32_t madsfml__rectangle__getFillColor(sf::RectangleShape *rectangle) {
  return rectangle->getFillColor().toInteger();
}

sf::RectangleShape *madsfml__rectangle__setFillColor(int32_t color, sf::RectangleShape *rectangle) {
  rectangle->setFillColor(sf::Color(color));
  return rectangle;
}

int32_t madsfml__rectangle__getOutlineColor(sf::RectangleShape *rectangle) {
  return rectangle->getOutlineColor().toInteger();
}

sf::RectangleShape *madsfml__rectangle__setOutlineColor(int32_t color, sf::RectangleShape *rectangle) {
  rectangle->setOutlineColor(sf::Color(color));
  return rectangle;
}

double madsfml__rectangle__getOutlineThickness(sf::RectangleShape *rectangle) {
  return rectangle->getOutlineThickness();
}

sf::RectangleShape *madsfml__rectangle__setOutlineThickness(double thickness, sf::RectangleShape *rectangle) {
  rectangle->setOutlineThickness(thickness);
  return rectangle;
}

sf::RectangleShape *madsfml__rectangle__setTexture(sf::Texture *texture, sf::RectangleShape *rectangle) {
  rectangle->setTexture(texture);
  return rectangle;
}

madsfml__math__rect_t *madsfml__rectangle__getTextureRect(sf::RectangleShape *rectangle) {
  return madsfml__math__toMadlibIntRect(rectangle->getTextureRect());
}

sf::RectangleShape *madsfml__rectangle__setTextureRect(int32_t left, int32_t top, int32_t width, int32_t height,
                                                       sf::RectangleShape *rectangle) {
  rectangle->setTextureRect(sf::IntRect(left, top, width, height));
  return rectangle;
}

sf::RectangleShape *madsfml__rectangle__setOrigin(double x, double y, sf::RectangleShape *rectangle) {
  rectangle->setOrigin(x, y);
  return rectangle;
}

madsfml__math__vector2_t *madsfml__rectangle__getPosition(sf::RectangleShape *rectangle) {
  return madsfml__math__toMadlibFloatVector2(rectangle->getPosition());
}

sf::RectangleShape *madsfml__rectangle__setPosition(double x, double y, sf::RectangleShape *rectangle) {
  rectangle->setPosition(x, y);
  return rectangle;
}

double madsfml__rectangle__getRotation(sf::RectangleShape *rectangle) { return rectangle->getRotation(); }

sf::RectangleShape *madsfml__rectangle__setRotation(double angle, sf::RectangleShape *rectangle) {
  rectangle->setRotation(angle);
  return rectangle;
}

madsfml__math__vector2_t *madsfml__rectangle__getScale(sf::RectangleShape *rectangle) {
  return madsfml__math__toMadlibFloatVector2(rectangle->getScale());
}

sf::RectangleShape *madsfml__rectangle__setScale(double x, double y, sf::RectangleShape *rectangle) {
  rectangle->setScale(x, y);
  return rectangle;
}

int32_t madsfml__rectangle__getPointCount(sf::RectangleShape *rectangle) { return rectangle->getPointCount(); }

sf::Transform *madsfml__rectangle__getTransform(sf::RectangleShape *rectangle) {
  return (sf::Transform *)&rectangle->getTransform();
}

madsfml__math__rect_t *madsfml__rectangle__getLocalBounds(sf::RectangleShape *rectangle) {
  return madsfml__math__toMadlibFloatRect(rectangle->getLocalBounds());
}

madsfml__math__rect_t *madsfml__rectangle__getGlobalBounds(sf::RectangleShape *rectangle) {
  return madsfml__math__toMadlibFloatRect(rectangle->getGlobalBounds());
}

sf::RectangleShape *madsfml__rectangle__make(double width, double height) {
  return new sf::RectangleShape(sf::Vector2f(width, height));
}

#ifdef __cplusplus
}
#endif
