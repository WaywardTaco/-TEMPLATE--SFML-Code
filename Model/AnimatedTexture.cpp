
#include "AnimatedTexture.hpp"

using namespace models;

AnimatedTexture::AnimatedTexture(std::vector<sf::Texture*> vecFrames) 
    : nCurrentFrame(0)
{
    this->vecFrames = vecFrames;
};

void AnimatedTexture::incrementFrame(){
    this->nCurrentFrame = (this->nCurrentFrame + 1) % this->vecFrames.size();
};

sf::Texture* AnimatedTexture::getFrame(){
    return this->vecFrames[this->nCurrentFrame];
};

void AnimatedTexture::setCurrentFrame(int nCurrentFrame){
    if(nCurrentFrame < 0)
        this->nCurrentFrame = 0;
    else if (this->nCurrentFrame >= vecFrames.size())
        this->nCurrentFrame = vecFrames.size() - 1;
    else
        this->nCurrentFrame = nCurrentFrame;
};  
