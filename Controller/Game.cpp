
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace controllers;

// Constructors 
Game::Game()
{
   this->CWindow = new sf::RenderWindow(sf::VideoMode(1800, 900), "Josiah Kurt B. Aviso");
   
   sf::Texture CTexture;
   if(!CTexture.loadFromFile("View/Image/persona.png")){
      std::cout << "Error" << std::endl;
   }
   else {
      this->CEntity = new GameObject(CTexture);
   }
};

// Methods
void Game::run(){
   while(this->CWindow->isOpen()){
      this->processEvents();

      this->update();

      this->render();
   }
};

void Game::processEvents(){
   sf::Event CEvent;
   while (this->CWindow->pollEvent(CEvent)) {
      switch(CEvent.type){
         case sf::Event::Closed :
            this->bCloseWindow = true;
            
            break;

         case sf::Event::KeyPressed :
            switch (CEvent.key.code) {
               case sf::Keyboard::W :
                  CEntity->setUpFlag(true);
                  break;
               case sf::Keyboard::A :
                  CEntity->setLeftFlag(true);
                  break;
               case sf::Keyboard::S :
                  CEntity->setDownFlag(true);
                  break;
               case sf::Keyboard::D :
                  CEntity->setRightFlag(true);
                  break;
            }
            break;

         case sf::Event::KeyReleased :
            switch (CEvent.key.code) {
               case sf::Keyboard::W :
                  CEntity->setUpFlag(false);
                  break;
               case sf::Keyboard::A :
                  CEntity->setLeftFlag(false);
                  break;
               case sf::Keyboard::S :
                  CEntity->setDownFlag(false);
                  break;
               case sf::Keyboard::D :
                  CEntity->setRightFlag(false);
                  break;
            }
            break;

         default:
            break;
      }
   }
};

void Game::update(){
   if(bCloseWindow){
      bCloseWindow = false;
      CWindow->close();
   }

   CEntity->updatePosition();
};

void Game::render(){
   this->CWindow->clear();
   this->CEntity->renderTo(this->CWindow);
   this->CWindow->display();
};
