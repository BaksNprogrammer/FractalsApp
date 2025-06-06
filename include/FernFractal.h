#ifndef FERN_FRACTAL_H
#define FERN_FRACTAL_H

#include "FractalBase.h"

class FernFractal : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
};

#endif // FERN_FRACTAL_H
