
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../Model/AnimatedTexture.hpp"
#include "../Model/Entity/Ship.hpp"
#include "../Model/Enum/AssetType.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/SceneManager.hpp"
#include "../Model/Enum/SceneTag.hpp"
#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/GameScene.hpp"

namespace controllers {
    using namespace entities;
    using namespace managers;
    using namespace scenes;
    class Game {
        private:
            sf::RenderWindow CWindow;
            bool bCloseWindow;

        public:
            Game();

        public:
            void run();

        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}

#endif