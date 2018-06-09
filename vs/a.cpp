#include <iostream>
#include <SFML/Graphics.hpp>
#include </home/a/vs/menu.cpp>
#include </home/a/vs/game.cpp>
using namespace sf;

    
    static float screenWidth = 1024;
    static float screenHeight = 720;
    
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "My first window bitch!");
    sf::Vector2i position = sf::Mouse::getPosition();
    menu Menu = menu(screenWidth,screenHeight);
    newgame Game;
    bool inGame = false;
     

 ///setup stuff
 int newGame(){
     if(!inGame){
    Game.setupbox();
    }
    inGame = true;
  return 1; 
 }
 /////create pointer
 int (*newGamePtr)() = newGame; 
 


   
int main () {
     while (window.isOpen())
    
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      window.clear();
 
 ///////draw menu or game
   if(!inGame){
      Menu.checkAllForCollision(*newGamePtr,window);
      window.draw(Menu);
      }
   if(inGame){
      window.draw(Game.aShape);
     //case 3:
}

     window.display();
    
    }
    
      

   



    

    return 0;
}
