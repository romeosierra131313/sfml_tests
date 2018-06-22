
#include <SFML/Graphics.hpp>
#include <iostream>
#include "windowContainer.h"


namespace mine {



class gameManager{

     public :
         gameManager();
         void initWindow();
         void handleInput();
         void update();
         void render();
         bool isDone = false;
         windowContainer* getMyWindow(){return &myWindow;};
    private:
         windowContainer myWindow ;
    
};
}