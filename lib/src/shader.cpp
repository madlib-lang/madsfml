#include "gc.h"
#include <SFML/Graphics.hpp>

#ifdef __cplusplus
extern "C" {
#endif


sf::Shader *madsfml__shader__new() {
  return new sf::Shader();
}


bool madsfml__shader__loadFromFile(char *path, sf::Shader::Type type, sf::Shader *shader) {
  return shader->loadFromFile(path, type);
}

bool madsfml__shader__loadFromMemory(char *code, sf::Shader::Type type,  sf::Shader *shader) {
  return shader->loadFromMemory(code, type);
}

void setCurrentTexture(sf::Shader *shader) {
  shader->setUniform("texture", sf::Shader::CurrentTexture);
}


#ifdef __cplusplus
}
#endif