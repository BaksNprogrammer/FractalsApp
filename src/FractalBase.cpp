#include "FractalBase.h"

sf::VertexArray FractalBase::getScaledPoints(const sf::VertexArray& points, float scaleX, float scaleY, float offsetX, float offsetY) {
    sf::VertexArray scaledPoints(sf::Points);
    for (size_t i = 0; i < points.getVertexCount(); ++i) {
        sf::Vector2f scaledPos(points[i].position.x * scaleX + offsetX, points[i].position.y * scaleY + offsetY);
        scaledPoints.append(sf::Vertex(scaledPos, points[i].color));
    }
    return scaledPoints;
}

sf::Vector2f FractalBase::applyTransformation(const sf::Vector2f& point, const Transformation& t) {
    return sf::Vector2f(
        t.a * point.x + t.b * point.y + t.e,
        t.c * point.x + t.d * point.y + t.f
    );
}
