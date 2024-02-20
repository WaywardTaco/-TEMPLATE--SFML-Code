
#include "Renderer.hpp"

using namespace renderers;

Renderer::Renderer(std::string strName) 
    : Component(strName, ComponentType::RENDERER)
{

};

void Renderer::perform(){
    for(sf::Drawable* pDrawable : this->vecDrawables){
        sf::Sprite* pSprite = (sf::Sprite*) pDrawable;

        this->pWindow->draw(*pSprite);

    }
};

void Renderer::assignTargetWindow(sf::RenderWindow* pWindow){
    this->pWindow = pWindow;
};
void Renderer::assignDrawable(sf::Drawable* pDrawable){
    this->vecDrawables.push_back(pDrawable);
};
