
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "game.h"
#include "Tile.h"
#include <vector>
#include <iostream>

namespace mine{
     
    class Editor:public screen{
        public:
         Editor();
        void setup(sf::Vector2u) override;
        void handleInput(sf::Event event ,gameManager* gameManager) override;
        void render(sf::RenderTarget* target) override;
        void renderUI(gameManager* gameManager,sf::RenderTarget* target)override;
        sf::Vector2f getTerra(Tile& t);

        private:
        
         std::vector<Tile> map;
         std::vector<Tile> UImap;
         std::vector<Tile>::iterator it;
         std::vector<Tile>::iterator it2;
          sf::Font font;
          sf::Text t;
          sf::RectangleShape tileHitBox;
          sf::RectangleShape UIBG;
         float x;
         float y;
         int TileWidth;
         bool toggleGrid;
         bool hasFocus;
         bool drawingTerrain;
         bool layer2;
         float cameraZoom = 1; 
         sf::View editorView;
         sf::Sprite position;
         sf::Texture TileSet;
         sf::Sprite TSSprite;
         sf::IntRect rectSourceSprite;
         sf::IntRect rectSourceSpritetemp;
         unsigned int top;
         unsigned int left;

         
         
    };



}