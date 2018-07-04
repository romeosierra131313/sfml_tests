#include "game.h"
#include <iostream>

#include <SFML/Graphics.hpp>


mine::gameManager m;


int main()
 


{
    sf::Clock clock;
float lastTime = 0;
    m.getMyWindow()->windowInit(m.getScreenSize(),"tie");

    while( !m.getMyWindow()->getisFinished()){
     
     m.update();
     m.render();
     float currentTime = clock.restart().asSeconds();
            float fps = 1.f / (currentTime - lastTime);
            lastTime = currentTime;
            m.getMyWindow()->getwindow()->setTitle(std::to_string(fps));
    }

    return EXIT_SUCCESS;
}
