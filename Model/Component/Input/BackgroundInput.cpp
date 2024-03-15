
#include "BackgroundInput.hpp"

using namespace components;

BackgroundInput::BackgroundInput(std::string strName) 
    : GeneralInput(strName), bSpacePressed(false), bQPressed(false)
{

}

void BackgroundInput::perform(){
    switch(this->CEvent.type){
        case sf::Event::KeyPressed:
            this->processKeyboardInput(this->CEvent.key.code, true);
            break;
        case sf::Event::KeyReleased:
            this->processKeyboardInput(this->CEvent.key.code, false);
            break;
    }
}
      
void BackgroundInput::processKeyboardInput(sf::Keyboard::Key inKey, bool isPressed){
    switch(inKey){
        case sf::Keyboard::Space:
            this->bSpacePressed = isPressed;
            break;
        case sf::Keyboard::Q:
            this->bQPressed = isPressed;
            break;
    }
}

bool BackgroundInput::getInteract(){
    return this->bSpacePressed;
};

bool BackgroundInput::getBack(){
    return this->bQPressed;
}