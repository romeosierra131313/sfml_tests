#include "game.h"
#include "titleScreen.h"
#include "EditorScreen.h"
#include "Editor.h"
#include "CreditsScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mine{

gameManager::gameManager(){
    setSize(sf::Vector2u(1280,720));
    myWindow.windowInit(getScreenSize(),"title");
    showTitle();
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
  if(myScreen != nullptr){
     delete myScreen;

  }
     myScreen = ascreen;
     myScreen->setup(getScreenSize());

  

}
void gameManager::showTitle(){
     setScreen(new titleScreen());

}
void gameManager::showEditorScreen(){
     setScreen(new EditorScreen());

}
void gameManager::showCredits(){
     setScreen(new CreditsScreen());

}
sf::Vector2u gameManager::getScreenSize(){
     return screenSize;

}
void gameManager::setSize(sf::Vector2u size){
     screenSize.x = size.x;
     screenSize.y = size.x;

}
;
}

