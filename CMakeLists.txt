cmake_minimum_required(VERSION 3.16)
project(TextRendererProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    src/freetype/FontLoader.cpp
    src/freetype/FreeTypeLib.cpp
    src/model/Font.cpp
    src/model/Glyph.cpp
    src/model/TextModel.cpp
    src/view/TextRenderer.cpp
    src/controller/Controller.cpp
    main.cpp
)

set(HEADERS
    include/freetype/FontLoader.hpp
    include/freetype/FreeTypeLib.hpp
    include/model/Font.hpp
    include/model/Glyph.hpp
    include/model/TextModel.hpp
    include/view/TextRenderer.hpp
    include/controller/Controller.hpp
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

find_package(Freetype REQUIRED)

add_executable(TextRenderer ${SRC} ${HEADERS})

target_include_directories(TextRenderer PRIVATE include ${FREETYPE_INCLUDE_DIRS})

target_link_libraries(TextRenderer PRIVATE sfml-graphics sfml-window sfml-system freetype)
