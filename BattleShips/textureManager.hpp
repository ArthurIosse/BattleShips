#ifndef textureManager_hpp
#define textureManager_hpp

#include "Game.hpp"

class textureManager{
  
public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex,SDL_Rect src, SDL_Rect dest);
};

#endif /* textureManager_hpp */
