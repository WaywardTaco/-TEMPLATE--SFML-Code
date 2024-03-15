#pragma once

#include <SFML/Graphics.hpp>

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
            AnimatedTexture* pTexture;
            std::vector<Component*> vecComponents;

        public:
            GameObject(std::string strName, AnimatedTexture* pTexture);
        
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
            void centerOrigin();

        public:
            bool getEnabled();
            void setEnabled(bool bEnabled);
            std::string getName();
            sf::Sprite* getSprite();
            void setFrame(int nFrame);
    };
}
