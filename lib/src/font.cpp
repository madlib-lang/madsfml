#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::Font *madsfml__font__make() { return new sf::Font(); }

bool madsfml__font__loadFromFile(char *path, sf::Font *font) {
  return font->loadFromFile(path);
}

#ifdef __cplusplus
}
#endif
