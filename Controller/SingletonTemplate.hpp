
#ifndef SINGLETON_TEMPLATE_H
#define SINGLETON_TEMPLATE_H

namespace controllers{
    class SingletonTemplate {
        public :
            void test();

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