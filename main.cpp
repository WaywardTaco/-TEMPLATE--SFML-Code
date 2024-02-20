
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/PlayerInput.cpp"
#include "Model/AnimatedTexture.cpp"
#include "Model/GameObject.cpp"
#include "Model/Entity/Player.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Game.cpp"


/********* MAIN *********/
int main(){
   Game CGame;
   CGame.run();
   return 0;
};