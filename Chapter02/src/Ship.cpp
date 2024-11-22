
#include "Ship.h"
#include "AnimSpriteComponent.h"

Ship::Ship(Game* game)
    :Actor(game)
     ,mRightSpeed(0.0f)
     ,mDownSpeed(0.0f) {
        AnimSpriteComponent* asc = new AnimSpriteComponent(this);
        std::vector<SDL_Texture*> anims = {
            game->GetTexture("assets/Ship01.png"),
            game->GetTexture("assets/Ship02.png"),
            game->GetTexture("assets/Ship03.png"),
            game->GetTexture("assets/Ship04.png")
        };
        asc->SetAnimTextures(anims);
}

void Ship::UpdateActor(float deltaTime) {
    Actor::UpdateActor(deltaTime);
    Vector2 pos = GetPosition();
    pos.x += mRightSpeed * deltaTime;
    pos.y += mDownSpeed * deltaTime;

    SetPosition(pos);
}

void Ship::ProcessKeyboard(const uint8_t* state) {
    mRightSpeed = 0.0f;
    mDownSpeed = 0.0f;

    if (state[SDL_SCANCODE_D]){
        mRightSpeed += 250.0f;
    }
    if (state[SDL_SCANCODE_A]){
        mRightSpeed -= 250.0f;
    }
    if (state[SDL_SCANCODE_S]){
        mDownSpeed += 300.0f;
    }
    if (state[SDL_SCANCODE_W]){
        mDownSpeed -= 300.0f;
    }
}
