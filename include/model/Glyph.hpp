#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Glyph{
    private:
        int width, height;
        int bearingX, bearingY;
        int advance;
        std::vector<unsigned char> bitmap;
        sf::Texture texture;
    public:
        void setWidth(int w);
        void setHeight(int h);
        void setBearing(int x, int y);
        void setAdvance(int a);
        void setBitmap(const std::vector<unsigned char>& bmp);
        int getWidth() const;
        int getHeight() const;
        int getBearingX() const;
        int getBearingY() const;
        int getAdvance() const;
        const std::vector<unsigned char>& getBitmap() const;
        void setTexture(sf::Texture&& tex);
        const sf::Texture& getTexture() const;

};