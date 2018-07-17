#include <SFML/Graphics.hpp>
#include "Editor.h"
#include <iostream>

namespace mine{
     Editor::Editor(){
             font.loadFromFile("arial.ttf");  
             editorView.setCenter(sf::Vector2f(640,392));
             editorView.setSize(sf::Vector2f(1600,778)); 
             TileSet.loadFromFile("terra.png");
             toggleGrid = true;
             hasFocus = false;
             layer2 = false;
             drawingTerrain = true;
             TileWidth = 64;
             
             

    }
     Editor::Editor(std::string& name){
             font.loadFromFile("arial.ttf");  
             editorView.setCenter(sf::Vector2f(640,392));
             editorView.setSize(sf::Vector2f(1600,778)); 
             TileSet.loadFromFile("terra.png");
             toggleGrid = true;
             hasFocus = false;
             layer2 = false;
             drawingTerrain = true;
             TileWidth = 64;
             name = name;
             

    }
    void Editor::setup(sf::Vector2u screenSize){

        //////creating editor grid////////
          for(int i = 0; i <100 ; i++){
              
               for(int j = 0; j <100; j++){
              Tile *tile = new Tile;
              tile ->x = i*TileWidth;
              tile ->y = j*TileWidth;
              tile->tileType = 0;
              tile->isFliped = false;
              map.push_back(*tile);
              if(x > 6399){x=0;}
              x+=TileWidth;
            

          }y+=TileWidth;
          }
          x =0;
          y=0;


          /////////creating ui grid  layer 2//////
           for(int i = 0; i <2 ; i++){
             for(int j = 0; j <10 ; j++){
              Tile *tile = new Tile;
              tile ->x = i*TileWidth;
              tile ->y = j*TileWidth;
              tile->tileType = 0;
              UImap.push_back(*tile);
              if(x > 639 ){x=0;}
              x+=TileWidth;
          }
          y+=TileWidth;
          }
      t.setString("0");
      t.setFont(font);
      t.setStyle(sf::Text::Bold);
      t.setFillColor(sf::Color::Blue);

      UIBG.setSize(sf::Vector2f(1280,TileWidth));
      UIBG.setOutlineColor(sf::Color::Black);
      UIBG.setOutlineThickness(1);
      UIBG.setFillColor(sf::Color::Blue);
      UIBG.setPosition(sf::Vector2f(0,0));

      tileHitBox.setSize(sf::Vector2f(TileWidth,TileWidth));
      tileHitBox.setOutlineColor(sf::Color::Black);
      tileHitBox.setOutlineThickness(1);
      tileHitBox.setPosition(sf::Vector2f(0,0));

      rectSourceSprite.top = 64;
      rectSourceSprite.left = 0;
      rectSourceSprite.height = TileWidth;
      rectSourceSprite.width = TileWidth;
      rectSourceSpritetemp.top = 0;
      rectSourceSpritetemp.left = 0;
      rectSourceSpritetemp.height = TileWidth;
      rectSourceSpritetemp.width = TileWidth;

      
      position.setTexture(TileSet);
      rectSourceSprite.top = 64;
      rectSourceSprite.left =0;
      position.setTextureRect(rectSourceSprite);
      
      TSSprite.setTexture(TileSet);
      TSSprite.setPosition(0,TileWidth);

    }
    void Editor::handleInput(sf::Event event ,gameManager* gameManager){
       
       auto myPosUI = sf::Mouse::getPosition(*gameManager->getMyWindow()->
                         getwindow());

         if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){ 
            if(myPosUI.x < 129 || myPosUI.y < 65){hasFocus =true;
            
              if(layer2){
                     for(it = UImap.begin(); it!= UImap.end();++it)
                     {
                        tileHitBox.setPosition(sf::Vector2f(it->x,it->y));
                
                        if(hasFocus && tileHitBox.getGlobalBounds().contains(myPosUI.x,myPosUI.y)){
                   
                        rectSourceSpritetemp.left =  tileHitBox.getGlobalBounds().left;

                        rectSourceSpritetemp.top =  tileHitBox.getGlobalBounds().top;
                        position.setTextureRect(rectSourceSpritetemp);
                 
                }
           }
         }

              if(myPosUI.y < 65 && myPosUI.x > 360){
                layer2 = true;
               }
              if(myPosUI.y < 65 && myPosUI.x < 360){
                layer2 = false;
               } 
              if(myPosUI.x < 64 && !layer2){drawingTerrain =true;}
              if(myPosUI.x >64 && myPosUI.x < 128 && !layer2){
              drawingTerrain = false;
            } 
              }
            
            
         
         else if(myPosUI.x > 129 && myPosUI.y > 64){hasFocus =false;}


     }
               
               
           

        /////////setting EDITOR VIEW///////////
          gameManager->getMyWindow()->getwindow()->setView(editorView);
          /////mousepos reference screen///////
           auto myPos = sf::Mouse::getPosition(*gameManager->getMyWindow()->
                         getwindow());

          ///////mousepos reference view///////
           sf::Vector2f mouse_pos = gameManager->getMyWindow()->
                         getwindow()->mapPixelToCoords(myPos);


          ///////zoom/////////                       
            if (event.type == sf::Event::MouseWheelMoved) {
        editorView.zoom(1.f-event.mouseWheel.delta*0.1f);
        gameManager->getMyWindow()->getwindow()->setView(editorView);
        
      }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        editorView.move(-10,0 );
       }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        editorView.move(10,0 );
      }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        editorView.move(0,10 );
       }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        editorView.move(0,-10 );
       }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        toggleGrid = false;
       }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
           std::cout<< "oooooooooooooooooooooooooooooooooooooo"; 
         for(it = map.begin(); it!= map.end();++it){
                if(it->tileType == 1){
                      sf::Vector2f tempV2 = getTerra(*it);
                      it->textureTop = tempV2.x;
                      it->textureLeft =tempV2.y;}
                      else{}

           }
         }
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  
           

           for(it = map.begin(); it!= map.end();++it){
               
                 tileHitBox.setPosition(sf::Vector2f(it->x,it->y));
                 
                  if(!hasFocus && tileHitBox.getGlobalBounds().contains(
                      mouse_pos.x,mouse_pos.y))
                      {
                       if(drawingTerrain )
                    {
                       it->tileType = 1;
 
                       sf::Vector2f tempV2 = getTerra(*it);
                      it->textureTop = tempV2.x;
                      it->textureLeft =tempV2.y;
                  
                     
                       if(layer2)
                    {
                      it->textureLeft = rectSourceSpritetemp.left;
                      it->textureTop = rectSourceSpritetemp.top;
                    }

                    }
                      else if(!drawingTerrain)
                    {
                      it->tileType = 0;
                    }  
                      
                      }
           }
                    


                    
                    
                }
                   
                }
               
               
           


           


    
    void Editor::render(sf::RenderTarget* target){
           target->setView(editorView); 
          
           for(it = map.begin(); it!= map.end();++it){
               
               
               tileHitBox.setPosition(sf::Vector2f(it->x,it->y));
               if(toggleGrid){
               target->draw(tileHitBox);
               }
                 if(it->tileType == 1){
                  
                      rectSourceSprite.left = it->textureTop;
                      rectSourceSprite.top = it->textureLeft;
                      position.setTextureRect(rectSourceSprite);
                      if(it->isFliped){
                        position.setOrigin(position.getLocalBounds().width,0);
                        position.setScale(-1.0f,1.0f);
                      }
                      else if(!it->isFliped){
                        position.setOrigin(0,0);
                        position.setScale(1.0f,1.0f);
                        }
                      it->render(target,position);

                      }
                else if(it->tileType == 0){
                      

                }
    
                  
                 
           } 
           
           
          
    }
   void Editor::renderUI(gameManager* gameManager,sf::RenderTarget* target){
             gameManager->getMyWindow()->getwindow()->setView(
                gameManager->getMyWindow()->getwindow()->getDefaultView() 
             );
  if(layer2){          
 target->draw(TSSprite);


for(it = UImap.begin(); it!= UImap.end();++it){
               
               tileHitBox.setPosition(sf::Vector2f(it->x,it->y));
               tileHitBox.setFillColor(sf::Color::Transparent);
               target->draw(tileHitBox);
                  
                }}
                else{
               tileHitBox.setPosition(sf::Vector2f(0,64));
               tileHitBox.setFillColor(sf::Color::Transparent);
               target->draw(tileHitBox);

               tileHitBox.setPosition(sf::Vector2f(64,64));
               tileHitBox.setFillColor(sf::Color::Transparent);
               target->draw(tileHitBox);

                }
  target->draw(UIBG);

            


   }

   sf::Vector2f Editor::getTerra(Tile& t){
        bool North = false;
        bool East = false;
        bool South = false;
        bool West = false;
        int value = 0;
        sf::Vector2f textureLocation;
        for(it2 = map.begin(); it2!= map.end();++it2){
          if(it2->tileType ==1){
             

if(it2->x == t.x             && it2->y == t.y-TileWidth)
               { ///// checking N
                value += 2;
                North = true;
               }

else if(it2->x == t.x + TileWidth && it2->y == t.y)
               { ///// checking E
                value += 16;
                East = true;
               }
else if(it2->x == t.x  && it2->y == t.y+TileWidth)
               { ///// checking S
                value += 64;
                South = true;
               }
else if(it2->x == t.x - TileWidth && it2->y == t.y)
               { ///// checking W
                value += 8;
                West = true;
               }
          }
        }

          for(it2 = map.begin(); it2!= map.end();++it2){
          if(it2->tileType ==1){
               if(it2->x == t.x - TileWidth && it2->y == t.y-TileWidth)
               { ///// checking NW
                if(North && West ){
                value += 1;}
               }
               
               else if(it2->x == t.x + TileWidth && it2->y == t.y-TileWidth)
               { ///// checking NE
                if(North && East){
                value += 4;}
               }
               else if(it2->x == t.x + TileWidth && it2->y == t.y+TileWidth)
               { ///// checking SE
                if(South && East ){
                value += 32;}
               }
              
               else if(it2->x == t.x - TileWidth && it2->y == t.y+TileWidth)
               { ///// checking SW
                if(South && West ){
                value += 128 ;}
               }
               
          }

        }
        
        switch(value)
        {
           case 0: 
                  textureLocation.x = 256;
                  textureLocation.y = 320;
           break;
           
           
           case 4:  
                  textureLocation.x = 256;
                  textureLocation.y = 320;
           break;
           case 6: 
                  textureLocation.x = 386;
                  textureLocation.y = 64;
           break;
           case 7: 
                  textureLocation.x = 64;
                  textureLocation.y = 0;
           break;
           
           
           case 12:  
                  textureLocation.x = 0;
                  textureLocation.y = 320;
           break;
           
           case 16:  
                  textureLocation.x = 256;
                  textureLocation.y = 320;
           break;
           
           
           
           
           case 36: 
                  textureLocation.x = 128;
                  textureLocation.y = 128;
           break;
           
           case 41: 
                  textureLocation.x = 128;
                  textureLocation.y = 128;
           break;
           case 48:  
                  textureLocation.x = 320;
                  textureLocation.y = 64;
           break;
           case 54: 
                  textureLocation.x = 386;
                  textureLocation.y = 64;
           break;
           case 58:  
                  textureLocation.x = 320;
                  textureLocation.y = 64;
           break;
           case 62: 
                  textureLocation.x = 386;
                  textureLocation.y = 64;
           break;
           case 64: 
                  textureLocation.x = 256;
                  textureLocation.y = 320;
           break;
           case 96:  
                  textureLocation.x = 320;
                  textureLocation.y = 64;
           break;
           case 999: 
                  textureLocation.x = 386;
                  textureLocation.y = 64;
           break;
           
           
           case 129: 
                  textureLocation.x = 128;
                  textureLocation.y = 0;
           break;
          
           
           
           
           
           
           
           
           
           
           
           
           /////////////////////////////////////////////////////
           case 91: //// left 3bite 
                  textureLocation.x = 320; //384;
                  textureLocation.y = 256;///320;
                  t.isFliped = true;
           break;
           case 122: //// left 3bite 
                  textureLocation.x = 320;
                  textureLocation.y = 256;
           break;
           case 126: ///left 2 bite
                  textureLocation.x = 384;
                  textureLocation.y = 256;
           break;
           
           
           case 219: ///right 2bite
                  textureLocation.x = 448;
                  textureLocation.y = 192;
           break;
           
           case 95: 
                  textureLocation.x = 64;
                  textureLocation.y = 192;
           break;
           
           case 250: /////top 2bite
                  textureLocation.x = 64;
                  textureLocation.y = 320;
           break;
           case 127: ///////bootom left bite
                  textureLocation.x = 448;
                  textureLocation.y = 256;
           break;
           
           case 223:////bottom right bite
                  textureLocation.x = 0;
                  textureLocation.y = 256;
           break;
           case 254:    ////top left bite
                  textureLocation.x = 192;
                  textureLocation.y = 320;
           break;
           case 251:  ////top right bite
                  textureLocation.x = 128;
                  textureLocation.y = 320;
           break;
           case 118:  /////left middle
                  textureLocation.x = 192;
                  textureLocation.y = 256;
           break;
           case 248:  ////top middle
                  textureLocation.x = 0;
                  textureLocation.y = 320;
           break;
           case 203: /////right middle
                  textureLocation.x = 256;
                  textureLocation.y = 192;
           break;
           case 31: ////bottom middle 
                  textureLocation.x = 256;
                  textureLocation.y = 64;
           break;
           
           case 112: /////top left corner
                  textureLocation.x = 64;
                  textureLocation.y = 256;
           break;
           case 200: /////top right corner
                  textureLocation.x = 128;
                  textureLocation.y = 192;
           break;
           case 11: ///////bttom right corner
                  textureLocation.x = 256;
                  textureLocation.y = 0;
                  
           break;
           case 22: ///////bttom left corner
                  textureLocation.x = 448;
                  textureLocation.y = 0;
                  
           break;
           case 170: //////four points
                  textureLocation.x = 386;
                  textureLocation.y = 128;
           break;
           case 128://////  => 
                  textureLocation.x = 128;
                  textureLocation.y = 0;
           break;
           case 2://///// ||
                  /////// U 
                  textureLocation.x = 64;
                  textureLocation.y = 0;
           break;
            case 10: ////bottom left elbow
                  textureLocation.x = 196;
                  textureLocation.y = 0;
           break;
           case 66:  //////vertical pipe
                  textureLocation.x = 386;
                  textureLocation.y = 64;
           break;
           //default:
                //  textureLocation.x = 0;
                 // textureLocation.y = 0;
           break;
           case 72:///top right elbow 
                  textureLocation.x = 448;
                  textureLocation.y = 64;
           break;
           case 24:////horizontal pipe
                  textureLocation.x = 0;
                  textureLocation.y = 64;
           break; 
           case 18://///bottom right elbow 
                  textureLocation.x = 386;
                  textureLocation.y = 0;
           break;
           case 1:///////ball 
                  textureLocation.x = 256;
                  textureLocation.y = 320;
           break;
           case 80://// top left elbow
                  textureLocation.x = 128;
                  textureLocation.y = 128;
           break;
           case 8://///  C==
                  textureLocation.x = 320;
                  textureLocation.y = 0;
           break;
           case 32:///////   ^
                   ///////  ||
                  textureLocation.x = 320;
                  textureLocation.y = 64;
           break;

        }
           std::cout<< value;
           std::cout<< ","; 
           return textureLocation;

   }

       }
       


 
