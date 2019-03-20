#include "GameObject.hpp"
#include "textureManager.hpp"


GameObject::GameObject(const char * texturesheet,int x,int y)
{
    
    objTexture = textureManager::LoadTexture(texturesheet);
    
    xpos = x;
    ypos = y;
}

GameObject::~GameObject()
{
    
}

void GameObject::Update()
{
    
    
    srcRect.w = 30;
    srcRect.h = 30;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos+600;
    destRect.w = srcRect.w *2;
    destRect.h = srcRect.h *2;
    
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

