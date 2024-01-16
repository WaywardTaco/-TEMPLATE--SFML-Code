
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace controllers;

// Constructors 
Game::Game()
{
   this->CWindow = new sf::RenderWindow(sf::VideoMode(600, 300), "Josiah Kurt B. Aviso");
   
   sf::Texture CTexture;
   if(!CTexture.loadFromFile("persona.png")){
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
   this->CEntity->renderTo(this->CWindow);
   this->CWindow->display();
};
