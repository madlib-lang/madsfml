#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::RenderWindow *madsfml__window__create(int32_t w, int32_t h, char *name) {
  return new sf::RenderWindow(sf::VideoMode(w, h), std::string(name));
}

sf::RenderWindow *madsfml__window__createWithSettings(
    int32_t w, int32_t h, char *name, int32_t antialiasingLevel) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = antialiasingLevel;
  return new sf::RenderWindow(sf::VideoMode(w, h), std::string(name),
                              sf::Style::Default, settings);
}

void madsfml__window__close(sf::RenderWindow *window) { window->close(); }

void madsfml__window__display(sf::RenderWindow *window) { window->display(); }

sf::RenderWindow *madsfml__window__setFrameRateLimit(int32_t limit, sf::RenderWindow *window) {
  window->setFramerateLimit(limit);
  return window;
}

sf::RenderWindow *madsfml__window__setView(sf::View *view,
                                           sf::RenderWindow *window) {
  window->setView(*view);
  return window;
}

void madsfml__window__clear(int32_t color, sf::RenderWindow *window) {
  window->clear(sf::Color(color));
}

sf::View *madsfml__window__getDefaultView(sf::RenderWindow *window) {
  return (sf::View *)&window->getDefaultView();
}

#ifdef __cplusplus
}
#endif
