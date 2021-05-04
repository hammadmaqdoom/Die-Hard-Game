#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include"menu.hpp"
#include"enemy.hpp"
#include"health.hpp"
#include "DragonBallz.hpp"
#include "TextureManager.h"

using namespace std;
class Game{
    string state = "MainMenu"; //to check state of the game
    public:
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    static SDL_Renderer* gRenderer;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //Main menu
    SDL_Texture* main_menuTexture = NULL;
    
    
    //play
    //SDL_Texture* playTexture = NULL;
    //control
    SDL_Texture* controlsTexture = NULL;
    //Credits
    SDL_Texture* creditsTexture = NULL;
    //Quit
    SDL_Texture* quitTexture = NULL;
    //choose character
    SDL_Texture* SelectCharacterTexture = NULL;
    SDL_Texture* GokuTexture = NULL; //Goku
    SDL_Texture* VegetaTexture = NULL; //Vegeta
    SDL_Texture* PicoloTexture = NULL; //Picolo

    //Sprite sheets
    SDL_Texture* Goku1 = NULL;
    SDL_Texture* Vegeta1 = NULL;
    SDL_Texture* Picolo1 = NULL;

    //enemy Health texture
    SDL_Texture* HealthTexture1 = NULL;
    SDL_Texture* HealthTexture2 = NULL;
    SDL_Texture* HealthTexture3 = NULL;
    SDL_Texture* HealthTexture0 = NULL;
    //player health texture
    SDL_Texture* HealthTexture4 = NULL;
    SDL_Texture* HealthTexture5 = NULL;
    SDL_Texture* HealthTexture6 = NULL;
    SDL_Texture* HealthTexture7 = NULL;

    //Enemy Texture
    SDL_Texture* EnemyTexture = NULL;
    //bg textures
    SDL_Texture* bgTexture1 = NULL;
    SDL_Texture* PauseTexture0 = NULL;
    SDL_Texture* PauseTexture1 = NULL;
    SDL_Texture* PauseTexture2 = NULL;

    //lose/win
    SDL_Texture* LoseTexture = NULL;
    SDL_Texture* WinTexture = NULL;

    
    
    //Music
    Mix_Music *introMusic = NULL;
    Mix_Music *startMusic = NULL;
    Mix_Music *selectSound = NULL;
    Mix_Music *exitSound = NULL;
    Mix_Music *winSound = NULL;
    Mix_Music *loseSound = NULL;
    Enemy enemy;


    bool init();
    bool loadMedia(); //loads media
    void close(); // closes the game, free space
    void run(); //main game logic
    void check_collision(Player*, Enemy*);
    void destroyObj();
};

