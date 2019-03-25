#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"

class GameObject {
public:
    GameObject(const char * texturesheet,int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    void ChangeX(bool x);
    void ChangeY(bool y);
    void Flipped(bool a);
    
    int xpos;
    int ypos;
    bool flipped = false;
    
private:
    
    
    
    SDL_Texture * objTexture;
    SDL_Rect srcRect, destRect;
    
};

#endif /* GameObject_hpp */
