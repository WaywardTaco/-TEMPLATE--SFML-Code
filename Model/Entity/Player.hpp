
#ifndef PLAYER_H
#define PLAYER_H

#include "../GameObject.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        private:
            bool
                bMovingUp,
                bMovingDown,
                bMovingLeft,
                bMovingRight
            ;

        public:
            Player(std::string strName);

        public:
            void updatePosition(float fElapsedTime);

        public:
            bool getMovingUp();
            void setMovingUp(bool bMovingUp);

            bool getMovingDown();
            void setMovingDown(bool bMovingDown);

            bool getMovingLeft();
            void setMovingLeft(bool bMovingLeft);

            bool getMovingRight();
            void setMovingRight(bool bMovingRight); 
    };      
}

#endif