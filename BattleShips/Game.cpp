#include "Game.hpp"
#include "textureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

int field[20][25] =
{{1,21,22,23,24,25,26,27,28,29,30,1,2,1,1,1,1,1,1,1,1,1,1,1,1},
    {11,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {12,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {13,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {14,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {15,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {16,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {17,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {18,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {19,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {20,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,44,44,44,44,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,43,43,43,1,41,1,41,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,43,43,43,1,41,1,41,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,42,42,1,42,42,1,42,42,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


//implementation

GameObject * player;
//GameObject * enemy;
Map * map;

SDL_Renderer * Game::renderer = nullptr;



void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    
    window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,flags);
    if(window == NULL){
        cout << "window cannot be created\n";
        isRunning = false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 200);
    
    if(renderer == NULL){
        cout << "renderer cannot be created\n";
        isRunning = false;
    }
    isRunning = true;
    }
    
    map = new Map(field);
    player = new GameObject("/Users/Arthur/workspace/BattleShips/assets/player.png",1,1);
    //enemy = new GameObject("/Users/Arthur/workspace/BattleShips/assets/enemy.png",14,1);
    
}

void Game::update()
{
    player->Update();
    map->LoadMap(field);
    //enemy->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    //enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::handleEvent()
{
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym){
    case SDLK_a: player->ChangeX(false);
        break;
    case SDLK_d: player->ChangeX(true);
        break;
    case SDLK_w: player->ChangeY(false);
        break;
    case SDLK_s: player->ChangeY(true);
        break;
    case SDLK_SPACE: if(field[player->ypos/32][player->xpos/32] == 44)
                field[player->ypos/32][player->xpos/32] = 44;
            
                break;
        }
    }
    
    if(event.type == SDL_KEYUP)
    {}
    
    switch(event.type){
        case SDL_QUIT: isRunning = false; break;
        default: break;
    }
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "everything is clear\n";
}

bool Game::running()
{
    
    return isRunning;
}

Game::Game()
{}

Game::~Game()
{}
