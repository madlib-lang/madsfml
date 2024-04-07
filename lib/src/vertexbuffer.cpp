#include <SFML/Graphics.hpp>

#include "array.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::VertexBuffer *madsfml__vertexbuffer__make() { return new sf::VertexBuffer(); }

sf::VertexBuffer *madsfml__vertexbuffer__makeWithPrimitiveType(int32_t primitiveType) {
  return new sf::VertexBuffer((sf::PrimitiveType)primitiveType);
}

bool madsfml__vertexbuffer__create(int32_t vertexCount, sf::VertexBuffer *vb) { return vb->create(vertexCount); }

sf::VertexBuffer *madsfml__vertexbuffer__update(madlib__array__Array_t *vertices, sf::VertexBuffer *vb) {
  sf::Vertex *_vertices = new sf::Vertex[vertices->length];

  for (int i = 0; i < vertices->length; i++) {
    _vertices[i] = *(((sf::Vertex **)vertices->items)[i]);
  }

  vb->update(_vertices, vertices->length, 0);
  return vb;
}

sf::VertexBuffer *madsfml__vertexbuffer__updateAt(madlib__array__Array_t *vertices, int32_t offset,
                                                  sf::VertexBuffer *vb) {
  sf::Vertex *_vertices = new sf::Vertex[vertices->length];

  for (int i = 0; i < vertices->length; i++) {
    _vertices[i] = *(((sf::Vertex **)vertices->items)[i]);
  }
  vb->update(_vertices, vertices->length, offset);
  return vb;
}

sf::VertexBuffer *madsfml__vertexbuffer__setPrimitiveType(int32_t primitiveType, sf::VertexBuffer *vb) {
  vb->setPrimitiveType((sf::PrimitiveType)primitiveType);
  return vb;
}

void madsfml__vertexbuffer__draw(sf::VertexBuffer *vb, sf::RenderWindow *window) { window->draw(*vb); }

void madsfml__vertexbuffer__drawWithRenderStates(sf::VertexBuffer *vb, sf::RenderStates *rs, sf::RenderWindow *window) {
  window->draw(*vb, *rs);
}

void madsfml__vertexbuffer__drawToTextureWithRenderStates(sf::VertexBuffer *vb, sf::RenderStates *rs,
                                                          sf::RenderTexture *renderTexture) {
  renderTexture->draw(*vb, *rs);
}

#ifdef __cplusplus
}
#endif
