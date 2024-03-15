
#include "GameScene.hpp"

using namespace scenes;

GameScene::GameScene() 
    : Scene(SceneTag::GAME_SCENE) 
{

}

void GameScene::onLoadResources(){
    TextureManager::getInstance()->loadGame();
};

void GameScene::onLoadObjects(){
    this->createBackground();
    this->createShip();
    this->createObjectPools();
};

void GameScene::onUnloadResources(){
    TextureManager::getInstance()->clearAll();
};

void GameScene::createBackground(){
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GAME_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);   
}

void GameScene::createShip(){
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Ship* pPlayer = new Ship("Ship", pTexture);
    this->registerObject(pPlayer);
}

void GameScene::createObjectPools(){
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER_BULLET));
    PlayerBullet* pBullet = new PlayerBullet("PlayerBullet", pTexture, (Ship*) GameObjectManager::getInstance()->findObjectByName("Ship"));
    
    GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET, 3, pBullet);
    pBulletPool->initialize();

    ObjectPoolManager::getInstance()->registerObjectPool(pBulletPool);

}