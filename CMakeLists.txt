cmake_minimum_required(VERSION 3.10)
project(FractalsApp)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 14)


# Указываем, где искать заголовочные файлы
include_directories(${PROJECT_SOURCE_DIR}/include)

#Путь до локального SFML
if(LINUX)
    include_directories(${PROJECT_SOURCE_DIR}/lib/SFML_linux/include)
endif()
# Добавляем исполняемый файл
#add_executable(FractalsApp src/FractalsApp.cpp)

# Добавляем остальные исходные файлы
set(SOURCES
    src/FractalsApp.cpp
    src/FernFractal.cpp
    src/FractalBase.cpp
    src/FractalSelector.cpp
    src/DragonCurve.cpp
    src/MandelbrotSet.cpp
    src/SierpinskiCarpet.cpp
    src/SierpinskiTetrahedron.cpp
    src/SierpinskiTriangle.cpp
    src/KochSnowflake.cpp
    src/JuliaSet.cpp
)

add_executable(FractalsApp ${SOURCES})

#Пути до динамически бибилиотек
if(LINUX)
    set(SFML_DIR ${PROJECT_SOURCE_DIR}/lib/SFML_linux/lib/cmake/SFML)
    set(CMAKE_INSTALL_RPATH ${PROJECT_SOURCE_DIR}/lib/SFML_linux/lib)
endif()

# Находим и подключаем SFML
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(FractalsApp sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Добавляем поддиректорию для тестов
#add_subdirectory(tests)


