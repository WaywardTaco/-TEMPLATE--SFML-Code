
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

namespace models {
    class GameObject {
        // Field
        private:
            sf::Texture CTexture;
            sf::Sprite imgSprite;

            bool
                bUpFlag = false,
                bDownFlag = false,
                bLeftFlag = false,
                bRightFlag = false
            ;

            float 
                fXpos = 100,
                fYpos = 100,
                fSpeed = 1.8
            ;



        // Constructors
        public:
            GameObject(sf::Texture CTexture);

        // Methods
        public:
            void renderTo(sf::RenderWindow* window);
            void updatePosition();

        // Getters & Setters
        public:
            void setTexture(sf::Texture CTexture_param);
            void setUpFlag(bool bValue);
            void setDownFlag(bool bValue);
            void setLeftFlag(bool bValue);
            void setRightFlag(bool bValue);
            
            sf::Sprite* getSprite();

    };
}

#endif