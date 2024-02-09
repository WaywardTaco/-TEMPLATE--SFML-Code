
#include "Game.hpp"

using namespace controllers;

// Constructors 
Game::Game() : 
   CWindow(sf::VideoMode(1800, 900), "Josiah Kurt B. Aviso"),
   bCloseWindow(false)
{
   TextureManager::getInstance()->loadAll();

   Player* pEntity = new Player("Player");
   GameObjectManager::getInstance()->addObject(pEntity);

   std::vector<sf::Texture*> mapPlayerTexture = TextureManager::getInstance()->getTexture(AssetType::PLAYER);

   GameObjectManager::getInstance()->findObjectByName("Player")->setTexture(mapPlayerTexture[0]);   


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
         default :
            GameObjectManager::getInstance()->processEvents(CEvent);
            break;
      }
   }
};

void Game::update(sf::Time tDeltaTime){
   if(bCloseWindow){
      bCloseWindow = false;
      CWindow.close();
   }

   GameObjectManager::getInstance()->update(tDeltaTime);
};

void Game::render(){
   this->CWindow.clear();
   GameObjectManager::getInstance()->draw(&this->CWindow);
   this->CWindow.display();
};
