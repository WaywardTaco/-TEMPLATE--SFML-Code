
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace controllers;

// Constructors 
Game::Game() : 
   CWindow(sf::VideoMode(1800, 900), "Josiah Kurt B. Aviso"),
   bCloseWindow(false)
{
   
   sf::Texture CTexture;
   if(!CTexture.loadFromFile("View/Image/persona.png")){
      std::cout << "Error loading texture" << std::endl;
   }

   this->CEntity.setTexture(CTexture);   
};

// Methods
void Game::run(){
   sf::Clock CClock;
   sf::Time 
      tTimePerFrame = sf::seconds(1.f / 60.f),
      tTimeSinceLastUpdate = sf::Time::Zero
   ;

   this->CWindow.setFramerateLimit(60.f);
            
   while(this->CWindow.isOpen()){
      tTimeSinceLastUpdate += CClock.restart();

      while(tTimeSinceLastUpdate > tTimePerFrame){
         tTimeSinceLastUpdate -= tTimePerFrame;

         this->processEvents();
         this->update(tTimePerFrame);
      }

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

void Game::update(sf::Time tDeltaTime){
   if(bCloseWindow){
      bCloseWindow = false;
      CWindow.close();
   }

   this->CEntity.updatePosition(tDeltaTime.asSeconds());
};

void Game::render(){
   this->CWindow.clear();
   this->CWindow.draw(*(CEntity.getSprite()));
   this->CWindow.display();
};

void Game::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){

   switch (CKey) {
      case sf::Keyboard::W :
         this->CEntity.setMovingUp(isPressed);
         break;
      case sf::Keyboard::A :
         this->CEntity.setMovingLeft(isPressed);
         break;
      case sf::Keyboard::S :
         this->CEntity.setMovingDown(isPressed);
         break;
      case sf::Keyboard::D :
         this->CEntity.setMovingRight(isPressed);
         break;
      default :
         break;
   }


}