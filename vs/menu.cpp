#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


using namespace sf;




 class menu{
      public:
sf::RectangleShape cursor;
sf::RectangleShape startButton;
sf::RectangleShape otherButton;
sf::Text start;
sf::Font MyFont;
int positionIndicator = 0;
std::string g = "Start";
sf::String t;
           
           
            menu(float screenWidth,float screenHeight){
                
if (!MyFont.loadFromFile("arial.ttf"))
{
        throw std::string("Failed to load Arial.ttf");
}

            
             cursor.setSize(sf::Vector2f(screenWidth/10,screenHeight/20));
             cursor.setOutlineColor(sf::Color::Green);
             cursor.setPosition(sf::Vector2f(screenWidth/10,screenHeight/20));


             startButton.setSize(sf::Vector2f(screenWidth/10,screenHeight/20));
             startButton.setPosition(sf::Vector2f(screenWidth/10,screenHeight/20));
             otherButton.setFillColor(Color(100,100,100,100));

             otherButton.setSize(sf::Vector2f(screenWidth/10,screenHeight/20));
             otherButton.setPosition(sf::Vector2f(screenWidth/10,screenHeight/20+screenHeight/10));
             otherButton.setFillColor(Color(100,100,100,100));

             start.setString(g);
             start.setPosition(sf::Vector2f(screenWidth/10,screenHeight/20));
             start.setCharacterSize(24);
             start.setColor(Color::Green);
             start.setFont(MyFont);
             
           } 
      
 void setPositionIdicator(){
            
       
       

      } 
      bool renderTo(sf::RenderWindow& window){
            
             
             window.draw(start);
             window.draw(startButton);
             window.draw(otherButton);
             window.draw(cursor);

             //////checking mouse collision with hitboxs
             ////// change to array if you add more buttons
             if(detectCollision(window,startButton)){
                 positionIndicator = 0;
                 cursor.setFillColor(Color::Blue);
                 cursor.setPosition(startButton.getPosition());
                 if(Mouse::isButtonPressed(Mouse::Button::Left)){
                    return true;

                 }

             }
             else if(detectCollision(window,otherButton)){
                 positionIndicator = 1;
                 cursor.setFillColor(Color::Blue);
                 cursor.setPosition(otherButton.getPosition());
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
          
          