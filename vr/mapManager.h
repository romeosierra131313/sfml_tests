#include <fstream>
#include"string.h"
#include"game.h"
#include<iostream>
#include<SFML/graphics.hpp>

namespace mine{

 class mapManager{
    
   public: 
    mapManager();
    void checkIfExists(string name);
    void openMap(String name,gameManager* gameManager);
    void writeMap(String name);
   
    std::ifstream myFile;
    std::ifstream ifile;
    
 
 
 }

}
