
#include "Component.hpp"

using namespace components;

Component::Component(std::string strName, ComponentType EType){
    this->strName = strName;
    this->EType = EType;
    this->pOwner = NULL;
};

Component::~Component(){

};

void Component::attachOwner(GameObject* pOwner){
    this->pOwner = pOwner;
};

void Component::detachOwner(){
    this->pOwner = NULL;
};

GameObject* Component::getOwner(){
    return this->pOwner;
};

ComponentType Component::getType(){
    return this->EType;
};

std::string Component::getName(){
    return this->strName;
};

void Component::setDeltaTime(sf::Time tDeltaTime){
    this->tDeltaTime = tDeltaTime;
};
