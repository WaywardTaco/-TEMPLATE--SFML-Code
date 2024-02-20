#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        private:
            // bool bMovingLeft;
            // bool bMovingRight;
            // bool bMovingUp;
            // bool bMovingDown;

        public:
            // Player(std::string strName);
            Player(std::string strName, AnimatedTexture* pAnimatedTexture);

        /* [TODO][1] */
        public:
            void initialize();
            void update(sf::Time tDeltaTime);

        // protected:
        //     void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);

        // public:
            // bool getMovingLeft();
            // void setMovingLeft(bool bMovingLeft);
            // bool getMovingRight();
            // void setMovingRight(bool bMovingRight);
    };
}
