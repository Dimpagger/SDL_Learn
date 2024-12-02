
#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <unordered_map>
#include <string>
#include <vector>

class Game {
    public:
        Game();
        bool Initialize();
        void RunLoop();
        void Shutdown();

        void AddActor(class Actor* actor);
        void RemoveActor(class Actor* actor);
        void AddSprite(class SpriteComponent* sprite);
        void RemoveSprite(class SpriteComponent* sprite);

        int GetWidth() const { return mWidth; }
        int GetHeight() const { return mHeight; }

        SDL_Texture* GetTexture(const std::string& fileName);
        TTF_Font* GetFont() const { return mFont; }
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();
        void LoadData();
        void UnloadData();

        std::unordered_map<std::string, SDL_Texture*> mTextures;
        std::vector<class Actor*> mActors;
        std::vector<class Actor*> mPendingActors;
        std::vector<class SpriteComponent*> mSprites;

        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        TTF_Font* mFont;
        Uint32 mTicksCount;
        bool mIsRunning;
        bool mUpdatingActors;
        class Ship* mShip;

        int mWidth = 800;
        int mHeight = 600;
};
