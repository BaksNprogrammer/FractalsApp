#include "FractalSelector.h"
#include <iostream>

FractalSelector::FractalSelector()
    : window(sf::VideoMode(1920, 1080), "Fractal Selector"), isFractalSelected(false), scaleX(100.0f), scaleY(-100.0f), selectedFractalIndex(0), animationProgress(0.0f), isDropdownOpen(true), startDrawing(false) {
    // Добавьте доступные фракталы
    fractals.push_back(std::make_shared<FernFractal>());
    fractals.push_back(std::make_shared<DragonCurve>());
    fractals.push_back(std::make_shared<MandelbrotSet>());
    fractals.push_back(std::make_shared<SierpinskiCarpet>());
    fractals.push_back(std::make_shared<SierpinskiTetrahedron>());
    fractals.push_back(std::make_shared<SierpinskiTriangle>());
    fractals.push_back(std::make_shared<KochSnowflake>());
    fractals.push_back(std::make_shared<JuliaSet>(800, 800, 1.5, 0, 0, juliaC, 300));
    // Добавьте другие фракталы здесь

    // Загрузка шрифта
    if (!font.loadFromFile("./fonts/NotoSansJP-VariableFont_wght.ttf")) {
        // Обработка ошибки загрузки шрифта
    }

    // Инициализация текстовых элементов
    fractalLabel.setFont(font);
    fractalLabel.setString("Select Fractal");
    fractalLabel.setCharacterSize(24);
    fractalLabel.setPosition(50, 50);
    fractalLabel.setFillColor(sf::Color::White);

    scaleLabel.setFont(font);
    scaleLabel.setString("Scale:");
    scaleLabel.setCharacterSize(24);
    scaleLabel.setPosition(50, 100);
    scaleLabel.setFillColor(sf::Color::White);

    scaleValue.setFont(font);
    scaleValue.setString(std::to_string(static_cast<int>(scaleX)));
    scaleValue.setCharacterSize(24);
    scaleValue.setPosition(250, 100);
    scaleValue.setFillColor(sf::Color::White);

    // Инициализация элементов выпадающего списка
    dropdownItems.push_back(sf::Text("Fern", font, 24));
    dropdownItems.push_back(sf::Text("Dragon Curve", font, 24));
    dropdownItems.push_back(sf::Text("MandelBrot", font, 24));
    dropdownItems.push_back(sf::Text("Sierpinski Carpet", font, 24));
    dropdownItems.push_back(sf::Text("Sierpinski Tetrahedron", font, 24));
    dropdownItems.push_back(sf::Text("Sierpinski Triangle", font, 24));
    dropdownItems.push_back(sf::Text("Koch Snowflake", font, 24));
    dropdownItems.push_back(sf::Text("Julia Set", font, 24));
    for (size_t i = 0; i < dropdownItems.size(); ++i) {
        dropdownItems[i].setPosition(50, 150 + i * 30);
        dropdownItems[i].setFillColor(sf::Color::White);
    }
}

void FractalSelector::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        handleEvents();

       
        if (startDrawing) {
            animationProgress = std::min(1.0f, clock.getElapsedTime().asSeconds() / 5.0f);
        }

        render();
    }
}

void FractalSelector::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (fractalLabel.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                toggleDropdown();
            }
            if (isDropdownOpen) {
                for (size_t i = 0; i < dropdownItems.size(); ++i) {
                    if (dropdownItems[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        selectedFractalIndex = i;
                        selectedFractal = fractals[selectedFractalIndex];
                        isFractalSelected = true;
                        isDropdownOpen = false;
                        startDrawing = true;  // Начинаем рисовать фрактал
                        break;
                    }
                }
            }
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                scaleX += 20.0f;
                scaleY -= 40.0f;
            } else if (event.key.code == sf::Keyboard::Down) {
                scaleX -= 20.0f;
                scaleY += 40.0f;
            }
            scaleValue.setString(std::to_string(static_cast<int>(scaleX)));
        }
    }
}

void FractalSelector::render() {
    window.clear(sf::Color(0, 0, 0));

    if (startDrawing) {
        drawFractal(selectedFractal);
    }

    drawControlPanel();
    window.display();
}

void FractalSelector::drawFractal(std::shared_ptr<FractalBase> fractal) {
    if (dynamic_cast<DragonCurve*>(fractal.get())) {
        // Отрисовка кривой дракона с анимацией
        static_cast<DragonCurve*>(fractal.get())->draw(window, animationProgress);
    } 
    else if (dynamic_cast<MandelbrotSet*>(fractal.get())) {
        // Отрисовка множества Мандельброта с масштабированием
        float offsetX = 960.0f;
        float offsetY = 540.0f;
        static_cast<MandelbrotSet*>(fractal.get())->draw(window, scaleX, scaleY, offsetX, offsetY);
    } 
    else if (dynamic_cast<SierpinskiCarpet*>(fractal.get())) {
        // Отрисовка ковра Серпинского с масштабированием
        float offsetX = 160.0f;
        float offsetY = 100.0f;
        static_cast<SierpinskiCarpet*>(fractal.get())->draw(window, scaleX, scaleY, offsetX, offsetY);
    }
    else if (dynamic_cast<SierpinskiTetrahedron*>(fractal.get())) {
        // Отрисовка тетраэдра Серпинского с масштабированием
        float offsetX = 960.0f;
        float offsetY = 540.0f;
        static_cast<SierpinskiTetrahedron*>(fractal.get())->draw(window, scaleX, scaleY, offsetX, offsetY);
    }
    else if (dynamic_cast<SierpinskiTriangle*>(fractal.get())) {
        // Отрисовка треугольника Серпинского с масштабированием
        float offsetX = 960.0f;
        float offsetY = 540.0f;
        static_cast<SierpinskiTriangle*>(fractal.get())->draw(window, scaleX, scaleY, offsetX, offsetY);
    }
    else if (dynamic_cast<KochSnowflake*>(fractal.get())) {
        // Отрисовка снежинки Коха с масштабированием
        float offsetX = 960.0f;
        float offsetY = 540.0f;
        static_cast<KochSnowflake*>(fractal.get())->draw(window, scaleX, scaleY, offsetX, offsetY);
    }
    else if (dynamic_cast<JuliaSet*>(fractal.get())) {
        // Отрисовка множества Джулия с масштабированием
        float offsetX = 960.0f;
        float offsetY = 540.0f;
        static_cast<JuliaSet*>(fractal.get())->draw(window, scaleX, scaleY, offsetX, offsetY);
    }
    else {
        sf::VertexArray points = fractal->generate(10000);
        float offsetX = 960.0f;
        float offsetY = 1040.0f;

        sf::VertexArray scaledPoints = fractal->getScaledPoints(points, scaleX, scaleY, offsetX, offsetY);
        window.draw(scaledPoints);
    }
}

void FractalSelector::drawControlPanel() {
    window.draw(fractalLabel);
    window.draw(scaleLabel);
    window.draw(scaleValue);

    if (isDropdownOpen) {
        for (const auto& item : dropdownItems) {
            window.draw(item);
        }
    }
}

void FractalSelector::toggleDropdown() {
    isDropdownOpen = !isDropdownOpen;
}
