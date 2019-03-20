#include "textureManager.hpp"

SDL_Texture* textureManager::LoadTexture(const char * texture)
{
    SDL_Surface * tempSurface = IMG_Load(texture);
    SDL_Texture * tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    if(tempSurface == NULL){
        cout<<"no img found!!"<<endl;
    }
    SDL_FreeSurface(tempSurface);
    
    
    return tex;
}
