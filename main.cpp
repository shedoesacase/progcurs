#include <SFML/Graphics.hpp>
#include "freetype/FontLoader.hpp"
#include "model/Font.hpp"
#include "model/TextModel.hpp"
#include "view/TextRenderer.hpp"
#include "controller/controller.hpp"
#include <memory>
#include <string>
#include <filesystem>

int main() {
    std::vector<std::string> fileNames;
    for(const auto& entry : std::filesystem::directory_iterator("../res")){
        fileNames.push_back(entry.path().string());
    }
    std::vector<std::shared_ptr<Font>> fonts;
    for(auto s : fileNames){
        auto font = std::make_shared<Font>();
        font->setSize(58);

        FontLoader loader;
        if (!loader.loadFont(s, *font)) {
            printf("Failed to load font\n");
            return -1;
        }
        fonts.push_back(font);
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Text Renderer");

    TextModel textModel;
    textModel.setText(U"hello world");
    textModel.setFont(fonts[0]);
    textModel.setPosition(250, 300);


    Controller controller (textModel, fonts);
    TextRenderer renderer(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            controller.handleEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        renderer.draw(textModel);

        window.display();
    }

    return 0;
}
