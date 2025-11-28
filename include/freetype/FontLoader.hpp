#pragma once
#include "freetype/FreeTypeLib.hpp"
#include "model/Font.hpp"
#include "model/Glyph.hpp"

class FontLoader{
    public:
    bool loadFont(const std::string& filepath, Font& font);
    
};