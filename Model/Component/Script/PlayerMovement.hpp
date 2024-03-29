#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"

namespace components {
    class PlayerMovement : public Component {
        private:
            float fSpeed;

        public:
            PlayerMovement(std::string strName);

        public:
            void perform();
    };
}