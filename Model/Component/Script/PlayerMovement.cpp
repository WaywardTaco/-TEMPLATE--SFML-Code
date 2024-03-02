
#include "PlayerMovement.hpp"

using namespace components;

PlayerMovement::PlayerMovement(std::string strName) 
    : Component(strName, ComponentType::SCRIPT),
    fSpeed(300.f)
{

};

void PlayerMovement::perform(){
    PlayerInput* pPlayerInput = (PlayerInput*) this->getOwner()->findComponentByName(this->getOwner()->getName() + "Input");
    sf::Sprite* pSprite = this->getOwner()->getSprite();

    if(pPlayerInput == NULL || pSprite == NULL){
        std::cout << "[ERROR] : One or more dependencies missing!" << std::endl;
        return;
    }

    if(pPlayerInput->getMovingLeft())
        pSprite->move(-1.f * this->fSpeed * this->tDeltaTime.asSeconds(), 0.f);
    
    if(pPlayerInput->getMovingRight())
        pSprite->move(1.f * this->fSpeed * this->tDeltaTime.asSeconds(), 0.f);
    
    if(pPlayerInput->getMovingUp())
        pSprite->move(0.f, -1.f * this->fSpeed * this->tDeltaTime.asSeconds());
    
    if(pPlayerInput->getMovingDown())
        pSprite->move(0.f, 1.f * this->fSpeed * this->tDeltaTime.asSeconds());  
};