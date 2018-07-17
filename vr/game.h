#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "windowContainer.h"
#include "screen.h"
#include <iostream>

namespace mine {



class gameManager{

     public :
         gameManager();
         void handleInput();
         void update();
         void render();
         void setScreen(screen* ascreen);
         void showTitle();
         void startGame();
         void showEditorScreen();
         void showEditor(const std::string name);
         void showCredits();
         sf::Vector2u getScreenSize();
         void setSize(sf::Vector2u);
         bool isDone = false;
         windowContainer* getMyWindow(){return &myWindow;};
    private:
         windowContainer myWindow ;
         screen* myScreen{nullptr};
         sf::Vector2u screenSize;
         sf::Clock clock;
         float lastTime = 0;
};
}
#endif

 
