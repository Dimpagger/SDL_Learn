
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

    if(pos.x > getGame()->GetWidth()) {
        pos.x = getGame()->GetWidth();
    }
    if(pos.y > getGame()->GetHeight()) {
        pos.y = getGame()->GetHeight();
    }
    if(pos.y<0) {
        pos.y=0;
    }
    if(pos.x<0){
        pos.x=0;
    }

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
    if (state[SDL_SCANCODE_J]){
        mDownSpeed += 300.0f;
    }
    if (state[SDL_SCANCODE_K]){
        mDownSpeed -= 300.0f;
    }
}
