#pragma once
#include <string>
#include <unordered_map>
#include "Glyph.hpp"

class Font{
    private:
        std::string filepath;
        int pixelSize;
        int ascender, descender, lineHeight;
        std::unordered_map<char32_t, Glyph> glyphs;
    public:
        void setMetrics(int asc, int desc, int lineH);
        void setSize(int size);
        void addGlyph(char32_t codepoint, const Glyph& g);
        const Glyph* getGlyph(char32_t cp) const;
        int getPixelSize() const;
};