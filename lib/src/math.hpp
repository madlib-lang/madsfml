#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct madsfml__math__vector2 {
  int64_t index;
  void *x;
  void *y;
} madsfml__math__vector2_t;

typedef struct madsfml__math__rect {
  int64_t index;
  void *left;
  void *top;
  void *width;
  void *height;
} madsfml__math__rect_t;

sf::Vector2f *madsfml__math__toSFMLFloatVector2(madsfml__math__vector2_t *vec);
madsfml__math__vector2_t *madsfml__math__toMadlibFloatVector2(sf::Vector2f vec);

sf::Vector2i *madsfml__math__toSFMLIntVector2(madsfml__math__vector2_t *vec);
madsfml__math__vector2_t *madsfml__math__toMadlibIntVector2(sf::Vector2i vec);

sf::FloatRect *madsfml__math__toSFMLFloatRect(madsfml__math__rect_t *rect);
madsfml__math__rect_t *madsfml__math__toMadlibFloatRect(sf::FloatRect rect);

sf::IntRect *madsfml__math__toSFMLIntRect(madsfml__math__rect_t *rect);
madsfml__math__rect_t *madsfml__math__toMadlibIntRect(sf::IntRect rect);

#ifdef __cplusplus
}
#endif
