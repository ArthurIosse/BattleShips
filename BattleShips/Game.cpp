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
GameObject * player2 = NULL;
GameObject * player3 = NULL;
GameObject * player4 = NULL;

GameObject * ship1;
GameObject * ship2;
GameObject * ship3;
GameObject * ship4;

GameObject * ship11;
GameObject * ship12;
GameObject * ship21;
GameObject * ship22;
GameObject * ship31;
GameObject * ship32;

GameObject * ship311;
GameObject * ship312;
GameObject * ship313;
GameObject * ship321;
GameObject * ship322;
GameObject * ship323;

GameObject * ship41;
GameObject * ship42;
GameObject * ship43;
GameObject * ship44;


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
    ship1 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 1, 12);
    ship2 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 3, 12);
    ship3 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 5, 12);
    ship4 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 7, 12);
    
    ship11 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 1, 14);
    ship12 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 2, 14);
    
    ship21 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 4, 14);
    ship22 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 5, 14);
    
    ship31 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 7, 14);
    ship32 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 8, 14);
    
    ship311 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 1, 16);
    ship312 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 2, 16);
    ship313 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 3, 16);
    
    ship321 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 5, 16);
    ship322 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 6, 16);
    ship323 = new GameObject("/Users/Arthur/workspace/BattleShips/assets/ship.png", 7, 16);
 
    
}

void Game::update()
{
    player->Update();
    
    ship1->Update();
    ship2->Update();
    ship3->Update();
    ship4->Update();
    ship11->Update();
    ship12->Update();
    ship21->Update();
    ship22->Update();
    ship31->Update();
    ship32->Update();
    ship311->Update();
    ship312->Update();
    ship313->Update();
    ship321->Update();
    ship322->Update();
    ship323->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    
    ship1->Render();
    ship2->Render();
    ship3->Render();
    ship4->Render();
    ship11->Render();
    ship12->Render();
    ship21->Render();
    ship22->Render();
    ship31->Render();
    ship32->Render();
    ship311->Render();
    ship312->Render();
    ship313->Render();
    ship321->Render();
    ship322->Render();
    ship323->Render();
    player->Render();
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
                if(player2)player2->ChangeX(false);
                if(player3)player3->ChangeX(false);
                if(player4)player4->ChangeX(false);
        break;
    case SDLK_d: player->ChangeX(true);
                if(player2)player2->ChangeX(true);
                if(player3)player3->ChangeX(true);
                if(player4)player4->ChangeX(true);
        break;
    case SDLK_w: player->ChangeY(false);
                if(player2)player2->ChangeY(false);
                if(player3)player3->ChangeY(false);
                if(player4)player4->ChangeY(false);
        break;
    case SDLK_s: player->ChangeY(true);
                if(player2)player2->ChangeY(true);
                if(player3)player3->ChangeY(true);
                if(player4)player4->ChangeY(true);
        break;
                
                
    case SDLK_SPACE:
                //1-Deck ships PRESS
                if((player->xpos == ship1->xpos) && (player->ypos == ship1->ypos) && enemy == NULL){
                        enemy = player;
                        player = ship1;
                        field[player->ypos/32][player->xpos/32] = 0;
            }
                else if((player->xpos == ship2->xpos) && (player->ypos == ship2->ypos)&& enemy == NULL){
                    enemy = player;
                    player = ship2;
                    field[player->ypos/32][player->xpos/32] = 0;
                }
                   else if((player->xpos == ship3->xpos) && (player->ypos == ship3->ypos)&& enemy == NULL){
                        enemy = player;
                        player = ship3;
                       field[player->ypos/32][player->xpos/32] = 0;
                    }
                       else if((player->xpos == ship4->xpos) && (player->ypos == ship4->ypos)&& enemy == NULL){
                            enemy = player;
                            player = ship4;
                           field[player->ypos/32][player->xpos/32] = 0;
                          }
                
                //1-Deck ships UNPRESS
                       else if((enemy != NULL) && (player2 == NULL) && (player3 == NULL) && (field[player->ypos/32][player->xpos/32] == 0)
                               && (field[(player->ypos/32)+1][ player->xpos/32]    != 6)
                               && (field[(player->ypos/32)+1][(player->xpos/32)+1] != 6)
                               && (field[(player->ypos/32)-1][(player->xpos/32)+1] != 6)
                               && (field[(player->ypos/32)+1][(player->xpos/32)-1] != 6)
                               && (field[(player->ypos/32)-1][ player->xpos/32]    != 6)
                               && (field[(player->ypos/32)-1][(player->xpos/32)-1] != 6)
                               && (field[ player->ypos/32]   [(player->xpos/32)+1] != 6)
                               && (field[ player->ypos/32]   [(player->xpos/32)-1] != 6)       ){
                           enemy->xpos = player->xpos;
                           enemy->ypos = player->ypos;
                           field[player->ypos/32][player->xpos/32] = 6;
                           player = enemy;
                           enemy = NULL;
                       }
                
                //2-Deck ships PRESS
                       else if(((player->xpos == ship11->xpos) || (player->xpos == ship12->xpos))
                               && ((player->ypos == ship11->ypos) || (player->ypos == ship12->ypos))
                               && enemy == NULL){
                           enemy = player;
                           player = ship11;
                           player2 = ship12;
                           field[player->ypos/32][player->xpos/32] = 0;
                           field[player2->ypos/32][player2->xpos/32] = 0;
                       }
                       else if(((player->xpos == ship21->xpos) || (player->xpos == ship22->xpos))
                                && ((player->ypos == ship21->ypos) || (player->ypos == ship22->ypos))
                               && enemy == NULL){
                           enemy = player;
                           player = ship21;
                           player2 = ship22;
                           field[player->ypos/32][player->xpos/32] = 0;
                           field[player2->ypos/32][player2->xpos/32] = 0;
                       }
                       else if(((player->xpos == ship31->xpos) || (player->xpos == ship32->xpos))
                               && ((player->ypos == ship31->ypos) || (player->ypos == ship32->ypos))
                               && enemy == NULL){
                           enemy = player;
                           player = ship31;
                           player2 = ship32;
                           field[player->ypos/32][player->xpos/32] = 0;
                           field[player2->ypos/32][player2->xpos/32] = 0;
                       }
                
                //2_deck ships UNPRESS
    else if((enemy != NULL) && (player2 != NULL) && (player3 == NULL) && (field[player->ypos/32][player->xpos/32] == 0)
            && (field[player2->ypos/32][player2->xpos/32] == 0)
            && (field[(player->ypos/32)+1][ player->xpos/32]    != 6)
            && (field[(player->ypos/32)+1][(player->xpos/32)+1] != 6)
            && (field[(player->ypos/32)-1][(player->xpos/32)+1] != 6)
            && (field[(player->ypos/32)+1][(player->xpos/32)-1] != 6)
            && (field[(player->ypos/32)-1][ player->xpos/32]    != 6)
            && (field[(player->ypos/32)-1][(player->xpos/32)-1] != 6)
            && (field[ player->ypos/32]   [(player->xpos/32)+1] != 6)
            && (field[ player->ypos/32]   [(player->xpos/32)-1] != 6)
            
            && (field[(player2->ypos/32)+1][ player2->xpos/32]    != 6)
            && (field[(player2->ypos/32)+1][(player2->xpos/32)+1] != 6)
            && (field[(player2->ypos/32)-1][(player2->xpos/32)+1] != 6)
            && (field[(player2->ypos/32)+1][(player2->xpos/32)-1] != 6)
            && (field[(player2->ypos/32)-1][ player2->xpos/32]    != 6)
            && (field[(player2->ypos/32)-1][(player2->xpos/32)-1] != 6)
            && (field[ player2->ypos/32]   [(player2->xpos/32)+1] != 6)
            && (field[ player2->ypos/32]   [(player2->xpos/32)-1] != 6)
            ){
        enemy->xpos = player->xpos;
        enemy->ypos = player->ypos;
        field[player->ypos/32][player->xpos/32] = 6;
        field[player2->ypos/32][player2->xpos/32] = 6;
        player = enemy;
        player2 = NULL;
        enemy = NULL;
    }
          //3-Deck ships PRESS
    else if(((player->xpos == ship311->xpos) || (player->xpos == ship312->xpos) || (player->xpos == ship313->xpos))
            && ((player->ypos == ship311->ypos) || (player->ypos == ship312->ypos) || (player->xpos == ship313->xpos))
            && enemy == NULL){
        enemy = player;
        player = ship311;
        player2 = ship312;
        player3 = ship313;
        field[player->ypos/32][player->xpos/32] = 0;
        field[player2->ypos/32][player2->xpos/32] = 0;
        field[player3->ypos/32][player3->xpos/32] = 0;
    }
                
              //3-Deck ships UNPRESS
    else if((enemy != NULL) && (player2 != NULL) && (player3 !=NULL) && (field[player->ypos/32][player->xpos/32] == 0)
            && (field[player2->ypos/32][player2->xpos/32] == 0)
            && (field[(player->ypos/32)+1][ player->xpos/32]    != 6)
            && (field[(player->ypos/32)+1][(player->xpos/32)+1] != 6)
            && (field[(player->ypos/32)-1][(player->xpos/32)+1] != 6)
            && (field[(player->ypos/32)+1][(player->xpos/32)-1] != 6)
            && (field[(player->ypos/32)-1][ player->xpos/32]    != 6)
            && (field[(player->ypos/32)-1][(player->xpos/32)-1] != 6)
            && (field[ player->ypos/32]   [(player->xpos/32)+1] != 6)
            && (field[ player->ypos/32]   [(player->xpos/32)-1] != 6)
            
            && (field[(player2->ypos/32)+1][ player2->xpos/32]    != 6)
            && (field[(player2->ypos/32)+1][(player2->xpos/32)+1] != 6)
            && (field[(player2->ypos/32)-1][(player2->xpos/32)+1] != 6)
            && (field[(player2->ypos/32)+1][(player2->xpos/32)-1] != 6)
            && (field[(player2->ypos/32)-1][ player2->xpos/32]    != 6)
            && (field[(player2->ypos/32)-1][(player2->xpos/32)-1] != 6)
            && (field[ player2->ypos/32]   [(player2->xpos/32)+1] != 6)
            && (field[ player2->ypos/32]   [(player2->xpos/32)-1] != 6)
            
            && (field[(player3->ypos/32)+1][ player3->xpos/32]    != 6)
            && (field[(player3->ypos/32)+1][(player3->xpos/32)+1] != 6)
            && (field[(player3->ypos/32)-1][(player3->xpos/32)+1] != 6)
            && (field[(player3->ypos/32)+1][(player3->xpos/32)-1] != 6)
            && (field[(player3->ypos/32)-1][ player3->xpos/32]    != 6)
            && (field[(player3->ypos/32)-1][(player3->xpos/32)-1] != 6)
            && (field[ player3->ypos/32]   [(player3->xpos/32)+1] != 6)
            && (field[ player3->ypos/32]   [(player3->xpos/32)-1] != 6)
            ){
        enemy->xpos = player->xpos;
        enemy->ypos = player->ypos;
        field[player->ypos/32][player->xpos/32] = 6;
        field[player2->ypos/32][player2->xpos/32] = 6;
        field[player3->ypos/32][player3->xpos/32] = 6;
        player = enemy;
        player2 = NULL;
        player3 = NULL;
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
