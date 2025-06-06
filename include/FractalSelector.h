#ifndef FRACTAL_SELECTOR_H
#define FRACTAL_SELECTOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "FractalBase.h"
#include "FernFractal.h"
#include "DragonCurve.h"
#include "MandelbrotSet.h"
#include "SierpinskiCarpet.h"
#include "SierpinskiTetrahedron.h"
#include "SierpinskiTriangle.h"
#include "KochSnowflake.h"
#include "JuliaSet.h"
#include <complex>

const int ITERATIONS = 12;  // Определите константу здесь

class FractalSelector {
public:
    FractalSelector();
    void run();

private:
    void drawFractal(std::shared_ptr<FractalBase> fractal);
    void handleEvents();
    void render();
    void drawControlPanel();
    void toggleDropdown();

    sf::RenderWindow window;
    std::vector<std::shared_ptr<FractalBase>> fractals;
    std::shared_ptr<FractalBase> selectedFractal;
    bool isFractalSelected;
    sf::Font font;
    sf::Text fractalLabel;
    sf::Text scaleLabel;
    sf::Text scaleValue;
    float scaleX, scaleY;
    int selectedFractalIndex;
    float animationProgress;
    bool isDropdownOpen;  // Флаг для отслеживания состояния выпадающего списка
    std::vector<sf::Text> dropdownItems;  // Элементы выпадающего списка
    bool startDrawing;  // Флаг для начала отрисовки фрактала
    std::complex<double> juliaC;  // Константа для множества Джулия
};

#endif // FRACTAL_SELECTOR_H
