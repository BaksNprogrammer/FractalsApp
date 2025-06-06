#ifndef JULIA_SET_H
#define JULIA_SET_H

#include "FractalBase.h"
#include <complex>
#include <vector>

class JuliaSet : public FractalBase {
public:
    JuliaSet(int width, int height, double zoom, double moveX, double moveY, std::complex<double> c, int maxIter);
    sf::VertexArray generate(int numPoints) override;
    void draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY);

private:
    int width;
    int height;
    double zoom;
    double moveX;
    double moveY;
    std::complex<double> c;
    int maxIter;
    std::vector<std::vector<int>> generateFractal();
};

#endif // JULIA_SET_H
