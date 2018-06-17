#pragma once
#include<SFML/Graphics>
#include <iostream>

namespace myGame : public sf::Drawable{
    
    class button{
        
         public:
               float getX(){return x;};
               float getY(){return y;};
               float getWidth(){return width;};
               float getHeight(){return height;};
               float setX(float ix){x = ix;};
               float setY(float iy){y = iy;};
               float setX(float iwidth){width = iwidth;};
               float setX(float iheight){height = iheight;};
               void pack();
               virtual void handleInput() = 0;
               virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const
               
         
         private:
               float x = 0f;
               float y = 0f;
               float width = 100f;
               float height = 100f;
               sf::rectangleShape rect;
               ///sf::Texture texture;
               
    
    
    }



}
