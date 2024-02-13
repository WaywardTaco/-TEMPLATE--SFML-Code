#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, float fSpeed) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
}

GameObject::GameObject(std::string strName, float fSpeed, AnimatedTexture* pAnimatedTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pAnimatedTexture = pAnimatedTexture;
    this->pSprite = new sf::Sprite();

    if(this->pAnimatedTexture != NULL)
        this->pSprite->setTexture(*this->pAnimatedTexture->getFrame());
}

/* [TODO][2] */
void GameObject::processEvents(sf::Event CEvent){
    switch(CEvent.type){
        case sf::Event::KeyPressed :
            this->processKeyboardInput(CEvent.key.code, true);
            break;

        case sf::Event::KeyReleased :
            this->processKeyboardInput(CEvent.key.code, false);
            break;
    }
};

void GameObject::draw(sf::RenderWindow* pWindow){
    pWindow->draw(*this->pSprite);
};

bool GameObject::getEnabled() {
    return this->bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

void GameObject::setFrame(int nFrame){
    if(this->pAnimatedTexture != NULL){
        this->pAnimatedTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pAnimatedTexture->getFrame());
    };
};

void GameObject::setTexture(sf::Texture* pTexture) {
    this->pTexture = pTexture;
    this->pSprite->setTexture(*this->pTexture);
}

float GameObject::getSpeed() {
    return this->fSpeed;
}
