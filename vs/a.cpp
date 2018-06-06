#include <iostream>
#include <SFML/Graphics.hpp>
#include </home/a/vs/stateManager.cpp>
#include </home/a/vs/menu.cpp>
using namespace sf;
    static float screenWidth = 1024;
    static float screenHeight = 720;
    int gameState = 0; 
    stateManager sm(&gameState); 
    menu menui=menu(screenWidth,screenHeight);
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "My first window bitch!");
    sf::Vector2i position = sf::Mouse::getPosition();

     void dosomething(){
          std::cout<<"didsomething";

        }
   
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

    switch (gameState){
     case 0:
   
    
     
      menui.setPositionIdicator();
     // menui.renderTo(window);
      if(menui.renderTo(window)){
           dosomething();

      } 
     // window.draw(menui.cursor);
     // window.draw(menui.start);
     //case 2:
     //case 3:

    }
    
      window.display();




    }

    return 0;
}