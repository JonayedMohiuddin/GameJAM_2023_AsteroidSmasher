#pragma once
#include "Game.hpp"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char *fileName);
    static void Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
    static void DrawRotated(SDL_Texture* texture, float angle, SDL_Point origin, SDL_Rect srcRect, SDL_Rect destRect);
};
