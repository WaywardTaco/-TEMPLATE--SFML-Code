
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../Model/GameObject.hpp"

namespace controllers {
    class Game {
        // Fields
        private:
            sf::RenderWindow* CWindow;
            GameObject* CEntity;
            bool 
                bCloseWindow = false
            ;

        // Controllers
        public:
            Game();

        // Methods
        public:
            void run();

        private:
            void processEvents();
            void update();
            void render();
    };
}

#endif