#pragma once
#include <string>
#include "Font.hpp"
#include <memory>
#include <cstdint>

class TextModel{
    private:
        std::u32string text;
        std::shared_ptr<Font> font;
        float x, y;
    public:
        void setText(std::u32string _text);
        void setPosition(float x, float y);
        void setFont(std::shared_ptr<Font> font_);
        std::u32string getText() const;
        std::pair<float, float> getPosition() const;
        std::shared_ptr<Font> getFont() const;
};

struct Color{
    uint8_t r, g, b, a;
};