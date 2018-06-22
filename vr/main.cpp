#include "game.h"
#include <iostream>

#include <SFML/Graphics.hpp>


mine::gameManager m;


int main()
 


{

    m.initWindow();
    while( m.getMyWindow()->getisFinished()){
     m.render();
  
    }

    return 0;
}
