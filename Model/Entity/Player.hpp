#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"

#include "../Component/PlayerInput.hpp"
#include "../Component/PlayerMovement.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        public:
            Player(std::string strName, AnimatedTexture* pAnimatedTexture);
        
        public:
            void initialize();
            // void update(sf::Time tDeltaTime);

        // protected:
        //     void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);

        // public:
            // bool getMovingLeft();
            // void setMovingLeft(bool bMovingLeft);
            // bool getMovingRight();
            // void setMovingRight(bool bMovingRight);
    };
}
