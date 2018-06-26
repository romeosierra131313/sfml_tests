#include "windowContainer.h"
#include <iostream>


namespace mine
{

windowContainer::windowContainer(){}

void windowContainer::windowInit(sf::Vector2u windowSize,std::string title){
  
	 renderWindow.create(sf::VideoMode{ windowSize.x, windowSize.y, 32 },title, sf::Style::Default);
   renderWindow.setSize(windowSize);
   renderWindow.setTitle(title);
   renderWindow.display();
   std::cout<< "p";
  
   isFinished = false;


}
void windowContainer::begin(){renderWindow.clear(sf::Color::White);}

void windowContainer::end(){renderWindow.display();}

void windowContainer::destroy(){
   renderWindow.close();

}

void windowContainer::update(sf::Event event ){
    if (event.type == sf::Event::Closed){
                isFinished = true;
                destroy();
    }
    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
               std::cout << "de";
               isFinished = true;
               destroy();

    }

}
bool windowContainer::getisFinished(){
  return isFinished;

}
}
;