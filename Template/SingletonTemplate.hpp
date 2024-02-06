
#ifndef SINGLETON_TEMPLATE_H
#define SINGLETON_TEMPLATE_H

namespace templates{
    class SingletonTemplate {

        /* * * * * * * * * * * * *
        *   SINGLETON CONTENT   *
        * * * * * * * * * * * * */
        private :
            static SingletonTemplate* P_SHARED_INSTANCE;

        private :
            SingletonTemplate();
            SingletonTemplate(const SingletonTemplate&);
            SingletonTemplate& operator = (const SingletonTemplate&);

        public :
            static SingletonTemplate* getInstance();

    }
}

#endif