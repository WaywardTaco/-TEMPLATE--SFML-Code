#include "GameObject.hpp"

using namespace models;

// GameObject::GameObject(std::string strName, float fSpeed) {
//     this->bEnabled = true;
//     this->strName = strName;
//     this->fSpeed = fSpeed;
//     this->pSprite = new sf::Sprite();
// }

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
    // switch(CEvent.type){
    //     case sf::Event::KeyPressed :
    //         this->processKeyboardInput(CEvent.key.code, true);
    //         break;

    //     case sf::Event::KeyReleased :
    //         this->processKeyboardInput(CEvent.key.code, false);
    //         break;
    // }
};

void GameObject::draw(sf::RenderWindow* pWindow){
    pWindow->draw(*this->pSprite);
};

void GameObject::attachComponent(Component* pComponent){
    this->vecComponents.push_back(pComponent);
    pComponent->attachOwner(this);
};

void GameObject::detachComponent(Component* pComponent){
    int nIndex = -1;

    int nComponentCount = this->vecComponents.size();
    for(int i = 0; i < nComponentCount; i++){
        if(pComponent == this->vecComponents[i]){
            nIndex = i;
            break;
        }
    }

    if(nIndex != -1){
        this->vecComponents[nIndex]->detachOwner();
        this->vecComponents.erase(this->vecComponents.begin() + nIndex);
    }
};

Component* GameObject::findComponentByName(std::string strName){
    int nComponentCount = this->vecComponents.size();
    for(int i = 0; i < nComponentCount; i++){
        if(this->vecComponents[i]->getName() == strName)
            return this->vecComponents[i];
    }

    return NULL;
};

std::vector<Component*> GameObject::getComponents(ComponentType EType){
    std::vector<Component*> vecOutput;

    int nComponentCount = this->vecComponents.size();
    for(int i = 0; i < nComponentCount; i++){
        if(this->vecComponents[i]->getType() == EType)
            vecOutput.push_back(this->vecComponents[i]);
    }

    return vecOutput;
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
