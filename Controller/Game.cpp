
#include "Game.hpp"

using namespace controllers;
 
Game::Game() : 
   CWindow(sf::VideoMode(800, 440), "Josiah Kurt B. Aviso"),
   bCloseWindow(false)
{
   SceneManager::getInstance()->registerScene(new MainMenuScene());
   SceneManager::getInstance()->registerScene(new GameScene());
   // SceneManager::getInstance()->registerScene(new ResultScene());

   SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
};

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

      SceneManager::getInstance()->checkLoadScene();
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
         default :
            GameObjectManager::getInstance()->processEvents(CEvent);
            break;
      }
   }
};

void Game::update(sf::Time tDeltaTime){
   if(bCloseWindow)
      CWindow.close();

   GameObjectManager::getInstance()->update(tDeltaTime);
};

void Game::render(){
   this->CWindow.clear();
   GameObjectManager::getInstance()->draw(&this->CWindow);
   this->CWindow.display();
};
