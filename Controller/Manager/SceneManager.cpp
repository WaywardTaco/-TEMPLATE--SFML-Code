#include "SceneManager.hpp"

using namespace managers;

void SceneManager::registerScene(Scene* pScene){
    this->mapScenes[pScene->getTag()] = pScene; 
};

void SceneManager::loadScene(SceneTag ETag){
    this->bLoading = true;
    this->ESceneToLoad = ETag;
};

void SceneManager::unloadScene(){  
    if(this->pActiveScene != NULL){
        this->pActiveScene->onUnloadObjects();
        this->pActiveScene->onUnloadResources();
    }
};

void SceneManager::checkLoadScene(){
    if(this->bLoading){
        this->unloadScene();
        this->pActiveScene = this->mapScenes[this->ESceneToLoad];
        this->pActiveScene->onLoadResources();
        this->pActiveScene->onLoadObjects();
        this->bLoading = false;
    }
};

bool SceneManager::getLoaded(SceneTag ETag){
    return (ETag == this->pActiveScene->getTag());
};

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
SceneManager* SceneManager::P_SHARED_INSTANCE = NULL;
SceneManager::SceneManager()
 : pActiveScene(NULL), bLoading(false){}
SceneManager::SceneManager(const SceneManager&) {}

SceneManager* SceneManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new SceneManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
