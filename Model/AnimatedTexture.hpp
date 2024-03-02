
#ifndef ANIMATED_TEXTURE_H
#define ANIMATED_TEXTURE_H

#include "Enum/AssetType.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace models {
    class AnimatedTexture {
        private:
            std::vector<sf::Texture*> vecFrames;
            int nCurrentFrame;

        public:
            AnimatedTexture(std::vector<sf::Texture*> vecFrames);

        public:
            void incrementFrame();
            sf::Texture* getFrame();
            void setCurrentFrame(int nCurrentFrame);  
    };
}

#endif