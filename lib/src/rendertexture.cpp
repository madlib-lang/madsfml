
#include <SFML/Graphics.hpp>

#include "./math.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::RenderTexture *madsfml__renderTexture__make() {
  // Create the main renderTexture
  return new sf::RenderTexture();
}

bool madsfml__renderTexture__create(int32_t w, int32_t h, sf::RenderTexture *renderTexture) {
  return renderTexture->create(w, h);
}

bool madsfml__renderTexture__createWithAntialiasing(int32_t w, int32_t h, int32_t antialiasing,
                                                    sf::RenderTexture *renderTexture) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = antialiasing;
  settings.sRgbCapable = true;
  return renderTexture->create(w, h, settings);
}

void madsfml__renderTexture__display(sf::RenderTexture *renderTexture) { renderTexture->display(); }

sf::View *madsfml__renderTexture__getView(sf::RenderTexture *renderTexture) {
  return (sf::View *)&renderTexture->getView();
}

sf::RenderTexture *madsfml__renderTexture__setView(sf::View *view, sf::RenderTexture *renderTexture) {
  renderTexture->setView(*view);
  return renderTexture;
}

void madsfml__renderTexture__clear(int32_t color, sf::RenderTexture *renderTexture) {
  renderTexture->clear(sf::Color(color));
}

sf::View *madsfml__renderTexture__getDefaultView(sf::RenderTexture *renderTexture) {
  return (sf::View *)&renderTexture->getDefaultView();
}

madsfml__math__vector2_t *madsfml__renderTexture__mapPixelToCoords(int32_t x, int32_t y, sf::View *view,
                                                                   sf::RenderTexture *renderTexture) {
  return madsfml__math__toMadlibFloatVector2(renderTexture->mapPixelToCoords(sf::Vector2i(x, y), *view));
}

madsfml__math__vector2_t *madsfml__renderTexture__mapCoordsToPixel(double x, double y, sf::View *view,
                                                                   sf::RenderTexture *renderTexture) {
  return madsfml__math__toMadlibIntVector2(renderTexture->mapCoordsToPixel(sf::Vector2f(x, y), *view));
}

sf::Texture *madsfml__renderTexture__getTexture(sf::RenderTexture *renderTexture) {
  sf::Texture *texture = (sf::Texture *)GC_MALLOC(sizeof(sf::Texture));
  *texture = renderTexture->getTexture();
  return texture;
}

#ifdef __cplusplus
}
#endif
