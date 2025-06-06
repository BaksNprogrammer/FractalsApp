#include "FernFractal.h"
#include <cstdlib>
#include <ctime>

sf::VertexArray FernFractal::generate(int numPoints) {
    srand(static_cast<unsigned>(time(0)));

    std::vector<Transformation> transformations = {
        {0.0, 0.0, 0.0, 0.16, 0.0, 0.0, 0.01},
        {0.85, 0.04, -0.04, 0.85, 0.0, 1.6, 0.85},
        {0.2, -0.26, 0.23, 0.22, 0.0, 1.6, 0.07},
        {-0.15, 0.28, 0.26, 0.24, 0.0, 0.44, 0.07}
    };

    sf::VertexArray points(sf::Points);
    sf::Vector2f currentPoint(0, 0);

    for (int i = 0; i < numPoints; ++i) {
        double r = static_cast<double>(rand()) / RAND_MAX;
        double cumulativeProbability = 0.0;
        int transformationIndex = 0;

        for (size_t j = 0; j < transformations.size(); ++j) {
            cumulativeProbability += transformations[j].p;
            if (r <= cumulativeProbability) {
                transformationIndex = j;
                break;
            }
        }

        currentPoint = applyTransformation(currentPoint, transformations[transformationIndex]);
        points.append(sf::Vertex(currentPoint, sf::Color::Green));
    }

    return points;
}
