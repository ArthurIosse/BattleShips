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
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


//implementation

GameObject * player;

GameObject * ship11;
GameObject * ship12;
GameObject * ship13;
GameObject * ship14;

GameObject * ship21;
GameObject * ship22;
GameObject * ship23;

GameObject * ship31;
GameObject * ship32;

GameObject * ship41;


GameObject * enemy = NULL;
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
    ship11 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 1, 12);
    ship12 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 3, 12);
    ship13 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 5, 12);
    ship14 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 7, 12);
    
    ship21 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 1, 14);
    //enemy = new GameObject("/Users/Arthur/workspace/BattleShips/assets/enemy.png",14,1);
    
}

void Game::update()
{
    player->Update();
    ship11->Update();
    ship12->Update();
    ship13->Update();
    ship14->Update();
    ship21->Update();
    //enemy->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    
    ship11->Render();
    ship12->Render();
    ship13->Render();
    ship14->Render();
    ship21->Render();
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
            case SDLK_SPACE: if((player->xpos == ship11->xpos) && (player->ypos == ship11->ypos) && enemy == NULL){
        enemy = player;
        player = ship11;
                field[player->ypos/32][player->xpos/32] = 0;
            }
                else if((player->xpos == ship12->xpos) && (player->ypos == ship12->ypos)&& enemy == NULL){
                    enemy = player;
                    player = ship12;
                    field[player->ypos/32][player->xpos/32] = 0;
                }
                   else if((player->xpos == ship13->xpos) && (player->ypos == ship13->ypos)&& enemy == NULL){
                        enemy = player;
                        player = ship13;
                       field[player->ypos/32][player->xpos/32] = 0;
                    }
                       else if((player->xpos == ship14->xpos) && (player->ypos == ship14->ypos)&& enemy == NULL){
                            enemy = player;
                            player = ship14;
                           field[player->ypos/32][player->xpos/32] = 0;
                          }
        break;
            case SDLK_p: if(enemy != NULL && field[player->ypos/32][player->xpos/32] == 0
                            && (field[(player->ypos/32)+1][player->xpos/32] != 6)
                            && (field[(player->ypos/32)+1][(player->xpos/32)-1] != 6)
                            && (field[(player->ypos/32)+1][(player->xpos/32)+1] != 6)
                            && (field[(player->ypos/32)+1][(player->xpos/32)-1] != 6)
                            && (field[(player->ypos/32)-1][player->xpos/32] != 6)
                            && (field[(player->ypos/32)-1][(player->xpos/32)-1] != 6)
                            && (field[player->ypos/32][(player->xpos/32)+1] != 6)
                            && (field[player->ypos/32][(player->xpos/32)-1] != 6)){
                enemy->xpos = player->xpos;
                enemy->ypos = player->ypos;
                field[player->ypos/32][player->xpos/32] = 6;
                player = enemy;
                enemy = NULL;
            }
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
