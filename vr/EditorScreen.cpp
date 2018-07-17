#include "EditorScreen.h"
#include <iostream>

namespace mine{
    EditorScreen::EditorScreen():screen{}{
        font.loadFromFile("arial.ttf"); 
        backGround.loadFromFile("stand.jpg");


        
    }
    void EditorScreen::setup(sf::Vector2u screenSize){
        spr.setTexture(backGround);
        spr.setPosition(0,0);

Create.setString("Create");
Create.setFont(font);
Create.setCharacterSize(50);
Create.setStyle(sf::Text::Bold);
Create.setFillColor(sf::Color::Blue);
Create.setPosition(1280/2,(720/10)*2);

EnterName.setString("EnterName :");
EnterName.setFont(font);
EnterName.setCharacterSize(50);
EnterName.setStyle(sf::Text::Bold);
EnterName.setFillColor(sf::Color::Blue);
EnterName.setPosition(1280/2,(720/10)*4);

Name.setString("Name");
Name.setFont(font);
Name.setCharacterSize(40);
Name.setStyle(sf::Text::Bold);
Name.setFillColor(sf::Color::Blue);
Name.setPosition(1280/2,(720/10)*5);

Forward.setString(">");
Forward.setFont(font);
Forward.setCharacterSize(50);
Forward.setStyle(sf::Text::Bold);
Forward.setFillColor(sf::Color::Blue);
Forward.setPosition((1280/10)*4,(720/10)*5);

Load.setString("Load");
Load.setFont(font);
Load.setCharacterSize(50);
Load.setStyle(sf::Text::Bold);
Load.setFillColor(sf::Color::Blue);
Load.setPosition(1280/2,(720/10)*3);

Back.setString("<");
Back.setFont(font);
Back.setCharacterSize(50);
Back.setStyle(sf::Text::Bold);
Back.setFillColor(sf::Color::Blue);
Back.setPosition(1280/2,(720/10)*6);

    }
    void  EditorScreen::handleInput(sf::Event event ,gameManager* gameManager){
        auto myPos = sf::Mouse::getPosition(*gameManager->getMyWindow()-> getwindow());
        changeColor(Back,myPos);
        changeColor(Create,myPos);
        changeColor(Load,myPos);
        changeColor(Name,myPos);

if(Back.getGlobalBounds().contains(myPos.x,myPos.y)  
   &&  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
   &&  nameSelected == true){
         Back.setFillColor(sf::Color::Red);
         std::cout<<"red";
         gameManager->showEditorScreen();
         }
if(Back.getGlobalBounds().contains(myPos.x,myPos.y)  
   &&  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
   &&  nameSelected == false){
         Back.setFillColor(sf::Color::Red);
         std::cout<<"red";
         gameManager->showTitle();
         }         
else if(Create.getGlobalBounds().contains(myPos.x,myPos.y)  &&
       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
        &&  nameSelected == false){
         Back.setFillColor(sf::Color::Red);
         std::cout<<"red";
         nameSelected = true;
         }
else if(Name.getGlobalBounds().contains(myPos.x,myPos.y)  
        && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
        &&  nameSelected == true){
         Back.setFillColor(sf::Color::Red);
         nameString.clear();
         Name.setString("|");
         }
else if (event.type == sf::Event::TextEntered && nameSelected == true)
{
    // Handle ASCII characters only
    if (event.text.unicode < 128)
    {   

        nameString += static_cast<char>(event.text.unicode);
        Name.setString(nameString);
    }
}
else if(Forward.getGlobalBounds().contains(myPos.x,myPos.y)
        &&  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
        && nameSelected == true){
            nameString += ".txt";
            std::cout<<nameString;
            createNewMap(gameManager);
            
         }



    }
    void  EditorScreen::render(sf::RenderTarget* target){
        target->draw(spr);
           if(nameSelected == false){
        target->draw(Create);
        target->draw(Load);
           }
          else if(nameSelected == true){
              target->draw(EnterName);
              target->draw(Name);
              target->draw(Forward);
              }
        
        target->draw(Back);
        

    }
    void  EditorScreen::openFile(){}
    void  EditorScreen::writeFile(){}
    void EditorScreen::changeColor(sf::Text &text,sf::Vector2i &myPos){

   
    if(text.getGlobalBounds().contains(myPos.x,myPos.y)){
         text.setFillColor(sf::Color::Cyan);
    }
    else if (!text.getGlobalBounds().contains(myPos.x,myPos.y)){
          text.setFillColor(sf::Color::White);

    }
  
}
bool EditorScreen::fexists(const std::string& nameString)
{
  std::ifstream ifile(nameString.c_str());
  return (bool)ifile;

}
void EditorScreen::createNewMap(gameManager* gameManager){

   if(fexists(nameString)){
      Name.setString("name is taken !");

   }else{
       std::ofstream outfile (nameString);
       outfile.close();
       gameManager->getMyWindow()->getView()->zoom(1.0f);
       gameManager->showEditor(name);
       }
   

}
void EditorScreen::renderUI(gameManager* gameManager,sf::RenderTarget* target){
             gameManager->getMyWindow()->getwindow()->setView(
                gameManager->getMyWindow()->getwindow()->getDefaultView()  
             );
             
   }
;
}
