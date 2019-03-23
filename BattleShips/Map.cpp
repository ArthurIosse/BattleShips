#include "Map.hpp"
#include "textureManager.hpp"

//int field[20][25] =
//         {{1,21,22,23,24,25,26,27,28,29,30,1,2,1,1,1,1,1,1,1,1,1,1,1,1},
//          {11,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {12,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {13,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {14,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {15,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {16,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {17,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {18,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {19,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {20,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
//          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,44,44,44,44,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,43,43,43,1,41,1,41,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,43,43,43,1,41,1,41,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,42,42,1,42,42,1,42,42,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//};

Map::Map(int field[20][25])
{
    dirt = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/dirt.png");
    water = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/water.png");
    grass = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/grass.png");
    
    one = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/1.png");
    two = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/2.png");
    three = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/3.png");
    four = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/4.png");
    five = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/5.png");
    six = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/6.png");
    seven = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/7.png");
    eight = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/8.png");
    nine = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/9.png");
    ten = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/10.png");
    a  = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/A.png");
    b = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/B.png");
    c = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/C.png");
    d = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/D.png");
    e = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/E.png");
    f = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/F.png");
    g = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/G.png");
    h = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/H.png");
    i = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/I.png");
    j = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/Numbers/J.png");
    ship1 = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/ship.png");
    ship2 = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/ship.png");
    ship3 = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/ship.png");
    ship4 = textureManager::LoadTexture("/Users/Arthur/workspace/BattleShips/assets/ship.png");
    
    
    
    LoadMap(field);
    
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
    for(int row = 0 ; row < 20 ; row++){
        for(int col = 0 ; col < 25 ; col++){
            
            type = map[row][col];
            dest.x = col*32;
            dest.y = row*32;
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
                    
                case 11:
                    textureManager::Draw(one, src, dest);
                    break;
                case 12:
                    textureManager::Draw(two, src, dest);
                    break;
                case 13:
                    textureManager::Draw(three, src, dest);
                    break;
                case 14:
                    textureManager::Draw(four, src, dest);
                    break;
                case 15:
                    textureManager::Draw(five, src, dest);
                    break;
                case 16:
                    textureManager::Draw(six, src, dest);
                    break;
                case 17:
                    textureManager::Draw(seven, src, dest);
                    break;
                case 18:
                    textureManager::Draw(eight, src, dest);
                    break;
                case 19:
                    textureManager::Draw(nine, src, dest);
                    break;
                case 20:
                    textureManager::Draw(ten, src, dest);
                    break;
                case 21:
                    textureManager::Draw(a, src, dest);
                    break;
                case 22:
                    textureManager::Draw(b, src, dest);
                    break;
                case 23:
                    textureManager::Draw(c, src, dest);
                    break;
                case 24:
                    textureManager::Draw(d, src, dest);
                    break;
                case 25:
                    textureManager::Draw(e, src, dest);
                    break;
                case 26:
                    textureManager::Draw(f, src, dest);
                    break;
                case 27:
                    textureManager::Draw(g, src, dest);
                    break;
                case 28:
                    textureManager::Draw(h, src, dest);
                    break;
                case 29:
                    textureManager::Draw(i, src, dest);
                    break;
                case 30:
                    textureManager::Draw(j, src, dest);
                    break;
                case 41:
                    textureManager::Draw(ship1, src, dest);
                case 42:
                    textureManager::Draw(ship2, src, dest);
                case 43:
                    textureManager::Draw(ship3, src, dest);
                case 44:
                    textureManager::Draw(ship4, src, dest);
                default:
                    break;
            }
        }
    }
}




//{{1,21,22,23,24,25,26,27,28,29,30,1,2,1,21,22,23,24,25,26,27,28,29,30,1},
//    {11,0,0,0,0,0,0,0,0,0,0,1,2,11,0,0,0,0,0,0,0,0,0,0,1},
//    {12,0,0,0,0,0,0,0,0,0,0,1,2,12,0,0,0,0,0,0,0,0,0,0,1},
//    {13,0,0,0,0,0,0,0,0,0,0,1,2,13,0,0,0,0,0,0,0,0,0,0,1},
//    {14,0,0,0,0,0,0,0,0,0,0,1,2,14,0,0,0,0,0,0,0,0,0,0,1},
//    {15,0,0,0,0,0,0,0,0,0,0,1,2,15,0,0,0,0,0,0,0,0,0,0,1},
//    {16,0,0,0,0,0,0,0,0,0,0,1,2,16,0,0,0,0,0,0,0,0,0,0,1},
//    {17,0,0,0,0,0,0,0,0,0,0,1,2,17,0,0,0,0,0,0,0,0,0,0,1},
//    {18,0,0,0,0,0,0,0,0,0,0,1,2,18,0,0,0,0,0,0,0,0,0,0,1},
//    {19,0,0,0,0,0,0,0,0,0,0,1,2,19,0,0,0,0,0,0,0,0,0,0,1},
//    {20,0,0,0,0,0,0,0,0,0,0,1,2,20,0,0,0,0,0,0,0,0,0,0,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
