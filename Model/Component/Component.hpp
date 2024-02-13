
#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Enum/ComponentType.hpp"
#include "../GameObject.hpp"

namespace components {
    using namespace models;
    class Component {
        protected:
            GameObject* pOwner;
            ComponentType EType;
            std::string strName;
            sf::Time tDeltaTime;
        
        public:
            Component(std::string strName, ComponentType EType);
            virtual ~Component();

        public:
            void attachOwner(GameObject* pOwner);
            void detachOwner();
            virtual void perform() = 0;

        public:
            GameObject* getOwner();
            ComponentType getType();
            std::string getName();
            void setDeltaTime(sf::Time tDeltaTime);
    };

}

#endif