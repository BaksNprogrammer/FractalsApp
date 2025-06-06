#ifndef DRAGON_CURVE_H
#define DRAGON_CURVE_H

#include "FractalBase.h"

class DragonCurve : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
    void drawDragonCurve(sf::VertexArray& points, sf::Vector2f start, sf::Vector2f end, int iterations, bool flip);
    void draw(sf::RenderWindow& window, float animationProgress);  // Обновите объявление метода
};

#endif // DRAGON_CURVE_H
