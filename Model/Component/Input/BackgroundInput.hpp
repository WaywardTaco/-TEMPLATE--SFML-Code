#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class BackgroundInput : public GeneralInput {
        private:
            bool bSpacePressed;

        public:
            BackgroundInput(std::string strName);
        
        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key inKey, bool isPressed);

        public:
            bool getInteract();
    };
}
