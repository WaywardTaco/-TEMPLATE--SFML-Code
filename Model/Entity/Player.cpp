#include "Player.hpp"

using namespace entities;
using namespace components;

// Player::Player(std::string strName) : GameObject(strName, 300.0f) {
//     this->bMovingLeft = false;
//     this->bMovingRight = false;
// }

Player::Player(std::string strName, AnimatedTexture* pAnimatedTexture) 
    : GameObject(strName, 300.0f, pAnimatedTexture) {}

void Player::initialize(){
    this->pSprite->setPosition(100.f, 100.f);

    this->attachComponent(new PlayerInput(this->strName + "Input"));
    this->attachComponent(new PlayerMovement(this->strName + "Movement"));
    this->attachComponent(new Renderer(this->strName + "Renderer"));

    ((Renderer*)this->findComponentByName(this->strName + "Renderer"))->assignDrawable(this->pSprite);
};

// void Player::update(sf::Time tDeltaTime){
//     if(true){
//         this->pSprite->move(-1.f * this->fSpeed * tDeltaTime.asSeconds(), 0.f);

//         this->pAnimatedTexture->setCurrentFrame(0);
//         this->getSprite()->setTexture(*this->pAnimatedTexture->getFrame());
//     }

//     if(true){
//         this->pSprite->move(1.f * this->fSpeed * tDeltaTime.asSeconds(), 0.f);

//         this->pAnimatedTexture->setCurrentFrame(1);
//         this->getSprite()->setTexture(*this->pAnimatedTexture->getFrame());
//     }
// };

// void Player::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){
//     switch (CKey) {
//       case sf::Keyboard::W :
//          this->bMovingUp = isPressed;
//          break;
//       case sf::Keyboard::A :
//          this->bMovingLeft = isPressed;
//          break;
//       case sf::Keyboard::S :
//          this->bMovingDown = isPressed;
//          break;
//       case sf::Keyboard::D :
//          this->bMovingRight = isPressed;
//          break;
//       default :
//          break;
//    }    
// };

// bool Player::getMovingLeft() {
//     return this->bMovingLeft;
// }

// void Player::setMovingLeft(bool bMovingLeft) {
//     this->bMovingLeft = bMovingLeft;
// }

// bool Player::getMovingRight() {
//     return this->bMovingRight;
// }

// void Player::setMovingRight(bool bMovingRight) {
//     this->bMovingRight = bMovingRight;
// }
