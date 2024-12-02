
#include "TextComponent.h"
#include "Actor.h"

TextComponent::TextComponent(Actor* owner)
    :SpriteComponent(owner) {
}

void TextComponent::Draw(SDL_Renderer* renderer) {
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, NULL);
}

void TextComponent::Update(float deltaTime) {
    float value = mOwner->GetRotation();
    std::string str = "Ship rotation: ";
    std::string result = str + std::to_string(value);
    const char* c_str = result.c_str();
    textSurface  = TTF_RenderText_Solid(mOwner->GetGame()->GetFont(), result.c_str(), {0, 0, 0});
}

void TextComponent::SetTexture(SDL_Texture* texture) {
}


