
#include "SingletonTemplate.hpp"

using namespace templates;

/* * * * * * * * * * * * *
 *   SINGLETON CONTENT   *
 * * * * * * * * * * * * */
SingletonTemplate* SingletonTemplate::P_SHARED_INSTANCE = NULL;
            
SingletonTemplate::SingletonTemplate(){};
SingletonTemplate::SingletonTemplate(const SingletonTemplate&){};
static SingletonTemplate::SingletonTemplate* getInstance(){
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new SingletonTemplate();

    return P_SHARED_INSTANCE;

};

