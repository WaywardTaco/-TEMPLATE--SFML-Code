#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->pTexture = pTexture;
    this->pSprite = new sf::Sprite();

    if(this->pTexture != NULL)
        this->pSprite->setTexture(*this->pTexture->getFrame());
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

void GameObject::centerOrigin(){
    if(this->pTexture != NULL){
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;

        this->pSprite->setOrigin(nWidth / 2, nHeight / 2);
    }
}

void GameObject::setEnabled(bool bEnabled){
    this->bEnabled = bEnabled;
}

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
    if(this->pTexture != NULL){
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame());
    };
};
