#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;



class newgame{

 public :
 RectangleShape aShape;
     newgame(){
         

      std::cout << "new game";
}
void setupbox(){

         aShape.setSize(Vector2f(300,300));
         aShape.setPosition(Vector2f(300,300));
         aShape.setFillColor(Color(200,200,200,110));
}
  
};