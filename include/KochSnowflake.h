#ifndef KOCH_SNOWFLAKE_H
#define KOCH_SNOWFLAKE_H

#include "FractalBase.h"

class KochSnowflake : public FractalBase {
public:
    sf::VertexArray generate(int numPoints) override;
    void draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY);

private:
    void drawSnowflake(sf::RenderWindow& window, sf::Vector2f p1, sf::Vector2f p2, int level);
};

#endif // KOCH_SNOWFLAKE_H
