
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

namespace models {
    class GameObject {
        // Field
        private:
            sf::Texture CTexture;
            sf::Sprite imgSprite;

        // Constructors
        public:
            GameObject();

        // Methods
        private:
            void render();

        // Getters & Setters
        public:
            void setTexture(sf::Texture CTexture_param);
            sf::Sprite* getSprite();
    };
}

#endif