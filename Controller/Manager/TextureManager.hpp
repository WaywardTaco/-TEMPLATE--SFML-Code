
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "../../Model/Enum/AssetType.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace managers {
    class TextureManager {
        private:
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;

        public:
            void loadAll();
            void loadMainMenu();
            void loadGame();
            void clearAll();

        public:
            std::vector<sf::Texture*> getTexture(AssetType EKey);
            sf::Texture* getTextureAt(AssetType EKey, int nFrame);

        /* SINGLETON TEMPLATE */
        private:
            static TextureManager* P_SHARED_INSTANCE;
        
        private:
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();

    };
}

#endif