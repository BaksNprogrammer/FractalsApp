#include "SierpinskiTriangle.h"

sf::VertexArray SierpinskiTriangle::generate(int numPoints) {
    // Для треугольника Серпинского мы не генерируем точки заранее, а рисуем напрямую в окне
    return sf::VertexArray();
}

void SierpinskiTriangle::draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY) {
    sf::Vector2f p1(offsetX, offsetY);
    sf::Vector2f p2(offsetX + scaleX, offsetY);
    sf::Vector2f p3(offsetX + scaleX / 5, offsetY + scaleY);

    drawTriangle(window, p1, p2, p3, 11);
}

void SierpinskiTriangle::drawTriangle(sf::RenderWindow& window, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int level) {
    if (level == 0) {
        sf::VertexArray triangle(sf::Triangles, 4);
        triangle[0] = sf::Vertex(p1, sf::Color::White);
        triangle[1] = sf::Vertex(p2, sf::Color::White);
        triangle[2] = sf::Vertex(p3, sf::Color::White);
        window.draw(triangle);
    } else {
        sf::Vector2f mid1 = (p1 + p2) / 2.0f;
        sf::Vector2f mid2 = (p2 + p3) / 2.0f;
        sf::Vector2f mid3 = (p3 + p1) / 2.0f;

        drawTriangle(window, p1, mid1, mid3, level - 1);
        drawTriangle(window, mid1, p2, mid2, level - 1);
        drawTriangle(window, mid3, mid2, p3, level - 1);
    }
}
