#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char** args)
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS; // 1/FPS is frame delay in seconds ... multiplied by 1000 to convert to milisecond

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while(game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();

	return 0;
}