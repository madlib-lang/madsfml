#include "./math.hpp"

#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

sf::Vector2f *madsfml__math__toSFMLFloatVector2(madsfml__math__vector2_t *vec) {
  return new sf::Vector2f(unboxDouble((double *)vec->x), unboxDouble((double *)vec->y));
}

madsfml__math__vector2_t *madsfml__math__toMadlibFloatVector2(sf::Vector2f vec) {
  madsfml__math__vector2_t *res = (madsfml__math__vector2_t *)GC_MALLOC(sizeof(madsfml__math__vector2_t));
  res->index = 0;
  res->x = boxDouble((double)vec.x);
  res->y = boxDouble((double)vec.y);
  return res;
}

sf::Vector2i *madsfml__math__toSFMLIntVector2(madsfml__math__vector2_t *vec) {
  return new sf::Vector2i((int64_t)vec->x, (int64_t)vec->y);
}

madsfml__math__vector2_t *madsfml__math__toMadlibIntVector2(sf::Vector2i vec) {
  madsfml__math__vector2_t *res = (madsfml__math__vector2_t *)GC_MALLOC(sizeof(madsfml__math__vector2_t));
  res->index = 0;
  res->x = (void *)vec.x;
  res->y = (void *)vec.y;
  return res;
}

sf::FloatRect *madsfml__math__toSFMLFloatRect(madsfml__math__rect_t *rect) {
  return new sf::FloatRect(unboxDouble((double *)rect->left), unboxDouble((double *)rect->top),
                           unboxDouble((double *)rect->width), unboxDouble((double *)rect->height));
}

madsfml__math__rect_t *madsfml__math__toMadlibFloatRect(sf::FloatRect rect) {
  madsfml__math__rect_t *res = (madsfml__math__rect_t *)GC_MALLOC(sizeof(madsfml__math__rect_t));
  res->index = 0;
  res->left = boxDouble((double)rect.left);
  res->top = boxDouble((double)rect.top);
  res->width = boxDouble((double)rect.width);
  res->height = boxDouble((double)rect.height);
  return res;
}

sf::IntRect *madsfml__math__toSFMLIntRect(madsfml__math__rect_t *rect) {
  return new sf::IntRect((int32_t)(int64_t)rect->left, (int32_t)(int64_t)rect->top, (int32_t)(int64_t)rect->width,
                         (int32_t)(int64_t)rect->height);
}

madsfml__math__rect_t *madsfml__math__toMadlibIntRect(sf::IntRect rect) {
  madsfml__math__rect_t *res = (madsfml__math__rect_t *)GC_MALLOC(sizeof(madsfml__math__rect_t));
  res->index = 0;
  res->left = (void *)rect.left;
  res->top = (void *)rect.top;
  res->width = (void *)rect.width;
  res->height = (void *)rect.height;
  return res;
}

#ifdef __cplusplus
}
#endif
