
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "game.h"
#include <iostream>

namespace mine  {
   class CreditsScreen:public screen{
       public:
        CreditsScreen();
        void setup(sf::Vector2u) override;
        void handleInput(sf::Event event ,gameManager* gameManager) override;
        void render(sf::RenderTarget* target) override;
        void changeColor(sf::Text &text,sf::Vector2i &myPos);
        
         
     sf::Text Back;
     sf::Texture backGround;
     sf::Sprite spr;
     sf::Font font;
     
   };


}
