#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *textureSheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(textureSheet);

    xpos = x;
    ypos = y;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 32;
    srcRect.h = 32;

    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
    destRect.x = xpos;
    destRect.y = ypos;

    cnt++;
    if(cnt > 32)
    {
        xpos += 32;
        ypos += 32;
        cnt -= 32;
    }
}

void GameObject::render()
{
    TextureManager::Draw(objTexture, srcRect, destRect);
}
