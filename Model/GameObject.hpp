
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

namespace models {
    class GameObject {
        // Field
        private:
            sf::Texture CTexture;
            sf::Sprite imgSprite;

            int 
                iXpos = 100,
                iYpos = 100
            ;

        // Constructors
        public:
            GameObject(sf::Texture CTexture);

        // Methods
        public:
            void renderTo(sf::RenderWindow* window);

        // Getters & Setters
        public:
            void setTexture(sf::Texture CTexture_param);
            sf::Sprite* getSprite();
    };
}

#endif