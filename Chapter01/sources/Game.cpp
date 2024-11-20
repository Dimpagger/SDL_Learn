#include "Game.h"

const int thickness = 5;     // 滑块的宽度
const float paddleH = 10.0f; // 滑块的长度

Game::Game()
    :mWindow(nullptr)
     ,mRenderer(nullptr)
     ,mTicksCount(0)
     ,mIsRunning(true)
     ,mPaddleDir(0)
{
}

bool Game::Initialize() {

    height = 300;
    width = 400;

    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0) {
        SDL_Log("unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow(
            "SDL_DEMO",
            100, 100, 
            width, height,
            0);
    if (!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    mRenderer = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
            );
    if (!mRenderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }

    mPaddlePos.x = 0.0f;
    mPaddlePos.y = height/2.0f;
    mBallPos.x = width/2.0f;
    mBallPos.y = height/2.0f;
    mBallVel.x = -100.0f;
    mBallVel.y = 100.0f;
    return true;
}

void Game::Shutdown() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::RunLoop() {
    while(mIsRunning){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_Q]) {
        mIsRunning = false;
    }
    mPaddleDir = 0;
    if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_K]) {
        mPaddleDir -=1;
    }
    if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_J]) {
        mPaddleDir +=1;
    }
}

void Game::UpdateGame() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }
    mTicksCount = SDL_GetTicks();

    if (mPaddleDir != 0) {
        mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;
        if (mPaddlePos.y < (paddleH/2.0f + thickness)) {
            mPaddlePos.y = paddleH/2.0f + thickness;
        }
        if (mPaddlePos.y > (height - paddleH/2.0f - thickness)) {
            mPaddlePos.y = height - paddleH/2.0f - thickness;
        }
    }

    mBallPos.x += mBallVel.x * deltaTime;
    mBallPos.y += mBallVel.y * deltaTime;

    float diff = mPaddlePos.y - mBallPos.y;
    diff = (diff > 0.0f) ? diff : -diff;
    if (
            diff <= paddleH / 2.0f &&
            mBallPos.x <= 5.0f &&
            mBallPos.x >= 0.0f &&
            mBallVel.x < 0.0f) {
        mBallVel.x *= -1.0f;
    } else if (mBallPos.x <= 0.0f) {
        mIsRunning = false;
    } else if (mBallPos.x >= (width - thickness) && mBallVel.x > 0.0f ) {
        mBallVel.x *= -1.0f;
    } else if (mBallPos.y >= (height - thickness) && mBallVel.y > 0.0f ) {
        mBallVel.y *= -1.0f;
    } else if (mBallPos.y <= thickness && mBallVel.y < 0.0f ) {
        mBallVel.y *= -1.0f;
    } else {
    }
}

void Game::GenerateOutput() {
    SDL_SetRenderDrawColor(
            mRenderer,
            0,0,255,255
            );
    SDL_RenderClear(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_Rect wall{0, 0, width, thickness};
    SDL_RenderFillRect(mRenderer, &wall);

    wall.y = height - thickness;
    SDL_RenderFillRect(mRenderer, &wall);

    wall.x = width - thickness;
    wall.y = 0;
    wall.w = thickness;
    wall.h = width;
    SDL_RenderFillRect(mRenderer, &wall);

    //wall.x = 0;
    //SDL_RenderFillRect(mRenderer, &wall);

    SDL_Rect paddle{static_cast<int>(mPaddlePos.x), static_cast<int>(mPaddlePos.y-20), 5, 40};
    SDL_RenderFillRect(mRenderer, &paddle);

    SDL_Rect ball{static_cast<int>(mBallPos.x), static_cast<int>(mBallPos.y-5), 10, 10};
    SDL_RenderFillRect(mRenderer, &ball);


    SDL_RenderPresent(mRenderer);
}

