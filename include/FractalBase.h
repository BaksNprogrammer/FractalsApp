#ifndef FRACTAL_BASE_H
#define FRACTAL_BASE_H

#include <SFML/Graphics.hpp>

// Объявляем структуру Transformation вне класса, чтобы она была доступна в файле реализации
struct Transformation {
    float a, b, c, d, e, f, p;
};

class FractalBase {
public:
    virtual ~FractalBase() = default;

    // Виртуальный метод для генерации фрактала
    virtual sf::VertexArray generate(int numPoints) = 0;

    // Метод для масштабирования точек
    sf::VertexArray getScaledPoints(const sf::VertexArray& points, float scaleX, float scaleY, float offsetX, float offsetY);

protected:
    // Метод для применения аффинного преобразования
    sf::Vector2f applyTransformation(const sf::Vector2f& point, const Transformation& t);
};

#endif // FRACTAL_BASE_H
