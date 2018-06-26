
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "game.h"
#include <iostream>

namespace mine  {
   class titleScreen:public screen{
       public:
        explicit titleScreen();
        void setup(sf::Vector2u) override;
        void handleInput(sf::Event event ,gameManager* gameManager) override;
        void render(sf::RenderTarget* target) override;
        void changeColor(sf::Text,sf::Vector2i);
         
     sf::Text NewGame;
     sf::Text Options;
     sf::Text Credits;
     sf::RectangleShape cursor;
     sf::Font font;
   };


}
