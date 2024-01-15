
#ifndef GAME_HPP
#define GAME_HPP

namespace controllers {
    class Game {
        // Controllers
        public:
            Game();

        // Methods
        public:
            void run();

        private:
            void processEvents();
            void update();
            void render();
    };
}

#endif