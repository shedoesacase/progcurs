#include "model/TextModel.hpp"

void TextModel::setText(std::u32string _text){
    text = _text;
}
void TextModel::setPosition(float x_, float y_){
    x = x_;
    y = y_;
}
void TextModel::setFont(std::shared_ptr<Font> font_){
    font = font_;
}
std::u32string TextModel::getText() const{
    return text;
}
std::pair<float, float> TextModel::getPosition() const{
    return {x, y};
}

std::shared_ptr<Font> TextModel::getFont() const{
    return font;
}