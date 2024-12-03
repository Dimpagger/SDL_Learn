
#include "TextComponent.h"
#include "Actor.h"

TextComponent::TextComponent(Actor* owner)
    :SpriteComponent(owner) {
}

void TextComponent::Draw(SDL_Renderer* renderer) {
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect r;
        r.w = static_cast<int>(500);
        r.h = static_cast<int>(50);
        r.x = static_cast<int>(mOwner->GetPosition().x - static_cast<float>(r.w)/2);
        r.y = static_cast<int>(mOwner->GetPosition().y - static_cast<float>(r.h)/2);

    SDL_RenderCopy(renderer, textTexture, nullptr, &r);
}

void TextComponent::Update(float deltaTime) {
    float value = mOwner->GetRotation();
    std::string str = "Ship rotation: ";
    std::string result = str + std::to_string(value);
    const char* c_str = result.c_str();
    textSurface  = TTF_RenderText_Solid(mOwner->GetGame()->GetFont(), result.c_str(), {255, 255, 255});
}

void TextComponent::SetTexture(SDL_Texture* texture) {
}


