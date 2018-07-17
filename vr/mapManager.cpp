#include<iostream>

namepace mine{
  
   void mapManager::checkIfExists(const std::string& name){
     std::ifstream ifile(name.c_str());
     return (bool)ifile;

   }
   void mapManager::openMap(string name, gameManager* gameManager){
        if(fexists(name)){
     

   }else{
       std::ofstream outfile (name);
       outfile.close();
       gameManager->getMyWindow()->getView()->zoom(1.0f);
       gameManager->showEditor();
       }
   
   }
   void mapManager::writeMap(string name){}

}
