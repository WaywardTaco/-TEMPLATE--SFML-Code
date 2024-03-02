#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pAnimatedTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->pAnimatedTexture = pAnimatedTexture;
    this->pSprite = new sf::Sprite();

    if(this->pAnimatedTexture != NULL)
        this->pSprite->setTexture(*this->pAnimatedTexture->getFrame());
}

void GameObject::processEvents(sf::Event CEvent){
    std::vector<Component*> vecInputs = this->getComponents(ComponentType::INPUT);

    for(Component* pComponent : vecInputs){
        GeneralInput* pGeneralInput = (GeneralInput*)pComponent;

        pGeneralInput->assignEvent(CEvent);
        pGeneralInput->perform();
    }
};

void GameObject::update(sf::Time tDeltaTime){
    std::vector<Component*> vecScripts = this->getComponents(ComponentType::SCRIPT);

    for(Component* pComponent : vecScripts){
        pComponent->setDeltaTime(tDeltaTime);
        pComponent->perform();
    }
};

void GameObject::draw(sf::RenderWindow* pWindow){
    std::vector<Component*> vecRenderers = this->getComponents(ComponentType::RENDERER);

    for(Component* pComponent : vecRenderers){
        Renderer* pRenderer = (Renderer*)pComponent;

        pRenderer->assignTargetWindow(pWindow);
        pRenderer->perform();
    }
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
    std::vector<Component*> vecOutput = {};

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
