#include "model/Glyph.hpp"

void Glyph::setWidth(int w){
    width = w;
}
void Glyph::setHeight(int h){
    height = h;
}
void Glyph::setBearing(int x, int y){
    bearingX = x;
    bearingY = y;
}

void Glyph::setAdvance(int a){
    advance = a;
}

void Glyph::setBitmap(const std::vector<unsigned char>& bmp){
    bitmap = bmp;
}

int Glyph::getWidth() const{
    return width;
}
int Glyph::getHeight() const{
    return height;
}
int Glyph::getBearingX() const{
    return bearingX;
}
int Glyph::getBearingY() const{
    return bearingY;
}
int Glyph::getAdvance() const{
    return advance;
}
const std::vector<unsigned char>& Glyph::getBitmap() const{
    return bitmap;
}

void Glyph::setTexture(sf::Texture&& tex){
    texture = std::move(tex);
}
const sf::Texture& Glyph::getTexture() const{
    return texture;
}