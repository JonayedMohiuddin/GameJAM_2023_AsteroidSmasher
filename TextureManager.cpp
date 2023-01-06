#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char *fileName)
{
    SDL_Surface *tmpSurface = IMG_Load(fileName);
    if(tmpSurface == NULL)
    {
        std::cout << "!! Couldnt load image : " << fileName << std::endl;
    }
    else
    {
        std::cout << "Image loaded : " << fileName << std::endl;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect)
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}

void TextureManager::DrawRotated(SDL_Texture* texture, float angle, SDL_Point origin,  SDL_Rect srcRect, SDL_Rect destRect)
{
    SDL_RenderCopyEx(Game::renderer, texture, &srcRect, &destRect, angle, &origin, SDL_FLIP_NONE);
}
