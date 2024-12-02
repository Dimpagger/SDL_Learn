
#include "Actor.h"

class Asteroid: public Actor {
    public:
        Asteroid(class Game* game);
        void ActorInput(const uint8_t* keyState) override;
};
