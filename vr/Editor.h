
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "game.h"
#include "Vector2.h"
#include "Tile.h"
#include <map>
#include <iostream>

namespace mine{
    class Editor:public screen{
         Editor();
        void setup(sf::Vector2u) override;
        void handleInput(sf::Event event ,gameManager* gameManager) override;
        void render(sf::RenderTarget* target) override;

        private:
    };



}