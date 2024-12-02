
#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Math.h"
#include "Random.h"

Asteroid::Asteroid(class Game* game) 
    :Actor(game) {
        Vector2 randPos = Random::GetVector(Vector2::Zero, 
                Vector2(GetGame()->GetWidth(), GetGame()->GetHeight()));
        SetPosition(randPos);
        SpriteComponent* sc = new SpriteComponent(this);
        sc->SetTexture(GetGame()->GetTexture("assets/Asteroid.png"));
        MoveComponent* mc = new MoveComponent(this);
        mc->SetForwardSpeed(150.0f);
}

void Asteroid::ActorInput(const uint8_t* keyState) {
}
