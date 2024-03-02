#include "Background.hpp"

using namespace entities;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject (strName, pTexture) {}

void Background::initialize(){
    Renderer* pRenderer = new Renderer(this->getName() + "Renderer");
    pRenderer->assignDrawable(this->getSprite());
    this->attachComponent(pRenderer);

    this->attachComponent(new BackgroundInput(this->getName() + "Input"));
    this->attachComponent(new BackgroundAction(this->getName() + "Action"));
};
