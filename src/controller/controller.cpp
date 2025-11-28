#include "controller/controller.hpp"

void Controller::handleEvent(const sf::Event& event){
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Right){
        switchFontNext();
        }
    }
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Left){
        switchFontPrev();
        }
    }
}

void Controller::switchFontNext(){
    curFontIndex = (curFontIndex + 1) % fonts.size();
    model.setFont(fonts[curFontIndex]);
}
void Controller::switchFontPrev(){
    curFontIndex = (curFontIndex - 1 + fonts.size()) % fonts.size();
    model.setFont(fonts[curFontIndex]);
}