#ifndef textureManager_hpp
#define textureManager_hpp

#include "Game.hpp"

class textureManager{
  
public:
    static SDL_Texture* LoadTexture(const char* filename);
};

#endif /* textureManager_hpp */
