#pragma once

#include "AnimatedTexture.hpp"
#include "Component/Component.hpp"
#include "Enum/ComponentType.hpp"

namespace models {
    using namespace components;
    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            AnimatedTexture* pAnimatedTexture;
            std::vector<Component*> vecComponents;
            sf::Texture* pTexture;
            float fSpeed;

        public:
            // GameObject(std::string strName, float fSpeed);
            GameObject(std::string strName, float fSpeed, AnimatedTexture* pAnimatedTexture);
        
        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltaTime) = 0;
            virtual void draw(sf::RenderWindow* pWindow);

        // protected:
        //     virtual void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed) = 0;
        public:
            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            Component* findComponentByName(std::string strName);
            std::vector<Component*> getComponents(ComponentType EType);

        public:
            bool getEnabled();
            std::string getName();
            sf::Sprite* getSprite();
            void setFrame(int nFrame);
            void setTexture(sf::Texture* pTexture);
            float getSpeed();
    };
}
