#include <SFML/Graphics.hpp>
#include "titleScreen.h"
#include<iostream>


namespace mine{
titleScreen::titleScreen():screen(){

font.loadFromFile("arial.ttf"); 

}
void titleScreen::setup(sf::Vector2u size){



NewGame.setString("New Game");
NewGame.setFont(font);
NewGame.setCharacterSize(50);
NewGame.setStyle(sf::Text::Bold);
NewGame.setFillColor(sf::Color::Blue);
NewGame.setPosition(size.x/2,(size.y/10)*5);

Options.setString("New Game");
Options.setFont(font);
Options.setCharacterSize(50);
Options.setStyle(sf::Text::Bold);
Options.setFillColor(sf::Color::Blue);
Options.setPosition(size.x/2,(size.y/10)*6);

Credits.setString("New Game");
Credits.setFont(font);
Credits.setCharacterSize(50);
Credits.setStyle(sf::Text::Bold);
Credits.setFillColor(sf::Color::Blue);
Credits.setPosition(size.x/2,(size.y/10)*7);
   

}
void titleScreen::handleInput(sf::Event event ,gameManager* gameManager){
    auto mousePosition = sf::Mouse::getPosition(*gameManager->getMyWindow()->
                         getwindow());
        changeColor(NewGame,mousePosition);
        changeColor(Options,mousePosition);
        changeColor(Credits,mousePosition);
 

}
void titleScreen::render(sf::RenderTarget* target){
   target->draw(NewGame);

}
void titleScreen::changeColor(sf::Text myText,sf::Vector2i myPos){
    if(myText.getGlobalBounds().contains(myPos.x,myPos.y)  &&
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
         myText.setFillColor(sf::Color::Red);

    }
    else if(myText.getGlobalBounds().contains(myPos.x,myPos.y)){
         myText.setFillColor(sf::Color::Cyan);

    }
    else{
          myText.setFillColor(sf::Color::Blue);
//

    }

}

}