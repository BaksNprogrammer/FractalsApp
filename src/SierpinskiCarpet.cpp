#include "SierpinskiCarpet.h"

sf::VertexArray SierpinskiCarpet::generate(int numPoints) {
    // Для ковра Серпинского мы не генерируем точки заранее, а рисуем напрямую в окне
    return sf::VertexArray();
}

void SierpinskiCarpet::draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY) {
    sf::Vector2f size(window.getSize().x, window.getSize().y);
    sf::Vector2f position(offsetX, offsetY);

    sf::RectangleShape rectangle(size);
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(position);

    window.draw(rectangle);

    drawCarpet(window, position, size, scaleX, scaleY, 3);
}

void SierpinskiCarpet::drawCarpet(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, float scaleX, float scaleY, int level) {
    if (level == 0) {
        return;
    }

    sf::Vector2f newSize(size.x / 3.55, size.y / 3.55);
    sf::Vector2f newPosition;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                sf::RectangleShape rectangle(newSize);
                rectangle.setFillColor(sf::Color::White);
                newPosition = position + sf::Vector2f(newSize.x * i, newSize.y * j);
                rectangle.setPosition(newPosition);
                window.draw(rectangle);
            } else {
                newPosition = position + sf::Vector2f(newSize.x * i, newSize.y * j);
                drawCarpet(window, newPosition, newSize, scaleX, scaleY, level - 1);
            }
        }
    }
}
