#include "Ship.hpp"

using namespace entities;
using namespace components;

Ship::Ship(std::string strName, AnimatedTexture* pTexture) : 
    GameObject(strName, pTexture),
    CNormalColor(0, 0, 0, 255){}

void Ship::initialize(){
    this->centerOrigin();
    this->pSprite->setColor(this->CNormalColor);
    this->pSprite->setPosition(90.f, 210.f);

    this->attachComponent(new ShipInput(this->strName + "Input"));
    this->attachComponent(new ShipControls(this->strName + "Movement"));
    this->attachComponent(new Renderer(this->strName + "Renderer"));

    ((Renderer*)this->findComponentByName(this->strName + "Renderer"))->assignDrawable(this->pSprite);
};

bool Ship::isTopBounds(){
    return true;
};

bool Ship::isBottomBounds(){
    return true;    
};

bool Ship::isLeftBounds(){
    return true;
};

bool Ship::isRightBounds(){
    return true;
};
