#include "game.h"
#include "titleScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mine{

gameManager::gameManager(){
    setSize(sf::Vector2u(1280,720));
    myWindow.windowInit(getScreenSize(),"title");
    setScreen(new titleScreen());
    }



void gameManager::render(){

    myWindow.begin();
    myScreen->render(myWindow.getwindow());
    myWindow.end();

}
void gameManager::update(){
    sf::Event event;
  while(myWindow.getwindow()->pollEvent(event)){
    myWindow.update(event);
    if(myScreen != nullptr){
    myScreen->handleInput(event, this);
    }
    }
       
}
void gameManager::setScreen(screen* ascreen){
  
     myScreen = ascreen;
     myScreen->setup(getScreenSize());

  

}
sf::Vector2u gameManager::getScreenSize(){return screenSize;}
 void gameManager::setSize(sf::Vector2u mySize){screenSize = mySize;}
};