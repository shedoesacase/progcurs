#include "view/TextRenderer.hpp"

void TextRenderer::draw(const TextModel& model){
    std::u32string text = model.getText();
    auto font = model.getFont();
    float x = model.getPosition().first;
    float y = model.getPosition().second;
    for(auto c : text){
        const Glyph* gl = font->getGlyph(c);
        if(!gl){
            continue;
        }
        const sf::Texture& tex = gl->getTexture();    
        sf::Sprite sprite;
        sprite.setTexture(tex);

        float xpos = x + gl->getBearingX();
        float ypos = y - gl->getBearingY();

        sprite.setPosition(xpos, ypos);
        window.draw(sprite);

        x += gl->getAdvance();
    }


}