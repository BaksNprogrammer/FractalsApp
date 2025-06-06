#include "DragonCurve.h"
#include <cmath>

const int MAX_ITERATIONS = 20; //12

sf::VertexArray DragonCurve::generate(int numPoints) {
    // Для кривой дракона мы не генерируем точки заранее, а рисуем напрямую в окне
    return sf::VertexArray();
}

void DragonCurve::drawDragonCurve(sf::VertexArray& points, sf::Vector2f start, sf::Vector2f end, int iterations, bool flip) {
    if (iterations == 0) {
        points.append(sf::Vertex(start, sf::Color::White));
        points.append(sf::Vertex(end, sf::Color::White));
    } else {
        sf::Vector2f delta = end - start;
        sf::Vector2f perp;

        if (flip) {
            perp = sf::Vector2f(-delta.y, delta.x);
        } else {
            perp = sf::Vector2f(delta.y, -delta.x);
        }

        sf::Vector2f mid = (start + end) / 2.0f;
        sf::Vector2f point = mid + perp * 0.48f;

        drawDragonCurve(points, start, point, iterations - 1, !flip);
        drawDragonCurve(points, point, end, iterations - 1, flip);
    }
}

void DragonCurve::draw(sf::RenderWindow& window, float animationProgress) {
    sf::VertexArray points(sf::Lines);
    sf::Vector2f start(540, 840);
    sf::Vector2f end(1260, 540);

    // Вычислите текущее количество итераций на основе прогресса анимации
    int currentIterations = static_cast<int>(animationProgress * MAX_ITERATIONS);

    drawDragonCurve(points, start, end, currentIterations, false);

    window.draw(points);
}
