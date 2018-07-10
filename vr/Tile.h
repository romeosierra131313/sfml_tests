
#include "string.h"
#include <iostream>

namespace mine{

  struct Tile{
      public:
         Tile(){}
         float x;
         float y;
         int bitmasktype;
         bool isFliped;
         int textureTop;
         int  textureLeft;
         int tileType;
         void render(sf::RenderTarget* target,sf::Sprite spr){
              spr.setPosition(x,y);
              target->draw(spr);
         }
        // Tile(const Tile&) = delete;
        // Tile& operator=(const Tile&) =delete;


  };

}