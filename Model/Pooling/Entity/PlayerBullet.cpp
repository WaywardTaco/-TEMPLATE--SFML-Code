
#include "PlayerBullet.hpp"

using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip) : 
    PoolableObject(PoolTag::PLAYER_BULLET, strName, pTexture),
    pShip(pShip){}

void PlayerBullet::initialize(){
    this->attachComponent(new BulletMovement(this->getName() + "Movement"));

    Renderer* pRenderer = new Renderer(this->getName() + "Renderer");
    pRenderer->assignDrawable(this->getSprite());
    this->attachComponent(pRenderer);      
}

void PlayerBullet::onActivate(){
    this->pSprite->setPosition(this->pShip->getSprite()->getPosition());
}

void PlayerBullet::onRelease(){

}

PoolableObject* PlayerBullet::clone(){
    return (PoolableObject*) new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);
}
