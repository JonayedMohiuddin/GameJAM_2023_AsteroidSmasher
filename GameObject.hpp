#pragma once
#include "Game.hpp"

class GameObject
{
public:
    int cnt = 0;

    GameObject(const char *textureSheet, int x, int y);
    ~GameObject();

    void update();
    void render();
private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};
