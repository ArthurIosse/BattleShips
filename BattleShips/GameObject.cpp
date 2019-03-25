#include "GameObject.hpp"
#include "textureManager.hpp"


GameObject::GameObject(const char * texturesheet,int x,int y)
{
    
    objTexture = textureManager::LoadTexture(texturesheet);
    
    xpos = x * 32;
    ypos = y * 32;
}

GameObject::~GameObject()
{
    
}

void GameObject::Flipped(bool a)
{
    flipped = a;
}

void GameObject::ChangeX(bool x)
{
    if(x)
    xpos += 32;
    else
        xpos -= 32;
    
}
void GameObject::ChangeY(bool y)
{
    if(y)
    ypos += 32;
    else
        ypos -= 32;
    
}

void GameObject::Update()
{
    
    
    srcRect.w = 32;
    srcRect.h = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w ;
    destRect.h = srcRect.h ;
    
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

