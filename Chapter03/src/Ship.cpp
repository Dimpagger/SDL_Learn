
#include "Ship.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "TextComponent.h"

Ship::Ship(Game* game)
    :Actor(game) {
        SpriteComponent* sc = new SpriteComponent(this);
        sc->SetTexture(game->GetTexture("assets/Ship.png"));
        InputComponent* ic = new InputComponent(this);
        ic->SetMaxAngularSpeed(Math::TwoPi);
        ic->SetMaxForwardSpeed(200.0f);
        ic->SetForwardKey(SDL_SCANCODE_W);
        ic->SetBackKey(SDL_SCANCODE_S);
        ic->SetClockwiseKey(SDL_SCANCODE_D);
        ic->SetCounterClockwiseKey(SDL_SCANCODE_A);
        TextComponent* tc = new TextComponent(this);
}

void Ship::UpdateActor(float deltaTime) {
}

void Ship::ActorInput(const uint8_t* keyState) {
}

