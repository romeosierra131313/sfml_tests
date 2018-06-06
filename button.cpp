#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


using namespace sf;




 class button{
      public:
sf::RectangleShape Button;
float bx = 10;
float by = 10;
float bwidth = 10;
float bheight = 10;
int bmethodPointer ;
sf::Text start;
sf::Font MyFont;


            
void setSize(float width,float height){
             Button.setSize(sf::Vector2f(width,height));
             bwidth = width;
             bheight = height;
             }
   float getWidth(){
     return Button.getSize().width;
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
     return Button.getPosition()xy;
   }            
/////void setSprite()             
             Button.setFillColor(Color(100,100,100,0));

void setText(String text){
             start.setString(g);
             start.setPosition(sf::Vector2f(screenWidth/10,screenHeight/20));
             start.setCharacterSize(24);
             start.setColor(Color::Green);
             start.setFont(MyFont);}
             
           } 
 void setMethod(*methodPointer){
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
