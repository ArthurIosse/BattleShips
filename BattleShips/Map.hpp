#ifndef Map_hpp
#define Map_hpp

#include "Game.hpp"




class Map {
public:
    Map(int arr[20][25]);
    ~Map();
    
    void LoadMap(int arr[20][25]);
    void DrawMap();
    
private:
    SDL_Rect src,dest;
    SDL_Texture * dirt;
    SDL_Texture * water;
    SDL_Texture * grass;
    SDL_Texture * one;
    SDL_Texture * two;
    SDL_Texture * three;
    SDL_Texture * four;
    SDL_Texture * five;
    SDL_Texture * six;
    SDL_Texture * seven;
    SDL_Texture * eight;
    SDL_Texture * nine;
    SDL_Texture * ten;
    SDL_Texture * a;
    SDL_Texture * b;
    SDL_Texture * c;
    SDL_Texture * d;
    SDL_Texture * e;
    SDL_Texture * f;
    SDL_Texture * g;
    SDL_Texture * h;
    SDL_Texture * i;
    SDL_Texture * j;
//    SDL_Texture * ship1;
//    SDL_Texture * ship2;
//    SDL_Texture * ship3;
//    SDL_Texture * ship4;
    
    

    int map[20][25];
};

#endif /* Map_hpp */
