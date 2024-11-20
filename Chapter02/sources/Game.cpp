#include "Game.h"


Game::Game()
    :mWindow(nullptr)
     ,mRenderer(nullptr)
     ,mIsRunning(true)
     ,mUpdatingActors(false)
{
}

bool Game::Initialize() {

    height = 300;
    width = 400;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow(
            "SDL_DEMO",
            100, 100, 
            width, height,
            0);
    if (!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
            );
    if (!mRenderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
        return false;
    }

    LoadData();
    mTicksCount = SDL_GetTicks();
    return true;
}

void Game::Shutdown() {
    UnloadData();
    IMG_Quit();
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
    mShip->ProcessKeyboard(state);
}

void Game::AddActor(Actor* actor) {
    if (mUpdatingActors) {
        mPendingActors.emplace_back(actor);
    } else {
        mActors.emplace_back(actor)
    }
}

void Game::RemoveActor(Actor* actor) {
    auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if (iter != mPendingActors.end()){
        std::iter_swap(iter, mPendingActors.end() - 1);
        mPendingActors.pop_back();
    } 
    iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end()) {
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
} 

void Game::UpdateGame() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }
    mTicksCount = SDL_GetTicks();

    mUpdatingActors = true;
    for (auto actor: mAtcors) {
        actor->Update(deltaTime);
    }
    mUpdatingActors = false;

    for (auto pending: mPendingActors) {
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();

    std::vector<Actor*> deadActors;
    for (auto actor: mActors) {
        if (actor->GetState() == Actor::EDead) {
            deadActors.emplace_back(actor);
        }
    }

    for (auto actor: deadActors) {
        delete actor;
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

