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
    void openMap(string name,gameManager* gameManager);
    void writeMap(string name);
   
    std::ifstream myFile;
    std::ifstream ifile;
    
 
 
 }

}
