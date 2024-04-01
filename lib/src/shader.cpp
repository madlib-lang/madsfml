#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::Shader *madsfml__shader__new() { return new sf::Shader(); }

bool madsfml__shader__loadFromFile(char *path, sf::Shader::Type type, sf::Shader *shader) {
  return shader->loadFromFile(path, type);
}

bool madsfml__shader__loadFromMemory(char *code, sf::Shader::Type type, sf::Shader *shader) {
  return shader->loadFromMemory(code, type);
}

sf::Shader *madsfml__shader__setCurrentTexture(char *name, sf::Shader *shader) {
  shader->setUniform(name, sf::Shader::CurrentTexture);
  return shader;
}

sf::Shader *madsfml__shader__setIntUniform(char *name, int32_t i, sf::Shader *shader) {
  shader->setUniform(name, i);
  return shader;
}

sf::Shader *madsfml__shader__setFloatUniform(char *name, double f, sf::Shader *shader) {
  shader->setUniform(name, (float)f);
  return shader;
}

sf::Shader *madsfml__shader__setBoolUniform(char *name, bool b, sf::Shader *shader) {
  shader->setUniform(name, b);
  return shader;
}

sf::Shader *madsfml__shader__setVec2Uniform(char *name, double x, double y, sf::Shader *shader) {
  shader->setUniform(name, sf::Glsl::Vec2(x, y));
  return shader;
}

sf::Shader *madsfml__shader__setVec3Uniform(char *name, double x, double y, double z, sf::Shader *shader) {
  shader->setUniform(name, sf::Glsl::Vec3(x, y, z));
  return shader;
}

sf::Shader *madsfml__shader__setVec4Uniform(char *name, double r, double g, double b, double a, sf::Shader *shader) {
  shader->setUniform(name, sf::Glsl::Vec4(r, g, b, a));
  return shader;
}

sf::Shader *madsfml__shader__setIVec2Uniform(char *name, int32_t x, int32_t y, sf::Shader *shader) {
  shader->setUniform(name, sf::Glsl::Ivec2(x, y));
  return shader;
}

sf::Shader *madsfml__shader__setIVec3Uniform(char *name, int32_t x, int32_t y, int32_t z, sf::Shader *shader) {
  shader->setUniform(name, sf::Glsl::Ivec3(x, y, z));
  return shader;
}

sf::Shader *madsfml__shader__setIVec4Uniform(char *name, int32_t r, int32_t g, int32_t b, int32_t a, sf::Shader *shader) {
  shader->setUniform(name, sf::Glsl::Ivec4(r, g, b, a));
  return shader;
}

#ifdef __cplusplus
}
#endif