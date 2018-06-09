#include <iostream>
#include <SFML/Graphics.hpp>
#include </home/a/vs/stateManager.cpp>
#include </home/a/vs/menu.cpp>
#include </home/a/vs/game.cpp>
using namespace sf;

    
    static float screenWidth = 1024;
    static float screenHeight = 720;
  //  stateManager sm = stateManager(); 
    
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "My first window bitch!");
    sf::Vector2i position = sf::Mouse::getPosition();
    menu m = menu(screenWidth,screenHeight);
    newgame g;
    bool inGame = false;
     

 
 int newGame(){
     if(!inGame){
    g.setupbox();
    }
    inGame = true;
  return 1; 
 }
 int (*i)() = newGame; 
 


   
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
 
 
   if(!inGame){
      m.renderTo(*i,window);
      window.draw(m);
      }
   if(inGame){
      window.draw(g.aShape);
     //case 3:
}

     window.display();
    
    }
    
      

   



    

    return 0;
}
