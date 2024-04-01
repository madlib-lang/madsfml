#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::BlendMode *madsfml__blendmode__make(int32_t sourceFactor, int32_t destinationFactor, int32_t colorBlendEquation) {
  return new sf::BlendMode((sf::BlendMode::Factor)sourceFactor, (sf::BlendMode::Factor)destinationFactor,
                           (sf::BlendMode::Equation)colorBlendEquation);
}

#ifdef __cplusplus
}
#endif
