
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

namespace models {
    class GameObject {
        // Field
        private:
            sf::Texture CTexture;
            sf::Sprite imgSprite;

            float 
                fXpos, 
                fYpos, 
                fSpeed
            ;
            
            bool
                bMovingUp,
                bMovingDown,
                bMovingLeft,
                bMovingRight
            ;

        // Constructors
        public:
            GameObject();

        // Methods
        public:
            void renderTo(sf::RenderWindow* window);
            void updatePosition(float fElapsedTime);

        // Getters & Setters
        public:
            void setTexture(sf::Texture CTexture_param);
            
            sf::Sprite* getSprite();

            float getSpeed();

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