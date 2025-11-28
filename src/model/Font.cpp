#include "model/Font.hpp"

void Font::setMetrics(int asc, int desc, int lineH){
    ascender = asc;
    descender = desc;
    lineHeight = lineH;
}

void Font::setSize(int size){
    pixelSize = size;
}

void Font::addGlyph(char32_t codepoint, const Glyph& g){
    glyphs[codepoint] = g;
}

const Glyph* Font::getGlyph(char32_t cp) const {
    auto it = glyphs.find(cp);
    if (it != glyphs.end())
        return &it->second;
    return nullptr;
}

int Font::getPixelSize() const{
    return pixelSize;
}