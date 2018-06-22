#include "windowContainer.h"
#include <iostream>


namespace mine
{

windowContainer::windowContainer(){}
windowContainer::windowContainer(sf::Vector2u windowSize,std::string title){
   renderWindow.setSize(windowSize);
   renderWindow.setTitle(title);
   std::cout<< "p";
   isFinished = true;


}
void windowContainer::begin(){renderWindow.clear(sf::Color::Black);}
void windowContainer::end(){renderWindow.display();}
void windowContainer::destroy(){
   renderWindow.close();

}
bool windowContainer::getisFinished(){
  return isFinished;

}
}
;