#include "SierpinskiTetrahedron.h"

sf::VertexArray SierpinskiTetrahedron::generate(int numPoints) {
    // Для тетраэдра Серпинского мы не генерируем точки заранее, а рисуем напрямую в окне
    return sf::VertexArray();
}

void SierpinskiTetrahedron::draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY) {
    sf::Vector3f p1(offsetX, offsetY, 0);
    sf::Vector3f p2(offsetX + scaleX, offsetY, 0);
    sf::Vector3f p3(offsetX + scaleX / 2, offsetY + scaleY, 0);
    sf::Vector3f p4(offsetX + scaleX / 2, offsetY + scaleY / 2, scaleY);

    drawTetrahedron(window, p1, p2, p3, p4, 4);
}

void SierpinskiTetrahedron::drawTetrahedron(sf::RenderWindow& window, sf::Vector3f p1, sf::Vector3f p2, sf::Vector3f p3, sf::Vector3f p4, int level) {
    if (level == 0) {
        return;
    }

    sf::VertexArray lines(sf::Lines);
    lines.append(sf::Vertex(sf::Vector2f(p1.x, p1.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p2.x, p2.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p2.x, p2.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p3.x, p3.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p3.x, p3.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p1.x, p1.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p1.x, p1.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p4.x, p4.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p2.x, p2.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p4.x, p4.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p3.x, p3.y), sf::Color::White));
    lines.append(sf::Vertex(sf::Vector2f(p4.x, p4.y), sf::Color::White));

    window.draw(lines);

    sf::Vector3f mid1 = (p1 + p2) / 2.0f;
    sf::Vector3f mid2 = (p2 + p3) / 2.0f;
    sf::Vector3f mid3 = (p3 + p1) / 2.0f;
    sf::Vector3f mid4 = (p1 + p4) / 2.0f;
    sf::Vector3f mid5 = (p2 + p4) / 2.0f;
    sf::Vector3f mid6 = (p3 + p4) / 2.0f;

    drawTetrahedron(window, mid1, mid2, mid3, mid4, level - 1);
    drawTetrahedron(window, mid2, mid3, mid5, mid6, level - 1);
    drawTetrahedron(window, mid1, mid4, mid5, mid6, level - 1);
    drawTetrahedron(window, mid4, mid5, mid6, p4, level - 1);
}
