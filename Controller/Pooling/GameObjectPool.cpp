
#include "GameObjectPool.hpp"

using namespace poolables;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference) :
    ETag(ETag), nPoolSize(nPoolSize), pPoolableReference(pPoolableReference),
    vecAvailableObject({}), vecUsedObject({}){}

void GameObjectPool::initialize(){
    for(int i = 0; i < this->nPoolSize; i++){
        PoolableObject* pClone = this->pPoolableReference->clone();
        GameObjectManager::getInstance()->addObject(pClone);
        pClone->setEnabled(false);
        this->vecAvailableObject.push_back(pClone);
    }
}

PoolableObject* GameObjectPool::requestPoolable(){
    if(!this->hasAvailable(1))
        return NULL;

    PoolableObject* pObject = this->vecAvailableObject.back();

    this->vecAvailableObject.pop_back();
    this->vecUsedObject.push_back(pObject);

    this->setEnabled(pObject, true);

    return pObject;
}

std::vector<PoolableObject*> GameObjectPool::requestPoolableBatch(int nRequestSize){
    std::vector<PoolableObject*> vecOutput = {};
    if(!this->hasAvailable(nRequestSize))
        return vecOutput;

    for(int i = 0; i < nRequestSize; i++){
        PoolableObject* pObject = this->vecAvailableObject.back();

        this->vecAvailableObject.pop_back();
        this->vecUsedObject.push_back(pObject);
        vecOutput.push_back(pObject);

        this->setEnabled(pObject, true);
    }

    return vecOutput;
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject){
    int nIndex = -1;
    int length = this->vecUsedObject.size();
    for(int i = 0; i < length; i++)
        if(this->vecUsedObject[i] == pPoolableObject){
            nIndex = i;
            break;
        }

    if(nIndex == -1)
        return;

    this->vecAvailableObject.push_back(this->vecUsedObject[nIndex]);
    this->vecUsedObject.erase(this->vecUsedObject.begin() + nIndex);

    this->setEnabled(pPoolableObject, false);
}

void GameObjectPool::releasePoolableBatch(std::vector<PoolableObject*> vecPoolableObject){
    int nLength = vecPoolableObject.size();
    for(int i = 0; i < nLength; i++){
        int nIndex = -1;
        int length = this->vecUsedObject.size();
        for(int j = 0; j < length; j++)
            if(this->vecUsedObject[j] == vecPoolableObject[i]){
                nIndex = j;
                break;
            }

        if(nIndex == -1)
            continue;

        this->vecAvailableObject.push_back(this->vecUsedObject[nIndex]);
        this->vecUsedObject.erase(this->vecUsedObject.begin() + nIndex);

        this->setEnabled(vecPoolableObject[i], false);
    }

    vecPoolableObject.clear();
}

bool GameObjectPool::hasAvailable(int nRequestSize){
    return (this->vecAvailableObject.size() >= nRequestSize);
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnable){
    pPoolableObject->setEnabled(bEnable);
    if(bEnable)
        pPoolableObject->onActivate();
    else
        pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag(){
    return this->ETag;
}