
#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName) : GameObject(strName, 300.0f) {
    this->fXpos = 0.f;
    this->fYpos = 0.f;
};

void Player::updatePosition(float fElapsedTime){
    float
        fXchange = bMovingRight - bMovingLeft,
        fYchange = bMovingUp - bMovingDown,
        fMagnitudeChange = 0.0
    ;

    fMagnitudeChange = std::sqrt(fXchange*fXchange + fYchange*fYchange);
    fXchange /= fMagnitudeChange;
    fYchange /= fMagnitudeChange;
    
    if(fMagnitudeChange != 0){
        this->fXpos += fXchange * this->fSpeed * fElapsedTime;
        this->fYpos -= fYchange * this->fSpeed * fElapsedTime;
    }

    this->pSprite->setPosition(this->fXpos, this->fYpos);
};

bool Player::getMovingUp(){
    return this->bMovingUp;
};

void Player::setMovingUp(bool bMovingUp){
    this->bMovingUp = bMovingUp;
};

bool Player::getMovingDown(){
    return this->bMovingDown;
};

void Player::setMovingDown(bool bMovingDown){
    this->bMovingDown = bMovingDown;
};

bool Player::getMovingLeft(){
    return this->bMovingLeft;
};
    
void Player::setMovingLeft(bool bMovingLeft){
    this->bMovingLeft = bMovingLeft;
};
    
bool Player::getMovingRight(){
    return this->bMovingLeft;
};

void Player::setMovingRight(bool bMovingRight){
    this->bMovingRight = bMovingRight;
}; 