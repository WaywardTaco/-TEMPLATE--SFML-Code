
#include <SFML/Graphics.hpp>
#include "Game.hpp"

using namespace controllers;

// Controllers 
Game::Game(){

};

// Methods
void Game::run(){
   sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Start-Up");
   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Blue);

   while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
         if (event.type == sf::Event::Closed)
            window.close();
      }

      window.clear();
      window.draw(shape);
      window.display();
   }

};

void Game::processEvents(){

};

void Game::update(){

};

void Game::render(){

};