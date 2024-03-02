
#include "TextureManager.hpp"

using namespace managers;

void TextureManager::loadAll(){

    sf::Texture* pTexture;

    std::cout << "Loading all textures..." << std::endl;
    
    pTexture = new sf::Texture();
    if(!pTexture->loadFromFile("View/Image/persona.png"))
        std::cout << "Error loading texture" << std::endl;
    
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

    pTexture = new sf::Texture();
    if(!pTexture->loadFromFile("View/Image/image2.jpg"))
        std::cout << "Error loading texture" << std::endl;
    
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

};

void TextureManager::loadMainMenu(){
    sf::Texture* pTexture = new sf::Texture;
    pTexture->loadFromFile("View/Image/Space Impact/main_menu_background.png");
    this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);
};

void TextureManager::loadGame(){
    sf::Texture* pTexture = new sf::Texture;
    pTexture->loadFromFile("View/Image/Space Impact/game_background.png");
    this->mapTexture[AssetType::GAME_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture;
    pTexture->loadFromFile("View/Image/Space Impact/Player/this_ship_be_otp.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);
};

void TextureManager::clearAll(){
    // for(sf::Texture* pTexture : this->mapTexture)
    //     delete pTexture;

    // this->mapTexture.clear();
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EKey){
    return this->mapTexture[EKey];
};

sf::Texture* TextureManager::getTextureAt(AssetType EKey, int nFrame){
    return this->mapTexture[EKey][nFrame];
};

/* SINGLETON TEMPLATE */
TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager(){};
TextureManager::TextureManager(const TextureManager&){};
TextureManager* TextureManager::getInstance(){
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
};