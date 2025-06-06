#ifndef SIERPINSKI_TETRAHEDRON_H
#define SIERPINSKI_TETRAHEDRON_H

#include "FractalBase.h"

class SierpinskiTetrahedron : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
    void draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY);

private:
    void drawTetrahedron(sf::RenderWindow& window, sf::Vector3f p1, sf::Vector3f p2, sf::Vector3f p3, sf::Vector3f p4, int level);
};

#endif // SIERPINSKI_TETRAHEDRON_H
