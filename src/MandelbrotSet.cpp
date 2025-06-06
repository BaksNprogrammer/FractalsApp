#include "MandelbrotSet.h"
#include <complex>

sf::VertexArray MandelbrotSet::generate(int numPoints) {
    // Для множества Мандельброта мы не генерируем точки заранее, а рисуем напрямую в окне
    return sf::VertexArray();
}

void MandelbrotSet::draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY) {
    sf::Image image;
    image.create(window.getSize().x, window.getSize().y);

    for (int y = 0; y < window.getSize().y; ++y) {
        for (int x = 0; x < window.getSize().x; ++x) {
            std::complex<double> c(((x - offsetX) / scaleX), ((y - offsetY) / scaleY));
            std::complex<double> z(0, 0);
            int n = 100;
            int max_iter = 256;

            while (std::abs(z) <= 2 && n < max_iter) {
                z = z * z + c;
                n++;
            }

            if (n == max_iter) {
                image.setPixel(x, y, sf::Color(235, 229, 228));
            } else {
                int brightness = static_cast<int>(239 * (max_iter - n) / max_iter);
                image.setPixel(x, y, sf::Color(brightness, brightness, brightness));
            }
        }
    }

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);
    window.draw(sprite);
}
