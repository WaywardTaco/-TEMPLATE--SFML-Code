#include <cmath>
#include <iostream>
#include "GameObject.hpp"

using namespace models;

// Constructors
GameObject::GameObject(){
    
};

// Methods
void GameObject::renderTo(sf::RenderWindow* CWindow){
    CWindow->draw(this->imgSprite);
};

void GameObject::updatePosition(){
    float
        fXchange = bRightFlag - bLeftFlag,
        fYchange = bUpFlag - bDownFlag,
        fMagnitudeChange = 0.0
    ;

    fMagnitudeChange = std::sqrt(fXchange*fXchange + fYchange*fYchange);
    fXchange /= fMagnitudeChange;
    fYchange /= fMagnitudeChange;
    
    if(fMagnitudeChange != 0){
        // std::cout << fXchange * this->fSpeed << ", " << fYchange * this->fSpeed << std::endl;
        this->fXpos += fXchange * this->fSpeed;
        this->fYpos -= fYchange * this->fSpeed;
    }

    this->imgSprite.setPosition(this->fXpos, this->fYpos);
};

// Getters & Setters
void GameObject::setTexture(sf::Texture CTexture_param){
    this->CTexture = CTexture_param;
    this->imgSprite.setTexture(this->CTexture);
};

void GameObject::setUpFlag(bool bValue){
    this->bUpFlag = bValue;
};

void GameObject::setDownFlag(bool bValue){
    this->bDownFlag = bValue;
};

void GameObject::setLeftFlag(bool bValue){
    this->bLeftFlag = bValue;
};

void GameObject::setRightFlag(bool bValue){
    this->bRightFlag = bValue;
};

sf::Sprite* GameObject::getSprite(){
    return &(this->imgSprite);
};