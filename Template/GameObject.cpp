#include <cmath>
#include <iostream>
#include "GameObject.hpp"

using namespace models;

// Constructors
GameObject::GameObject() : 
    fXpos(0.f),
    fYpos(0.f),
    fSpeed(1500.f),
    bMovingUp(false),
    bMovingDown(false),
    bMovingLeft(false),
    bMovingRight(false)
{

};

// Methods
void GameObject::renderTo(sf::RenderWindow* CWindow){
    CWindow->draw(this->imgSprite);
};

void GameObject::updatePosition(float fElapsedTime){
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

    this->imgSprite.setPosition(this->fXpos, this->fYpos);
};

// Getters & Setters
void GameObject::setTexture(sf::Texture CTexture_param){
    this->CTexture = CTexture_param;
    this->imgSprite.setTexture(this->CTexture);
};

sf::Sprite* GameObject::getSprite(){
    return &(this->imgSprite);
};

float GameObject::getSpeed(){
    return this->fSpeed;
}

bool GameObject::getMovingUp(){
    return this->bMovingUp;
};
void GameObject::setMovingUp(bool bMovingUp){
    this->bMovingUp = bMovingUp;
};

bool GameObject::getMovingDown(){
    return this->bMovingDown;
};
void GameObject::setMovingDown(bool bMovingDown){
    this->bMovingDown = bMovingDown;
};

bool GameObject::getMovingLeft(){
    return this->bMovingLeft;
};
void GameObject::setMovingLeft(bool bMovingLeft){
    this->bMovingLeft = bMovingLeft;
};

bool GameObject::getMovingRight(){
    return this->bMovingRight;
};
void GameObject::setMovingRight(bool bMovingRight){
    this->bMovingRight = bMovingRight;
};