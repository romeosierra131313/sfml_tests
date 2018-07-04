
#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
#include<iostream>

namespace mine{

class gameManager;

struct screen{
    public:
       screen(){}

      virtual ~screen(){}
      virtual void setup(sf::Vector2u) = 0;
      virtual void handleInput(sf::Event,gameManager* gameManager)=0;
      virtual void render(sf::RenderTarget* target)=0;
      virtual void renderUI(gameManager* gameManager,sf::RenderTarget* target)=0;
      screen(const screen&) = delete;
      screen& operator=(const screen&) = delete;
};


}

#endif