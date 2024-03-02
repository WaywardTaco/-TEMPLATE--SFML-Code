
#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../Component.hpp"
#include <SFML/Graphics.hpp>

namespace components {
    class Renderer : public Component {
        private:
            sf::RenderWindow* pWindow;
            std::vector<sf::Drawable*> vecDrawables;

        public:
            Renderer(std::string strName);

        public:
            void perform();

        public:
            void assignTargetWindow(sf::RenderWindow* pWindow);
            void assignDrawable(sf::Drawable* pDrawable);
            void flip();
    };
}