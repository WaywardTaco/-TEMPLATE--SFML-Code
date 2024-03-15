
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Model/Enum/AssetType.hpp"
#include "Model/Enum/ComponentType.hpp"
#include "Model/Enum/SceneTag.hpp"
#include "Model/Enum/PoolTag.hpp"

#include "Model/Component/Component.cpp"
#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"
#include "Model/Scene.cpp"

#include "Model/Component/Renderer/Renderer.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Input/BackgroundInput.cpp"
#include "Model/Component/Input/ShipInput.cpp"
#include "Model/Component/Script/PlayerMovement.cpp"
#include "Model/Component/Script/BackgroundAction.cpp"
#include "Model/Component/Script/ShipControls.cpp"
#include "Model/Component/Script/BulletMovement.cpp"

#include "Model/Entity/Ship.cpp"
#include "Model/Entity/Background.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Entity/PlayerBullet.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"

#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/SceneManager.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"
#include "Controller/Game.cpp"


/********* MAIN *********/
int main(){ 
   Game CGame;
   CGame.run();
   return 0;
};