
#pragma once
#include "SpriteComponent.h"

class TextComponent: public SpriteComponent {
    public:
        TextComponent(class Actor* owner);

        void Update(float deltaTime) override;
        void SetTexture(SDL_Texture* texture) override;
        void Draw(SDL_Renderer* renderer) override;
    private:
        SDL_Surface* textSurface;
};
