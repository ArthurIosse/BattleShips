#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include  "SDL2_image/SDL_image.h"

using namespace std;

//prototypes
class Game{
public:
    Game();
    ~Game();
    
    void init(const char * title,int width, int height,bool fullscreen);
    
    void update();
    void handleEvent();
    void render();
    void clean();
    
    bool running();
    
    static SDL_Renderer * renderer;
    
private:
    SDL_Window * window;
    bool isRunning = false;
    int counter = 0;
};

#endif /* Game_hpp */


