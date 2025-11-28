#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "model/TextModel.hpp"

class TextRenderer{
    private:
    sf::RenderWindow& window;
    public:
        TextRenderer(sf::RenderWindow& win) : window(win) {};
        void draw(const TextModel& model);
};