#include "Game.hpp"

#define W 600
#define H 600

Game * game = nullptr;


int main(int argc, const char * argv[]) {
    
    const int FPS = 60;
    const int framedelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    
    game->init("BattleShips",W, H, false);
    
    while(game->running())
    {
        frameStart = SDL_GetTicks();
        
        game->handleEvent();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(framedelay > frameTime){
            SDL_Delay(framedelay - frameTime);
        }
        
    }
    
    game->clean();
    //delete(game);
    return 0;
}
