#include <SFML/Graphics.hpp>

#include "./math.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::View *madsfml__view__make() { return new sf::View(); }

sf::View *madsfml__view__makeWithRect(double left, double top, double width, double height) {
  return new sf::View(sf::FloatRect(left, top, width, height));
}

sf::View *madsfml__view__setSize(double width, double height, sf::View *view) {
  view->setSize(width, height);
  return view;
}

sf::View *madsfml__view__setCenter(double x, double y, sf::View *view) {
  view->setCenter(x, y);
  return view;
}

sf::View *madsfml__view__setRotation(double angle, sf::View *view) {
  view->setRotation(angle);
  return view;
}

sf::View *madsfml__view__setViewport(double left, double top, double width, double height, sf::View *view) {
  view->setViewport(sf::FloatRect(left, top, width, height));
  return view;
}

sf::View *madsfml__view__reset(double left, double top, double width, double height, sf::View *view) {
  view->reset(sf::FloatRect(left, top, width, height));
  return view;
}

madsfml__math__vector2_t *madsfml__view__getCenter(sf::View *view) {
  return madsfml__math__toMadlibFloatVector2(view->getCenter());
}

madsfml__math__vector2_t *madsfml__view__getSize(sf::View *view) {
  return madsfml__math__toMadlibFloatVector2(view->getSize());
}

double madsfml__view__getRotation(sf::View *view) { return view->getRotation(); }

madsfml__math__rect_t *madsfml__view__getViewport(sf::View *view) {
  return madsfml__math__toMadlibFloatRect(view->getViewport());
}

#ifdef __cplusplus
}
#endif