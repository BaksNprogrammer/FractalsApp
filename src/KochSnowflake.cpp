#include "KochSnowflake.h"
#include <cmath>  

sf::VertexArray KochSnowflake::generate(int numPoints) {
    // Для снежинки Коха мы не генерируем точки заранее, а рисуем напрямую в окне
    return sf::VertexArray();
}

void KochSnowflake::draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY) {
    sf::Vector2f center(offsetX, offsetY);
    sf::Vector2f p1 = center + sf::Vector2f(0, -scaleY);
    sf::Vector2f p2 = center + sf::Vector2f(scaleX, -scaleY);
    sf::Vector2f p3 = center + sf::Vector2f(scaleX / 2, scaleY);

    drawSnowflake(window, p1, p2, 4);
    drawSnowflake(window, p2, p3, 4);
    drawSnowflake(window, p3, p1, 4);
}

void KochSnowflake::drawSnowflake(sf::RenderWindow& window, sf::Vector2f p1, sf::Vector2f p2, int level) {
    if (level == 0) {
        sf::VertexArray line(sf::Lines, 2);
        line[0] = sf::Vertex(p1, sf::Color::White);
        line[1] = sf::Vertex(p2, sf::Color::White);
        window.draw(line);
    } else {
        sf::Vector2f delta = p2 - p1;
        sf::Vector2f p3 = p1 + delta / 3.0f;
        sf::Vector2f p5 = p1 + delta * 2.0f / 3.0f;

        sf::Vector2f p4;
        p4.x = p3.x + (p5.x - p3.x) * cos(M_PI / 3.0) - (p5.y - p3.y) * sin(M_PI / 3.0);
        p4.y = p3.y + (p5.x - p3.x) * sin(M_PI / 3.0) + (p5.y - p3.y) * cos(M_PI / 3.0);

        drawSnowflake(window, p1, p3, level - 1);
        drawSnowflake(window, p3, p4, level - 1);
        drawSnowflake(window, p4, p5, level - 1);
        drawSnowflake(window, p5, p2, level - 1);
    }
}
