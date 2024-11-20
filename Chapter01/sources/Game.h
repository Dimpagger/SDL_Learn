

#pragma once
#include "SDL.h"

struct Vector2 {
    float x;
    float y;
};

class Game {
    public:
        Game();
        bool Initialize();
        void RunLoop();
        void Shutdown();
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        Uint32 mTicksCount;
        bool mIsRunning;
        int mPaddleDir;

        int height;
        int width;
        Vector2 mPaddlePos;
        Vector2 mBallPos;
        Vector2 mBallVel;
};