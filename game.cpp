#include "game.hpp"

SDL_Renderer* Game::gRenderer = NULL;
Player* p; //Player class pointer to assign pointer of selected player
Goku* p1;
Vegeta* p2;
Picolo* p3;
Health 
health (2,2,150,60),
pHealth (820,2,150,60);
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Die Hard", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL)
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );


				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
		
	}
	return success;
}

void Game :: check_collision(Player* p, Enemy* e) //Checking Collision between Enemy and Player and Reducing Health accordingly
{
	SDL_Rect* pmover = p->getmover(); //player
	SDL_Rect* emover = e->getmover(); //enemy
	std::cout<<pmover->x<<endl;
	if (pmover->x == emover->x  ) 
	{
		e->action();
		if (p->kick || p->punch)
		health--;
		if (p->defend == false)
		{
			cout<<"decrase health of player"<<endl;
			if (e->kick || e->punch)
			{	
				pHealth--;
				e->punch = false;
				e->kick = false;
			}
		}
		
		
		
		}			
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	//loading Textures
	//assets = loadTexture("assets.png");
    gTexture = TextureManager::LoadTexture("images//goku-bg.jpg");
	main_menuTexture = TextureManager::LoadTexture("images//MainMenu.jpeg");
	controlsTexture = TextureManager::LoadTexture("images//Controls.jpeg");
	creditsTexture = TextureManager::LoadTexture("images//Credits.jpeg");
	quitTexture = TextureManager::LoadTexture("images//quit.jpeg");
	SelectCharacterTexture = TextureManager::LoadTexture("images//SelectCharacter0.jpeg");
	GokuTexture = TextureManager::LoadTexture("images//SelectCharacter1.jpeg");
	VegetaTexture = TextureManager::LoadTexture("images//SelectCharacter2.jpeg");
	PicoloTexture = TextureManager::LoadTexture("images//SelectCharacter3.jpeg");
	bgTexture1 = TextureManager::LoadTexture("images//bg.png");
	PauseTexture0 = TextureManager::LoadTexture("images//pause0.jpeg");
	PauseTexture1 = TextureManager::LoadTexture("images//pause1.jpeg");
	PauseTexture2 = TextureManager::LoadTexture("images//pause2.jpeg");
	//Players
	Goku1 = TextureManager::LoadTexture("sprites//gokuu.png");
	Vegeta1 = TextureManager::LoadTexture("sprites//vegeta1.png");
	Picolo1 = TextureManager::LoadTexture("sprites//pikolo.png");

	//Health
	HealthTexture0 = TextureManager::LoadTexture("images//health_left_6.png");
	HealthTexture1 = TextureManager::LoadTexture("images//health_left_5.png");
	HealthTexture2 = TextureManager::LoadTexture("images//health_left_3.png");
	HealthTexture3 = TextureManager::LoadTexture("images//health_left_1.png");

	HealthTexture4 = TextureManager::LoadTexture("images//health_right_6.png");
	HealthTexture5 = TextureManager::LoadTexture("images//health_right_5.png");
	HealthTexture6 = TextureManager::LoadTexture("images//health_right_3.png");
	HealthTexture7 = TextureManager::LoadTexture("images//health_right_1.png");
	//Enemy
	EnemyTexture = TextureManager::LoadTexture("sprites//cell-jr.png");

	// Win and lose
	WinTexture = TextureManager::LoadTexture("images//win.jpeg");
	LoseTexture = TextureManager::LoadTexture("images//lose.jpeg");
	if(gTexture==NULL || main_menuTexture == NULL || controlsTexture == NULL || 
	creditsTexture == NULL || quitTexture == NULL || SelectCharacterTexture == NULL || 
	GokuTexture == NULL || VegetaTexture == NULL || PicoloTexture == NULL ||
	Goku1 == NULL || Vegeta1 == NULL || Picolo1 == NULL || PauseTexture1 == NULL
	|| HealthTexture7 == NULL || HealthTexture6 == NULL || HealthTexture5 == NULL || HealthTexture4 == NULL || HealthTexture3 == NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	introMusic = Mix_LoadMUS( "audios//intro.wav" );
	selectSound = Mix_LoadMUS( "audios//Snd6.wav" );
	startMusic = Mix_LoadMUS( "audios//ominous-drums.wav" );
	exitSound = Mix_LoadMUS( "audios//select.wav" );
	loseSound = Mix_LoadMUS( "audios//player-losing.wav" );
	winSound = Mix_LoadMUS( "audios//levelcomplete2.wav" );

	if(introMusic == NULL || selectSound == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	//Free loaded images
	// SDL_DestroyTexture(assets);
	SDL_DestroyTexture(gTexture);
	SDL_DestroyTexture(main_menuTexture);
	SDL_DestroyTexture(controlsTexture);
	SDL_DestroyTexture(creditsTexture);
	SDL_DestroyTexture(quitTexture);
	SDL_DestroyTexture(SelectCharacterTexture);
	SDL_DestroyTexture(GokuTexture);
	SDL_DestroyTexture(VegetaTexture);
	SDL_DestroyTexture(PicoloTexture);
	SDL_DestroyTexture(bgTexture1);
	SDL_DestroyTexture(Goku1);
	SDL_DestroyTexture(Vegeta1);
	SDL_DestroyTexture(Picolo1);
	SDL_DestroyTexture(PauseTexture0);
	SDL_DestroyTexture(PauseTexture1);
	SDL_DestroyTexture(PauseTexture2);
	SDL_DestroyTexture(HealthTexture0);
	SDL_DestroyTexture(HealthTexture1);
	SDL_DestroyTexture(HealthTexture2);
	SDL_DestroyTexture(HealthTexture3);
	SDL_DestroyTexture(HealthTexture4);
	SDL_DestroyTexture(HealthTexture5);
	SDL_DestroyTexture(HealthTexture6);
	SDL_DestroyTexture(HealthTexture7);
	SDL_DestroyTexture(EnemyTexture);
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	// Mix_FreeMusic(introMusic);
	// introMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}


// Player* p;
void Game::run( )
{
	string player;
	
	//creating objects of players
	p1 = new Goku(30, 75, 145, 150);
	p2 = new Vegeta(30, 75, 110, 155);
	p3 = new Picolo(30, 75, 130, 150);

	
	
	bool quit = false; // quit
	SDL_Event e;
	Menu mainMenu, prompt, characterMenu, pauseMenu; //Menu Objects
	// creating Buttons
	Buttons Play(145 , 240, 235, 270, "Play"), 
	Control(145 , 305, 320, 330, "Controls"), 
	Credits(145 , 380, 285, 410, "Credits"), 
	Exit(145 , 455, 220, 480, "Exit"),
	Yes(400, 300, 505, 320, "Yes"),
	No(550, 300, 650, 320, "No"),
	selectGoku(180, 255, 380, 470, "Goku"),
	selectVegeta(410, 255, 590, 470, "Vegeta"),
	selectPicolo(630, 255, 815, 470, "Picolo"),
	resume(441, 265, 559, 288, "resume"),
	quitTomain(353, 305, 647, 330, "main");

	//Adding buttons to the list of buttons
	mainMenu.add_btns(&Play);
	mainMenu.add_btns(&Control);
	mainMenu.add_btns(&Credits);
	mainMenu.add_btns(&Exit);
	prompt.add_btns(&Yes);
	prompt.add_btns(&No);
	characterMenu.add_btns(&selectGoku);
	characterMenu.add_btns(&selectVegeta);
	characterMenu.add_btns(&selectPicolo);
	pauseMenu.add_btns(&resume);
	pauseMenu.add_btns(&quitTomain);
	
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
	SDL_RenderPresent(gRenderer);
	Mix_PlayMusic( introMusic, 1 ); //plays music
	SDL_Delay(5000);
	while( !quit )
	{

		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if (state == "runing")
			enemy.move();
			// user requests to go back
			if(e.type == SDL_KEYDOWN){		
				if (e.key.keysym.sym == SDLK_ESCAPE){ //checks for ESC key pressed
					if (state == "runing" )
						state ="pause";
					else if (state =="pause")
						state ="pause";
					else if (state == "MainMenu")
						state = "Exit";
					else state = "MainMenu";
				}
				if (state == "runing"){
					if (player == "p"){
						p->move(&e); //move funtionality of player
						enemy.move();
						check_collision(p, &enemy);
					
						if(health.count == 1){
							state = "win";
							Mix_PlayMusic( winSound, 1 );
						}
						else if(pHealth.count == 1){
							state = "lose";
							Mix_PlayMusic( loseSound, 1 );
						}
						if (e.key.keysym.sym == SDLK_x)
							p->kick = true; //enabling kick
						
						
						if (e.key.keysym.sym == SDLK_f)
							p->defend = true; //enabling defence
						
						if (e.key.keysym.sym == SDLK_z)
							p->punch = true; //enabling punch

					}
					
				}
			}
		}
		if (player =="p"){
			if (p->defend)
				p->action(1); //call for defence that was enabled above of keypress event
				
			else if (p->kick)
				p->action(2);//call for kick that was enabled above of keypress event

			else if (p->punch)
				p->action(3);//call for punch that was enabled above of keypress event

			else 
				p->action(0); //idle
			}
		
		
		if(e.type == SDL_MOUSEBUTTONDOWN){
			int xMouse, yMouse;
			string id; // button id

			SDL_GetMouseState(&xMouse,&yMouse);
			cout<<xMouse<<" "<<yMouse<<endl;

			if (state == "MainMenu"){
				id = mainMenu.check(xMouse, yMouse); //check for mainMenu buttons
				if (id != "FALSE"){
				Mix_PlayMusic( selectSound, 1 );
				}
			}

			if (state == "Exit"){
				id = prompt.check(xMouse, yMouse); //check for prompt buttons
				if (id != "FALSE"){
				Mix_PlayMusic( exitSound, 1 );
				}
			}

			if (state == "Play"){
				id = characterMenu.check(xMouse, yMouse); //check for characterMenu buttons
				if (id != "FALSE"){
				Mix_PlayMusic( selectSound, 1 );
				}
			}

			if (state == "pause"){
				id = pauseMenu.check(xMouse, yMouse); //check for pauseMenu buttons
				if (id != "FALSE"){
				Mix_PlayMusic( selectSound, 1 );
				}
			}
			
			//Play
			if (id == "Play" && state == "MainMenu"){
				cout<<"Play"<<endl;
				state = "Play";
				p1->reset();
				p2->reset();
				p3->reset();
				enemy.reset();
				health.reset();
				pHealth.reset();

			}

			//Controls
			if (id == "Controls" && state == "MainMenu"){
				state = "Controls";
				cout<<"Controls"<<endl;
			}

			//Credits
			if (id == "Credits" && state == "MainMenu"){
				state = "Credits";
				cout<<"Credits"<<endl;
			}

			//Exit
			if (id == "Exit" && state == "MainMenu"){
				state = "Exit";
				cout<<"Exit"<<endl;
			}

			//Exit Yes
			if (id == "Yes" && state == "Exit"){
				quit = true;
			}
			// Exit No
			if (id == "No" && state == "Exit"){
				state = "MainMenu";
			}

			//Goku selected
			if (id == "Goku" && state == "Play"){
				state = "Goku";
				player = "p";
				
			}

			//Vegeta selected
			if (id == "Vegeta" && state == "Play"){
				state = "Vegeta";
				player = "p";
				
			}

			//Picolo selected
			if (id == "Picolo" && state == "Play"){
				state = "Picolo";
				player = "p";
			}

			//Resume game
			if (id =="resume" && state == "pause"){
				state = "runing";
			}

			//Quit to main menu and start new game
			if (id =="main" && state == "pause"){
				state = "MainMenu";
			}
			
		}
		

		SDL_RenderClear(gRenderer); //removes everything from renderer
		
		if (state == "MainMenu"){
			SDL_RenderCopy(gRenderer, main_menuTexture, NULL, NULL); //Draws background to renderer
		}

		if (state == "Play"){
			SDL_RenderCopy(gRenderer,SelectCharacterTexture, NULL, NULL);
		}

		if (state == "runing"){
			
			SDL_RenderCopy(gRenderer, bgTexture1, NULL, NULL); //background of running game
			if (p->player_name == "Goku"){
			SDL_RenderCopy(gRenderer, Goku1, p1->getsrc(), p1->getmover());
			}
			if (p->player_name  == "Vegeta"){
			SDL_RenderCopy(gRenderer, Vegeta1, p2->getsrc(), p2->getmover());
			}
			if (p->player_name  == "Picolo"){
			SDL_RenderCopy(gRenderer, Picolo1, p3->getsrc(), p3->getmover());
			}
			enemy.draw(gRenderer, EnemyTexture);
			if (health.getCount() == 4) health.draw(gRenderer, HealthTexture3);
			else if (health.getCount() == 3) health.draw(gRenderer, HealthTexture2);
			else if (health.getCount() == 2) health.draw(gRenderer, HealthTexture1);
			else if (health.getCount() <= 1) health.draw(gRenderer, HealthTexture0);

			if (pHealth.getCount() == 4) pHealth.draw(gRenderer, HealthTexture7);
			else if (pHealth.getCount() == 3) pHealth.draw(gRenderer, HealthTexture6);
			else if (pHealth.getCount() == 2) pHealth.draw(gRenderer, HealthTexture5);
			else if (pHealth.getCount() <= 1) pHealth.draw(gRenderer, HealthTexture4);
		}

		if ( state == "resume"){
		SDL_RenderCopy(gRenderer, PauseTexture1, NULL, NULL);
		state = "runing";
		}
		if (state == "main"){
		SDL_RenderCopy(gRenderer, PauseTexture2, NULL, NULL);
		state = "MainMenu";
		}

		if (state == "Goku"){
			p = p1;  //assigning slected player to player pointer
			p->player_name = "Goku";
			SDL_RenderCopy(gRenderer,GokuTexture, NULL, NULL);
			Mix_PlayMusic( startMusic, 1 );
			state = "runing";
		}
		if (state == "Vegeta"){
			p = p2; //assigning slected player to player pointer
			p->player_name = "Vegeta";
			SDL_RenderCopy(gRenderer,VegetaTexture, NULL, NULL);
			Mix_PlayMusic( startMusic, 1 );
			state = "runing";
		}
		if (state == "Picolo"){
			p = p3; //assigning slected player to player pointer
			p->player_name = "Picolo";
			SDL_RenderCopy(gRenderer,PicoloTexture, NULL, NULL);
			Mix_PlayMusic( startMusic, 1 );
			state = "runing";
		}
		
		if (state == "Controls"){
			SDL_RenderCopy(gRenderer, controlsTexture, NULL, NULL);
		}
		
		if (state == "Credits"){
			SDL_RenderCopy(gRenderer, creditsTexture, NULL, NULL);
		}

		if (state == "Exit"){
			SDL_RenderCopy(gRenderer, quitTexture, NULL, NULL);
		}

		if (state == "pause"){
			SDL_RenderCopy(gRenderer, PauseTexture0, NULL, NULL);
		}	

		if (state == "win"){
			SDL_RenderCopy(gRenderer, WinTexture, NULL, NULL);
			
			// state = "MainMenu";
		}

		if (state == "lose"){
			SDL_RenderCopy(gRenderer, LoseTexture, NULL, NULL);
			
			// state = "MainMenu";
		}
		
		//***********************draw the objects here********************
		
		//dragonballz.drawObjects();

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer
	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}

void Game::destroyObj(){ //deletes pointers and objects created dynamically
	delete &pHealth;
	delete &health;
	delete p;
	delete p1;
	delete p2;
	delete p3;
}
