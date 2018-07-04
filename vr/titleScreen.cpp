#include <SFML/Graphics.hpp>
#include "titleScreen.h"
#include<iostream>


namespace mine{
titleScreen::titleScreen():screen{}{

font.loadFromFile("arial.ttf"); 
backGround.loadFromFile("stand.jpg");

}
void titleScreen::setup(sf::Vector2u screenSize){


spr.setTexture(backGround);
spr.setPosition(0,0);

NewGame.setString("New Game");
NewGame.setFont(font);
NewGame.setCharacterSize(50);
NewGame.setStyle(sf::Text::Bold);
NewGame.setFillColor(sf::Color::Blue);
NewGame.setPosition(1280/2,(720/10)*2);

Options.setString("Options");
Options.setFont(font);
Options.setCharacterSize(50);
Options.setStyle(sf::Text::Bold);
Options.setFillColor(sf::Color::Blue);
Options.setPosition(1280/2,(720/10)*3);

Editor.setString("Editor");
Editor.setFont(font);
Editor.setCharacterSize(50);
Editor.setStyle(sf::Text::Bold);
Editor.setFillColor(sf::Color::Blue);
Editor.setPosition(1280/2,(720/10)*4);

Credits.setString("Credits");
Credits.setFont(font);
Credits.setCharacterSize(50);
Credits.setStyle(sf::Text::Bold);
Credits.setFillColor(sf::Color::Blue);
Credits.setPosition(1280/2,(720/10)*5);

   

}
void titleScreen::handleInput(sf::Event event ,gameManager* gameManager){
    auto myPos = sf::Mouse::getPosition(*gameManager->getMyWindow()->
                         getwindow());
     
       changeColor(NewGame,myPos); 
       changeColor(Options,myPos); 
       changeColor(Editor,myPos); 
       changeColor(Credits,myPos); 

        if(NewGame.getGlobalBounds().contains(myPos.x,myPos.y)  &&
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
         NewGame.setFillColor(sf::Color::Red);
         std::cout<<"red";

         }
        else if(Options.getGlobalBounds().contains(myPos.x,myPos.y)  &&
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
         Options.setFillColor(sf::Color::Red);
         std::cout<<"red";

    }

        else if(Editor.getGlobalBounds().contains(myPos.x,myPos.y)  &&   
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
         Editor.setFillColor(sf::Color::Red);
         std::cout<<"red";
         gameManager->showEditorScreen();

    }
       else if(Credits.getGlobalBounds().contains(myPos.x,myPos.y)  &&   
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
         Editor.setFillColor(sf::Color::Red);
         std::cout<<"red";
         gameManager->showCredits();

    }


 

}
void titleScreen::render(sf::RenderTarget* target){
   target->draw(spr);
   target->draw(NewGame);
   target->draw(Options);
   target->draw(Editor);
   target->draw(Credits);
   
}

   void titleScreen::changeColor(sf::Text &text,sf::Vector2i &myPos){

   
    if(text.getGlobalBounds().contains(myPos.x,myPos.y)){
         text.setFillColor(sf::Color::Cyan);
    }
    else if (!text.getGlobalBounds().contains(myPos.x,myPos.y)){
          text.setFillColor(sf::Color::White);

    }
    

}
void titleScreen::renderUI(gameManager* gameManager,sf::RenderTarget* target){
             gameManager->getMyWindow()->getwindow()->setView(
                gameManager->getMyWindow()->getwindow()->getDefaultView() 
             );
             
   }

; 
}
