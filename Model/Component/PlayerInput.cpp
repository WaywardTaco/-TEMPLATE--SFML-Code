
#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName),
    bMovingLeft = false, bMovingRight = false, bMovingUp = false, bMovingDown = false
{

};

void PlayerInput::perform(){
    switch(this->CEvent.type){
        case sf::Event::KeyPressed :
            this->processKeyboardInput(this->CEvent.key.code, true);
            break;

        case sf::Event::KeyReleased :
            this->processKeyboardInput(this->CEvent.key.code, false);
            break;
    }
};

void PlayerInput::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){
    switch (CKey) {
        case sf::Keyboard::W :
            this->bMovingUp = isPressed;
            break;
        case sf::Keyboard::A :
            this->bMovingLeft = isPressed;
            break;
        case sf::Keyboard::S :
            this->bMovingDown = isPressed;
            break;
        case sf::Keyboard::D :
            this->bMovingRight = isPressed;
            break;
        default :
            break;
   }    
};

bool PlayerInput::getMovingLeft(){
    return this->bMovingLeft;
};

bool PlayerInput::getMovingRight(){
    return this->bMovingEight;
};

bool PlayerInput::getMovingUp(){
    return this->bMovingUp;
};

bool PlayerInput::getMovingDown(){
    return this->bMovingDown;
};

