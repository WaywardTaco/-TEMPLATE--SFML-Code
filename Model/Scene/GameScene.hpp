
#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Enum/PoolTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Ship.hpp"
#include "../Pooling/Entity/PlayerBullet.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"

namespace scenes {
    using namespace models;
    using namespace managers;
    using namespace entities;
    using namespace poolables;
    class GameScene : public Scene {
        public:
            GameScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createBackground();
            void createShip();
            void createObjectPools();
    };
}