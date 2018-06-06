#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


using namespace sf;




 class Button{
      public:
sf::RectangleShape button;
sf::Text start;
sf::Font MyFont;
sf::String t;
           
           
            Button(float screenWidth,float screenHeight){
                
if (!MyFont.loadFromFile("arial.ttf"))
{
        throw std::string("Failed to load Arial.ttf");
}

            
 void setSize(float width,float height){
        button.setSize(sf::Vector2f(width,height));
 }            
void setPosition(float x , float y ){
        button.setPosition(sf::Vector2f(x,y));
}
void setText(String text){
             button.setString(g);
             button.setPosition(sf::Vector2f(button.getPosition().x,button.getPosition().y));
             button.setCharacterSize(24);
             button.setColor(Color::Green);
             button.setFont(MyFont);
}
             
            
             button.setFillColor(Color(100,100,100,100));


            
             
           } 
      
      bool renderTo(sf::RenderWindow& window){
            
             
             window.draw(start);
             window.draw(button);

             //////checking mouse collision with hitboxs
             ////// change to array if you add more buttons
             if(detectCollision(window,button)){
                 cursor.setFillColor(Color::Blue);
                 cursor.setPosition(button.getPosition());
                 if(Mouse::isButtonPressed(Mouse::Button::Left)){
                    return true;

                 }

             }
           
             return false;
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

      
       int main(){
      
             return 0;};    

       
     
};
