#include "GameObject.hpp"

using namespace models;

// Constructors
GameObject::GameObject(){
    
};

// Methods
void GameObject::render(){

};

// Getters & Setters
void GameObject::setTexture(sf::Texture CTexture_param){
    this->CTexture = CTexture_param;
};

sf::Sprite* GameObject::getSprite(){
    return &(this->imgSprite);
};