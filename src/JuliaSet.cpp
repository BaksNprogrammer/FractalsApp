#include "JuliaSet.h"
#include <complex>
#include <vector>
#include <cmath>

JuliaSet::JuliaSet(int width, int height, double zoom, double moveX, double moveY, std::complex<double> c, int maxIter)
    : width(width), height(height), zoom(zoom), moveX(moveX), moveY(moveY), c(c), maxIter(maxIter) {}

sf::VertexArray JuliaSet::generate(int numPoints) {
   
    return sf::VertexArray();
}

std::vector<std::vector<int>> JuliaSet::generateFractal() {
    std::vector<std::vector<int>> img(height, std::vector<int>(width, 0));

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            std::complex<double> z((x / (double)width - 0.5) * zoom - moveX,
                                    (y / (double)height - 0.5) * zoom - moveY);
            int i = maxIter;

            while (std::abs(z) < 2.0 && i > 0) {
                z = z * z + c;
                --i;
            }

            img[y][x] = i % 8 * 32;
        }
    }

    return img;
}

void JuliaSet::draw(sf::RenderWindow& window, float scaleX, float scaleY, float offsetX, float offsetY) {
    std::vector<std::vector<int>> img = generateFractal();
    sf::Image image;
    image.create(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int colorValue = img[y][x];
            sf::Color color(colorValue, colorValue, colorValue);
            image.setPixel(x, y, color);
        }
    }

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);
    window.draw(sprite);
}
