#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include<SFML/OpenGL.hpp>

using namespace sf;


sf::RectangleShape Button;
float bx = 10;
float by = 10;
float bwidth = 10;
float bheight = 10;

int bmethodPointer ;
/////////////glEnable(GL_TEXTURE_2D); //////////in main


 class button : public sf::Drawable{
      public:

sf::Text start;
sf::Font MyFont;


            
void setSize(float width,float height){
             Button.setSize(sf::Vector2f(width,height));
             bwidth = width;
             bheight = height;
             }
   float getWidth(){
     return bwidth;
   }
   float getHeight(){
     return Button.getSize.height;
   }
void setPosition(float x , float y ){             
             Button.setPosition(sf::Vector2f(x,y));
             bx = x;
             by = y;
             }
    float getX(){
     return Button.getPosition().x;
   }
   float getY(){
     return Button.getPosition().y;
   }            
/////void setSprite()             
             

void setText(String text){
    Button.setFillColor(Color(100,100,100,0));
             start.setString(text);
             start.setPosition(sf::Vector2f(x,y));
             start.setCharacterSize(24);
             start.setColor(Color::Green);
             start.setFont(MyFont);}
             
           } 
 void setMethod(int  *methodPointer){
      bmethodPointer = methodPointer;
 }    

      void renderTo(sf::RenderWindow& window){
            
             window.draw(Button);
             

             //////checking mouse collision with hitboxs
             ////// change to array if you add more buttons
             if(detectCollision(window,startButton)){
                 Button.setFillColor(Color(100,100,100,200));
                 if(Mouse::isButtonPressed(Mouse::Button::Left)){
                    (*bmethodPointer);
             

                 }

             }else {
                 Button.setFillColor(Color(100,100,100,0));
                
             }
             
             
      }
  private:
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const
      {
         glBegin(GL_QUADS);
         
         glEnd();
      
      }
      bool detectCollision(sf::RenderWindow& window,sf::RectangleShape shape){

            ///////getting mouse Position relative to window 
            sf::Vector2i mp =  Mouse::getPosition(window);
            ////// detect if its in the cursor's bounds
            if(mp.x >= shape.getPosition().x &&
               mp.x <= shape.getPosition().x + shape.getSize().x &&
               mp.y >= shape.getPosition().y && 
               mp.y <= shape.getPosition().y+shape.getSize().y){
                  return true;
            }     return false;

      }

           
button(float screenWidth,float screenHeight){
                
        if (!MyFont.loadFromFile("arial.ttf"))
          {
        throw std::string("Failed to load Arial.ttf");
            }
            }

      
       int main(){
      
             return 0;};    

       
     
};
© 2018 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
API
Training
Shop
Blog
About
