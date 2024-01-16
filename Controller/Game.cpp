
#include <SFML/Graphics.hpp>
#include "Game.hpp"

using namespace controllers;

// Controllers 
Game::Game()
{
   this->CWindow = new sf::RenderWindow(sf::VideoMode(600, 300), "Josiah Kurt B. Aviso");

   sf::Texture CTexture;
   if(!CTexture.loadFromFile("View/Image/persona.png")){

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
         case sf::Event::Closed:
            this->bCloseWindow = true;
            
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
};

void Game::render(){
   this->CWindow->clear();
   // this->CWindow->draw(this->CEntity);
   this->CWindow->display();
};
