#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


using namespace sf;




 class menu: public sf::Drawable {
      public:
sf::RectangleShape startButton;
sf::RectangleShape otherButton;
sf::Text start;
sf::Font MyFont;
int positionIndicator = 0;
std::string g = "Start";
sf::String t;
         
         public:
            menu(float screenWidth,float screenHeight){
                
if (!MyFont.loadFromFile("arial.ttf"))
{
        throw std::string("Failed to load Arial.ttf");
}

///////////setup stuff here

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
      

      bool checkAllForCollision(int i() ,sf::RenderWindow& window){
           

             //////checking mouse collision with hitboxs
             ////// change to array if you add more buttons
             if(detectCollision(window,startButton)){
                 positionIndicator = 0;
                 startButton.setFillColor(Color::Blue); 
                   if(detectCollision(window,startButton) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                       i();
                       
                   }
             }
             else if (!detectCollision(window,startButton)){   startButton.setFillColor(Color::White); }

             if(detectCollision(window,otherButton)){
                 positionIndicator = 1;
                 otherButton.setFillColor(Color::Blue);
                 
                 }
                 else if (!detectCollision(window,otherButton))
                 {   otherButton.setFillColor(Color::White); }
             
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

   // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    //...          
 void draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //assuming m_shape is the sf::RectangleShape(detectCollision(window,otherButton))
    target.draw(startButton,states);
    target.draw(otherButton,states);
} 
};
      
    

       
     

          
          