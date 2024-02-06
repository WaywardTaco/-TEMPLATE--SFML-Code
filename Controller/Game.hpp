
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../Model/Entity/Player.hpp"
#include "../Model/Enum/AssetType.hpp"
#include "Manager/TextureManager.hpp"

namespace controllers {
    using namespace entities;
    using namespace managers;
    class Game {
        // Fields
        private:
            sf::RenderWindow CWindow;
            Player CEntity;
            bool bCloseWindow;

        // Controllers
        public:
            Game();

        // Methods
        public:
            void run();

        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
    };
}

#endif