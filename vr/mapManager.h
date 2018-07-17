#include <fstream>
#include"string.h"
#include"game.h"
#include<iostream>
#include<SFML/graphics.hpp>

namespace mine{

 class mapManager{
    
   public: 
    mapManager();
    checkIfExists(string name);
    openMap(String name,gameManager* gameManager);
    writeMap(String name);
   
    std::ifstream myFile;
    std::ifstream ifile;
    
 
 
 }

}
