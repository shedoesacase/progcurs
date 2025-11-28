#pragma once
#include "model/TextModel.hpp"
#include <vector>
#include <SFML/Window.hpp>

class Controller{
    private:
        TextModel& model;
        std::vector<std::shared_ptr<Font>> fonts;
        int curFontIndex = 0;

    public:
        Controller(TextModel& mod, std::vector<std::shared_ptr<Font>> fts) : model(mod), fonts(fts){};
        void handleEvent(const sf::Event& event);
        void switchFontNext();
        void switchFontPrev();
};