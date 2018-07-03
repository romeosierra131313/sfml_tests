#include <SFML/Graphics.hpp>
#include "CreditsScreen.h"
#include<iostream>

namespace mine{

CreditsScreen::CreditsScreen(){
    font.loadFromFile("arial.ttf"); 
    backGround.loadFromFile("stand.jpg");

}
void CreditsScreen::setup(sf::Vector2u screenSize){
    spr.setTexture(backGround);
    spr.setPosition(0,0);
    
Back.setString("<");
Back.setFont(font);
Back.setCharacterSize(50);
Back.setStyle(sf::Text::Bold);
Back.setFillColor(sf::Color::Blue);
Back.setPosition(1280/2,(720/10)*6);

}
void CreditsScreen::handleInput(sf::Event event ,gameManager* gameManager){
   auto myPos = sf::Mouse::getPosition(*gameManager->getMyWindow()-> getwindow());
   changeColor(Back,myPos);

if(Back.getGlobalBounds().contains(myPos.x,myPos.y)  &&
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
         Back.setFillColor(sf::Color::Red);
         std::cout<<"red";
         gameManager->showTitle();
         }


}
void CreditsScreen::render(sf::RenderTarget* target){
   
   target->draw(spr);
   target->draw(Back);
   
}
  void CreditsScreen::changeColor(sf::Text &text,sf::Vector2i &myPos){

   
    if(text.getGlobalBounds().contains(myPos.x,myPos.y)){
         text.setFillColor(sf::Color::Cyan);
    }
    else if (!text.getGlobalBounds().contains(myPos.x,myPos.y)){
          text.setFillColor(sf::Color::White);

    }
    

}
};