
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../Model/Entity/Player.hpp"
#include "../Model/Enum/AssetType.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"

namespace controllers {
    using namespace entities;
    using namespace managers;
    class Game {
        // Fields
        private:
            sf::RenderWindow CWindow;
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
    };
}

#endif