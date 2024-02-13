
#ifndef ANIMATED_TEXTURE_H
#define ANIMATED_TEXTURE_H

#include "Enum/AssetType.hpp"

namespace models {
    class AnimatedTexture {
        private:
            AssetType EType;
            std::vector<sf::Texture*> vecFrames;
            int nCurrentFrame;

        public:
            AnimatedTexture(AssetType EType, std::vector<sf::Texture*> vecFrames);

        public:
            void incrementFrame();
            sf::Texture* getFrame();
            void setCurrentFrame(int nCurrentFrame);  

    };
}

#endif