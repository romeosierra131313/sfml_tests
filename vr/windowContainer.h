
#include<SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

namespace mine{

class windowContainer{
     
     public:
       windowContainer();
       void windowInit(sf::Vector2u,std::string);
       void begin();
       void end();
       void destroy();
       bool getisFinished();
       void update(sf::Event);
       sf::RenderWindow* getwindow(){return &renderWindow;};
       sf::View* getView(){return &view;};
     private:
      
 sf::RenderWindow renderWindow;
 sf::View view;
 bool isFinished;

};
}