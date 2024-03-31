#include <SFML/Graphics.hpp>

#include "gc.h"
#include "./math.hpp"

#ifdef __cplusplus
extern "C" {
#endif

sf::Text *madsfml__text__make() {
  return new sf::Text();
}

sf::Text *madsfml__text__setFont(sf::Font *font, sf::Text *text) {
  text->setFont(*font);
  return text;
}

sf::Text *madsfml__text__setString(char *string, sf::Text *text) {
  auto str = sf::String::fromUtf8(string, string + strlen(string));
  text->setString(str);
  return text;
}

sf::Text *madsfml__text__setFillColor(int32_t c, sf::Text *text) {
  text->setFillColor(sf::Color(c));
  return text;
}

sf::Text *madsfml__text__setOutlineColor(int32_t c, sf::Text *text) {
  text->setOutlineColor(sf::Color(c));
  return text;
}

sf::Text *madsfml__text__setOutlineThickness(double thickness, sf::Text *text) {
  text->setOutlineThickness(thickness);
  return text;
}

sf::Text *madsfml__text__setCharacterSize(int32_t size, sf::Text *text) {
  text->setCharacterSize(size);
  return text;
}

sf::Text *madsfml__text__setLetterSpacing(double spacing, sf::Text *text) {
  text->setLetterSpacing(spacing);
  return text;
}

sf::Text *madsfml__text__setLineSpacing(double spacing, sf::Text *text) {
  text->setLineSpacing(spacing);
  return text;
}

sf::Text *madsfml__text__setStyles(int32_t styles, sf::Text *text) {
  text->setStyle(styles);
  return text;
}

void madsfml__text__draw(sf::Text *text, sf::RenderWindow *window) {
  window->draw(*text);
}


madsfml__math__vector2_t *madsfml__text__getOrigin(sf::Text *text) {
  return madsfml__math__toMadlibFloatVector2(text->getOrigin());
}

sf::Text *madsfml__text__setOrigin(double x, double y, sf::Text *s) {
  s->setOrigin(x, y);
  return s;
}

madsfml__math__vector2_t *madsfml__text__getPosition(sf::Text *text) {
  return madsfml__math__toMadlibFloatVector2(text->getPosition());
}

sf::Text *madsfml__text__setPosition(double x, double y, sf::Text *s) {
  s->setPosition(x, y);
  return s;
}

double madsfml__text__getRotation(sf::Text *text) {
  return text->getRotation();
}

sf::Text *madsfml__text__setRotation(double angle, sf::Text *s) {
  s->setRotation(angle);
  return s;
}

madsfml__math__vector2_t *madsfml__text__getScale(sf::Text *text) {
  return madsfml__math__toMadlibFloatVector2(text->getScale());
}

sf::Text *madsfml__text__setScale(double x, double y, sf::Text *s) {
  s->setScale(x, y);
  return s;
}

madsfml__math__rect_t *madsfml__text__getLocalBounds(sf::Text *text) {
  return madsfml__math__toMadlibFloatRect(text->getLocalBounds());
}

madsfml__math__rect_t *madsfml__text__getGlobalBounds(sf::Text *text) {
  return madsfml__math__toMadlibFloatRect(text->getGlobalBounds());
}

#ifdef __cplusplus
}
#endif
