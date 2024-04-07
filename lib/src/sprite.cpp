#include <SFML/Graphics.hpp>

#include "./math.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::Sprite *madsfml__sprite__make(sf::Texture *texture) { return new sf::Sprite(*texture); }

sf::Sprite *madsfml__sprite__setTexture(sf::Texture *texture, sf::Sprite *sprite) {
  sprite->setTexture(*texture);
  return sprite;
}

madsfml__math__rect_t *madsfml__sprite__getTextureRect(sf::Sprite *sprite) {
  return madsfml__math__toMadlibIntRect(sprite->getTextureRect());
}

sf::Sprite *madsfml__sprite__setTextureRect(int32_t left, int32_t top, int32_t width, int32_t height,
                                            sf::Sprite *sprite) {
  sprite->setTextureRect(sf::IntRect(left, top, width, height));
  return sprite;
}

int32_t madsfml__sprite__getColor(sf::Sprite *sprite) { return sprite->getColor().toInteger(); }

sf::Sprite *madsfml__sprite__setColor(int32_t color, sf::Sprite *sprite) {
  sprite->setColor(sf::Color(color));
  return sprite;
}

madsfml__math__vector2_t *madsfml__sprite__getOrigin(sf::Sprite *sprite) {
  return madsfml__math__toMadlibFloatVector2(sprite->getOrigin());
}

sf::Sprite *madsfml__sprite__setOrigin(double x, double y, sf::Sprite *s) {
  s->setOrigin(x, y);
  return s;
}

madsfml__math__vector2_t *madsfml__sprite__getPosition(sf::Sprite *sprite) {
  return madsfml__math__toMadlibFloatVector2(sprite->getPosition());
}

sf::Sprite *madsfml__sprite__setPosition(double x, double y, sf::Sprite *s) {
  s->setPosition(x, y);
  return s;
}

double madsfml__sprite__getRotation(sf::Sprite *sprite) { return sprite->getRotation(); }

sf::Sprite *madsfml__sprite__setRotation(double angle, sf::Sprite *s) {
  s->setRotation(angle);
  return s;
}

madsfml__math__vector2_t *madsfml__sprite__getScale(sf::Sprite *sprite) {
  return madsfml__math__toMadlibFloatVector2(sprite->getScale());
}

sf::Sprite *madsfml__sprite__setScale(double x, double y, sf::Sprite *s) {
  s->setScale(x, y);
  return s;
}

sf::Transform *madsfml__sprite__getTransform(sf::Sprite *s) { return (sf::Transform *)&s->getTransform(); }

void madsfml__sprite__draw(sf::Sprite *sprite, sf::RenderWindow *window) { window->draw(*sprite); }

void madsfml__sprite__drawWithRenderStates(sf::Sprite *sprite, sf::RenderStates *rs, sf::RenderWindow *window) {
  window->draw(*sprite, *rs);
}

void madsfml__sprite__drawToTextureWithRenderStates(sf::Sprite *sprite, sf::RenderStates *rs, sf::RenderTexture *renderTexture) {
  renderTexture->draw(*sprite, *rs);
}

void madsfml__sprite__drawWithShader(sf::Sprite *sprite, sf::Shader *shader, sf::RenderWindow *window) {
  window->draw(*sprite, shader);
}

madsfml__math__rect_t *madsfml__sprite__getLocalBounds(sf::Sprite *sprite) {
  return madsfml__math__toMadlibFloatRect(sprite->getLocalBounds());
}

madsfml__math__rect_t *madsfml__sprite__getGlobalBounds(sf::Sprite *sprite) {
  return madsfml__math__toMadlibFloatRect(sprite->getGlobalBounds());
}

#ifdef __cplusplus
}
#endif
