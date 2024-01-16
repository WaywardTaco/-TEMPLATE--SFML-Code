#include "GameObject.hpp"

using namespace models;

// Constructors
GameObject::GameObject(sf::Texture CTexture){
    this->setTexture(CTexture);
};

// Methods
void GameObject::renderTo(sf::RenderWindow* CWindow){
    CWindow->draw(this->imgSprite);
};

// Getters & Setters
void GameObject::setTexture(sf::Texture CTexture_param){
    this->CTexture = CTexture_param;
    this->imgSprite.setTexture(this->CTexture);
};

sf::Sprite* GameObject::getSprite(){
    return &(this->imgSprite);
};