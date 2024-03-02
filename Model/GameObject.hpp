#pragma once

#include "AnimatedTexture.hpp"
#include "Enum/ComponentType.hpp"
#include "Component/Component.hpp"
#include "Component/GeneralInput.hpp"
#include "Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;
    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            AnimatedTexture* pAnimatedTexture;
            std::vector<Component*> vecComponents;

        public:
            GameObject(std::string strName, AnimatedTexture* pAnimatedTexture);
        
        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltaTime);
            virtual void draw(sf::RenderWindow* pWindow);

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
    };
}
