#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::BlendMode *madsfml__blendmode__make(int32_t sourceFactor, int32_t destinationFactor, int32_t colorBlendEquation) {
  return new sf::BlendMode((sf::BlendMode::Factor)sourceFactor, (sf::BlendMode::Factor)destinationFactor,
                           (sf::BlendMode::Equation)colorBlendEquation);
}

sf::BlendMode *madsfml__blendmode__makeWithAlpha(int32_t sourceColorFactor, int32_t destinationColorFactor,
                                                 int32_t colorBlendEquation, int32_t sourceAlphaFactor,
                                                 int32_t destinationAlphaFactor, int32_t alphaBlendEquation) {
  return new sf::BlendMode((sf::BlendMode::Factor)sourceColorFactor, (sf::BlendMode::Factor)destinationColorFactor,
                           (sf::BlendMode::Equation)colorBlendEquation, (sf::BlendMode::Factor)sourceAlphaFactor,
                           (sf::BlendMode::Factor)destinationAlphaFactor, (sf::BlendMode::Equation)alphaBlendEquation);
}

#ifdef __cplusplus
}
#endif
