
#pragma once

#include <vector>
#include "../../Model/Enum/PoolTag.hpp"
#include "../../Model/Pooling/PoolableObject.hpp"
#include "../Manager/GameObjectManager.hpp"

namespace poolables {
    using namespace managers;
    class GameObjectPool {
        private:
            PoolTag ETag;
            int nPoolSize;
            PoolableObject* pPoolableReference;
            std::vector<PoolableObject*> vecAvailableObject;
            std::vector<PoolableObject*> vecUsedObject;

        public:
            GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference);

        public:
            void initialize();
            PoolableObject* requestPoolable();
            std::vector<PoolableObject*> requestPoolableBatch(int nRequestSize);
            void releasePoolable(PoolableObject* pPoolableObject);
            void releasePoolableBatch(std::vector<PoolableObject*> vecPoolableObject);

        private:
            bool hasAvailable(int nRequestSize);
            void setEnabled(PoolableObject* pPoolableObject, bool bEnable);

        public:
            PoolTag getTag();
    };
}