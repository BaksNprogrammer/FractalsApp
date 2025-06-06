#ifndef SIERPINSKI_CARPET_H
#define SIERPINSKI_CARPET_H

#include "FractalBase.h"

class SierpinskiCarpet : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
    void draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY);

private:
    void drawCarpet(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, float scaleX, float scaleY, int level);
};

#endif // SIERPINSKI_CARPET_H
