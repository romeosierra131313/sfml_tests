
#include<SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

namespace mine{

class windowContainer{
     
     public:
       windowContainer();
       windowContainer(sf::Vector2u windowSize,std::string title);
       void begin();
       void end();
       void destroy();
       bool getisFinished();
       sf::RenderWindow* getwindow(){return &renderWindow;};
       
     private:
      
 sf::RenderWindow renderWindow;
 bool isFinished = false;

};
}