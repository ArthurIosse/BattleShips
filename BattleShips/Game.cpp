#include "Game.hpp"
#include "textureManager.hpp"
#include "GameObject.hpp"

//implementation

GameObject * player;
GameObject * enemy;

SDL_Renderer * Game::renderer = nullptr;



void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    SDL_Init(SDL_INIT_EVERYTHING);
    
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
    
    player = new GameObject("/Users/Arthur/workspace/BattleShips/graphics/player.png",0,0);
    enemy = new GameObject("/Users/Arthur/workspace/BattleShips/graphics/enemy.png",300,300);
    
}

void Game::update()
{
    player->Update();
    enemy->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::handleEvent()
{
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
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
