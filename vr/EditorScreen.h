
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "game.h"
#include <fstream>
#include "string.h"
#include <iostream>

namespace mine  {
   class EditorScreen:public screen{
       public:
        EditorScreen();
        void setup(sf::Vector2u) override;
        void handleInput(sf::Event event ,gameManager* gameManager) override;
        void render(sf::RenderTarget* target) override;
        void changeColor(sf::Text &text,sf::Vector2i &myPos);
        void renderUI(gameManager* gameManager,sf::RenderTarget* target)override;
        void openFile();
        void writeFile();
        void createNewMap(gameManager* gameManager);
        bool fexists(const std::string& nameString);
        
        
       private:  
     std::ifstream myFile;
     std::ifstream iFile;
     sf::Font font;
     sf::Texture backGround;
     sf::Sprite spr;
     sf::Text Create;
        bool nameSelected = false;
        sf::Text EnterName;
        sf::Text Name;
        std::string nameString ="name";
     sf::Text Load;
     sf::Text Back;
     sf::Text Forward;
   };


}
