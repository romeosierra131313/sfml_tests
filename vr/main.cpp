#include "game.h"
#include <iostream>

#include <SFML/Graphics.hpp>


mine::gameManager m;


int main()
 


{

    while( !m.getMyWindow()->getisFinished()){
     
     m.update();
     m.render();
     
    }

    return EXIT_SUCCESS;
}
