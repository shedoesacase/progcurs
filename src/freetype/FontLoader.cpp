#include "freetype/FontLoader.hpp"

bool FontLoader::loadFont(const std::string& filepath, Font& font){
    FT_Face face;
    FT_Library library = FreeTypeLib::getinstance().getLibrary();
    if (FT_New_Face(library, filepath.c_str(), 0, &face)) {
    return false;
    }
    FT_Set_Pixel_Sizes(face, 0, font.getPixelSize());
    font.setMetrics(face->size->metrics.ascender/64, face->size->metrics.descender/64, face->size->metrics.height/64);
    
    for(int codepoint = 32; codepoint <= 126; codepoint++){
        if(FT_Load_Char(face, codepoint, FT_LOAD_RENDER)){
            continue;
        }
        Glyph gl;
        gl.setAdvance(face->glyph->advance.x/64);
        gl.setBearing(face->glyph->metrics.horiBearingX/64, face->glyph->metrics.horiBearingY/64);
        gl.setBitmap(std::vector<unsigned char>(face->glyph->bitmap.buffer,face->glyph->bitmap.buffer + face->glyph->bitmap.width * face->glyph->bitmap.rows));
        gl.setHeight(face->glyph->bitmap.rows);
        gl.setWidth(face->glyph->bitmap.width);
        std::vector<sf::Uint8> pixels(face->glyph->bitmap.width * face->glyph->bitmap.rows * 4);
        for(int y = 0; y < face->glyph->bitmap.rows; ++y){
            for(int x = 0; x < face->glyph->bitmap.width; ++x){
            unsigned char value = face->glyph->bitmap.buffer[y * face->glyph->bitmap.pitch + x];
            int index = 4 * (y * face->glyph->bitmap.width + x);
            pixels[index + 0] = 255;
            pixels[index + 1] = 255;
            pixels[index + 2] = 255;
            pixels[index + 3] = value;
        }
    }

    sf::Texture tex;
    tex.create(face->glyph->bitmap.width, face->glyph->bitmap.rows);
    tex.update(pixels.data());
    gl.setTexture(std::move(tex));

    font.addGlyph(codepoint, gl);
    }
    FT_Done_Face(face);
    return true;
}