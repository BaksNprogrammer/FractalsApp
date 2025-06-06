#ifndef SIERPINSKI_TRIANGLE_H
#define SIERPINSKI_TRIANGLE_H

#include "FractalBase.h"

class SierpinskiTriangle : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
    void draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY);

private:
    void drawTriangle(sf::RenderWindow& window, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int level);
};

#endif // SIERPINSKI_TRIANGLE_H
