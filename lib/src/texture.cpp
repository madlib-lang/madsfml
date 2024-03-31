#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::Texture *madsfml__texture__make() { return new sf::Texture(); }

bool madsfml__texture__loadFromFile(char *path, sf::Texture *texture) {
  return texture->loadFromFile(path);
}

#ifdef __cplusplus
}
#endif
