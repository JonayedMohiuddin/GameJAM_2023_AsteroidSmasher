#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"

Game::Game(){}
Game::~Game(){}

Player *player;

SDL_Event Game::event;
SDL_Renderer *Game::renderer = nullptr;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    else
        flags = SDL_WINDOW_SHOWN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem initialised." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "Window created." << std::endl;
        }
        else
        {
            std::cout << "!! Couldnt create window." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Renderer created." << std::endl;
        }
        else
        {
            std::cout << "!! Couldnt create renderer." << std::endl;
        }

        isRunning = true;
    }
    else
    {
        std::cout << "!! Couldnt initialise subsystem." << std::endl;
        isRunning = false;
    }

    player = new Player();
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
}

void Game::update()
{
    player->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    /* Add stuff to renderer for rendering */
    player->render();
    /* Rendering stuffs end */
    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

