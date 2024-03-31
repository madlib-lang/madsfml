#include <SFML/Graphics.hpp>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

sf::Transform *madsfml__transform__identity() { return new sf::Transform(); }

sf::Transform *madsfml__transform__make(double a00, double a01, double a02,
                                        double a10, double a11, double a12,
                                        double a20, double a21, double a22) {
  return new sf::Transform(a00, a01, a02, a10, a11, a12, a20, a21, a22);
}

sf::Transform *madsfml__transform__rotate(double angle, sf::Transform *t) {
  t->rotate(angle);
  return t;
}

sf::Transform *madsfml__transform__rotateFrom(double angle, double centerX,
                                              double centerY,
                                              sf::Transform *t) {
  t->rotate(angle, centerX, centerY);
  return t;
}

sf::Transform *madsfml__transform__scale(double scaleX, double scaleY,
                                         sf::Transform *t) {
  t->scale(scaleX, scaleY);
  return t;
}

sf::Transform *madsfml__transform__scaleFrom(double scaleX, double scaleY,
                                             double centerX, double centerY,
                                             sf::Transform *t) {
  t->scale(scaleX, scaleY, centerX, centerY);
  return t;
}

#ifdef __cplusplus
}
#endif
