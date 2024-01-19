
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace controllers;

// Constructors 
Game::Game() : 
   CWindow(sf::VideoMode(1800, 900), "Josiah Kurt B. Aviso")
{
   // this->CWindow = new sf::RenderWindow(sf::VideoMode(1800, 900), "Josiah Kurt B. Aviso");
   
   sf::Texture CTexture;
   if(!CTexture.loadFromFile("View/Image/persona.png")){
      std::cout << "Error loading texture" << std::endl;
   }

   this->CEntity.setTexture(CTexture);
};

// Methods
void Game::run(){
   while(this->CWindow.isOpen()){
      this->processEvents();

      this->update();

      this->render();
   }
};

void Game::processEvents(){
   sf::Event CEvent;
   while (this->CWindow.pollEvent(CEvent)) {
      switch(CEvent.type){
         case sf::Event::Closed :
            this->bCloseWindow = true;
            break;

         case sf::Event::KeyPressed :
            processKeyboardInput(CEvent.key.code, true);
            break;

         case sf::Event::KeyReleased :
            processKeyboardInput(CEvent.key.code, false);
            break;

         default:
            break;
      }
   }
};

void Game::update(){
   if(bCloseWindow){
      bCloseWindow = false;
      CWindow.close();
   }

   CEntity.updatePosition();
};

void Game::render(){
   this->CWindow.clear();
   this->CWindow.draw(*(CEntity.getSprite()));
   this->CWindow.display();
};

void Game::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){

   switch (CKey) {
      case sf::Keyboard::W :
         CEntity.setUpFlag(isPressed);
         break;
      case sf::Keyboard::A :
         CEntity.setLeftFlag(isPressed);
         break;
      case sf::Keyboard::S :
         CEntity.setDownFlag(isPressed);
         break;
      case sf::Keyboard::D :
         CEntity.setRightFlag(isPressed);
         break;
      default :
         break;
   }


}