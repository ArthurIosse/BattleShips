#include "Map.hpp"
#include "textureManager.hpp"

int lvl1[20][25] =
         {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

Map::Map()
{
    dirt = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/dirt.png");
    water = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/water.png");
    grass = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/grass.png");
    
    LoadMap(lvl1);
    
    src.x = 0;
    src.y = 0;
    src.h = 32;
    src.w = 32;
    
    dest.x =0;
    dest.y = 0;
    dest.h = 32;
    dest.w = 32;
}

Map::~Map()
{
    
}

void Map::LoadMap(int arr[20][25])
{
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 25 ; j++){
            map[i][j] = arr[i][j];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 25 ; j++){
            
            type = map[i][j];
            dest.x = j*32;
            dest.y = i*32;
            switch(type){
                case 0:
                    textureManager::Draw(water, src, dest);
                    break;
                case 1:
                    textureManager::Draw(dirt, src, dest);
                    break;
                case 2:
                    textureManager::Draw(grass, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
