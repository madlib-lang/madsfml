#include <SFML/Graphics.hpp>
#include "gc.h"
#include "record.hpp"
#include "maybe.hpp"

#ifdef __cplusplus
extern "C" {
#endif

sf::Texture *madsfml__texture__make() {
  return new sf::Texture();
}

bool madsfml__texture__loadFromFile(char *path, sf::Texture *texture) {
  return texture->loadFromFile(path);
}

sf::Sprite *madsfml__sprite__make(sf::Texture *texture) {
  return new sf::Sprite(*texture);
}

void madsfml__sprite__draw(sf::Sprite *sprite, sf::RenderWindow *window) {
  window->draw(*sprite);
}

void madsfml__sprite__drawWithShader(sf::Sprite *sprite, sf::Shader *shader, sf::RenderWindow *window) {
  window->draw(*sprite, shader);
}

#ifdef __cplusplus
}
#endif
