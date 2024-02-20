
#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../Component.hpp"

namespace renderers {
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


    };
}