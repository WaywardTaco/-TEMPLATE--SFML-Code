#include "Player.hpp"

using namespace entities;
using namespace components;

Player::Player(std::string strName, AnimatedTexture* pAnimatedTexture) 
    : GameObject(strName, pAnimatedTexture) {}

void Player::initialize(){
    this->pSprite->setPosition(100.f, 100.f);

    this->attachComponent(new PlayerInput(this->strName + "Input"));
    this->attachComponent(new PlayerMovement(this->strName + "Movement"));
    this->attachComponent(new Renderer(this->strName + "Renderer"));

    ((Renderer*)this->findComponentByName(this->strName + "Renderer"))->assignDrawable(this->pSprite);
};