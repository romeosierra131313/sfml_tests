
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "game.h"
#include <iostream>

namespace mine  {
   class titleScreen:public screen{
       public:
        titleScreen();
        void setup(sf::Vector2u) override;
        void handleInput(sf::Event event ,gameManager* gameManager) override;
        void render(sf::RenderTarget* target) override;
        void changeColor(sf::Text &text,sf::Vector2i &myPos);
        void renderUI(gameManager* gameManager,sf::RenderTarget* target) override;
        
       
         
     sf::Text NewGame;
     sf::Text Options;
     sf::Text Editor;
     sf::Text Credits;
     sf::Texture backGround;
     sf::Sprite spr;
     sf::Font font;
     
   };


}
