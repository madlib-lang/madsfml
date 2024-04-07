#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::VertexArray *madsfml__vertexarray__make() { return new sf::VertexArray(); }

sf::VertexArray *madsfml__vertexarray__makeWithPrimitiveTypeAndSize(
    int32_t primitiveType, int32_t size) {
  return new sf::VertexArray((sf::PrimitiveType)primitiveType, size);
}

sf::VertexArray *madsfml__vertexarray__set(int32_t index, sf::Vertex *v,
                                           sf::VertexArray *va) {
  (*va)[index] = *v;
  return va;
}

sf::Vertex *madsfml__vertexarray__get(int32_t index, sf::VertexArray *va) {
  return &(*va)[index];
}

void madsfml__vertexarray__draw(sf::VertexArray *va, sf::RenderWindow *window) {
  window->draw(*va);
}

void madsfml__vertexarray__drawWithRenderStates(sf::VertexArray *va,
                                                sf::RenderStates *rs,
                                                sf::RenderWindow *window) {
  window->draw(*va, *rs);
}

void madsfml__vertexarray__drawToTextureWithRenderStates(sf::VertexArray *va,
                                                sf::RenderStates *rs,
                                                sf::RenderTexture *renderTexture) {
  renderTexture->draw(*va, *rs);
}

#ifdef __cplusplus
}
#endif
