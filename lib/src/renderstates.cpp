#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::RenderStates *madsfml__renderstates__default() {
  return new sf::RenderStates();
}

sf::RenderStates *madsfml__renderstates__setTransform(sf::Transform *t,
                                                      sf::RenderStates *rs) {
  rs->transform = *t;
  return rs;
}

sf::RenderStates *madsfml__renderstates__setTexture(sf::Texture *t,
                                                    sf::RenderStates *rs) {
  rs->texture = t;
  return rs;
}

sf::RenderStates *madsfml__renderstates__setShader(sf::Shader *s,
                                                   sf::RenderStates *rs) {
  rs->shader = s;
  return rs;
}

#ifdef __cplusplus
}
#endif
