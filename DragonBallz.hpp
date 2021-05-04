#include<SDL.h>
#include <vector>
#include"player.hpp"
#include"goku.hpp"
#include"vegeta.hpp"
#include"picolo.hpp"
using namespace std;

class DragonBallz{
    SDL_Renderer *gRenderer;
    SDL_Renderer *bgRenderer;
    SDL_Texture *assets;
    
    public:
    DragonBallz(SDL_Renderer *, SDL_Texture *);
    //void drawObjects(); 
    //void createObject(int, int);
};