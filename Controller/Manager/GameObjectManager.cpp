#include "GameObjectManager.hpp"

using namespace managers;

void GameObjectManager::processEvents(sf::Event CEvent) {
    for(GameObject* pGameObject : this->vecGameObjects)
        if(pGameObject->getEnabled())
            pGameObject->processEvents(CEvent);
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    for(GameObject* pGameObject : this->vecGameObjects)
        if(pGameObject->getEnabled())
            pGameObject->update(tDeltaTime);
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    for(GameObject* pGameObject : this->vecGameObjects)
        if(pGameObject->getEnabled())
            pGameObject->draw(pWindow);
}

void GameObjectManager::addObject(GameObject* pGameObject) {
    this->mapGameObjects[pGameObject->getName()] = pGameObject;
    this->vecGameObjects.push_back(pGameObject);
    pGameObject->initialize();
}

GameObject* GameObjectManager::findObjectByName(std::string strName) {
    if(this->mapGameObjects[strName] != NULL)
        return this->mapGameObjects[strName];
    else {
        std::cout << "[ERROR] : Object [" << strName << "] NOT found." << std::endl;
        return NULL;
    }
}

void GameObjectManager::deleteAllObjects(){
    for(GameObject* pGameObject : this->vecGameObjects)
        delete pGameObject;
    
    this->vecGameObjects.clear();
    this->mapGameObjects.clear();
}

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */

/* [TODO][2] */
GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;
GameObjectManager::GameObjectManager(){};
GameObjectManager::GameObjectManager(const GameObjectManager&){};
GameObjectManager* GameObjectManager::getInstance(){
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new GameObjectManager();
    
    return P_SHARED_INSTANCE;
};


