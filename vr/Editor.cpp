#include <SFML/Graphics.hpp>
#include "Editor.h"
#include <iostream>

namespace mine{
     Editor::Editor(){
             font.loadFromFile("arial.ttf");  
             editorView.setCenter(sf::Vector2f(640,392));
             editorView.setSize(sf::Vector2f(1600,778)); 
             TileSet.loadFromFile("ts.png");
             toggleGrid = true;
             hasFocus = false;
             layer2 = false;
             drawingTerrain = true;
             TileWidth = 64;
             

    }
    void Editor::setup(sf::Vector2u screenSize){

        //////creating editor grid////////
          for(int i = 0; i <100 ; i++){
              
               for(int j = 0; j <100; j++){
              Tile *tile = new Tile;
              tile ->x = i*TileWidth;
              tile ->y = j*TileWidth;
              tile->tileType = 0;
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
            
            
         if(layer2){
           for(it = UImap.begin(); it!= UImap.end();++it){
                 tileHitBox.setPosition(sf::Vector2f(it->x,it->y));
                
                if(hasFocus && tileHitBox.getGlobalBounds().contains(myPosUI.x,myPosUI.y)){
                   
                   rectSourceSpritetemp.left =  tileHitBox.getGlobalBounds().left;

                   rectSourceSpritetemp.top =  tileHitBox.getGlobalBounds().top;
                   position.setTextureRect(rectSourceSpritetemp);
                  
                  std::cout<<",";
                  
                   
                }
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
        

         if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  

              
                

           for(it = map.begin(); it!= map.end();++it){
              
                 tileHitBox.setPosition(sf::Vector2f(it->x,it->y));
                
                if(!hasFocus && tileHitBox.getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                    if(drawingTerrain){
                     if(it->tileType == 0){ 
                      it->textureLeft = 0;
                      it->textureTop = 0;
                      it->tileType = 1;}

                      if(it->tileType==1 && layer2){
                      it->textureLeft = rectSourceSpritetemp.left;
                      it->textureTop = rectSourceSpritetemp.top;

                    }
                    }
                    else if(!drawingTerrain){
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
                      rectSourceSprite.top  = 0;
                      rectSourceSprite.left = 0;
                      position.setTextureRect(rectSourceSprite);
                      it->render(target,position);
                      
                      rectSourceSprite.top  = it->textureTop;
                      rectSourceSprite.left = it->textureLeft;
                      position.setTextureRect(rectSourceSprite);
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

       }
       


 