#ifndef MANDELBROT_SET_H
#define MANDELBROT_SET_H

#include "FractalBase.h"

class MandelbrotSet : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
    void draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY);
};

#endif // MANDELBROT_SET_H
