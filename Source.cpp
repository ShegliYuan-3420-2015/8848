#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "header.h"


using namespace std;

enum KeyPressSurfaces
{ KEY_PRESS_SURFACE_UP,
KEY_PRESS_SURFACE_DOWN
};


bool init();
bool loadMedia();

SDL_Texture *loadTexture(string path);
SDL_Window* window = NULL;
SDL_Renderer* rend = NULL;
SDL_Texture* text = NULL;
SDL_Texture* text2 = NULL;
SDL_Texture* back = NULL;
SDL_Texture* winner = NULL;


bool init()
{

bool success = true;
if(SDL_Init(SDL_INIT_VIDEO) < 0)
	success = false;
else
{

	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200,1000, SDL_WINDOW_SHOWN );
	if(window == NULL)
	success = false;
	else
	{
		rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
		if(rend == NULL)
			success = false;
		else
		{
		SDL_SetRenderDrawColor(rend,255,255,255,0);
		}
	}
}
return success;
}

bool loadMedia()
{
	bool success = true;
	text = loadTexture("swords.png");
	if(text == NULL)
		success = false;
	text2 = loadTexture("sheild.png");
	if(text2 == NULL)
		success = false;
	winner = loadTexture("win.png");
	if(winner == NULL)
		success = false;
	back = loadTexture("pirates.png");
	if(back == NULL)
		success = false;
	return success;
	
}

SDL_Texture* loadTexture(string path)
{
	SDL_Texture* temp = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface != NULL)
		temp = SDL_CreateTextureFromSurface(rend,loadedSurface);

	SDL_FreeSurface(loadedSurface);
	return temp;
}
void draw_rect()
{
 SDL_Rect rect = { 100,100,600,600};
 SDL_RenderDrawRect(rend,&rect);
 for(int i = 0; i < 5; i++)
 {
 SDL_RenderDrawLine(rend,100,i*100+200,700,i*100+200);
 SDL_RenderDrawLine(rend,i*100+200,100,i*100+200,700);
 }
 }


int main(int argc, char* args[])
{

	int player,computer;
	computer = 1;
	player = 0;
	record rec;
	int x,y;
	SDL_Event e;
	bool win = false;
	bool quit = false;
	SDL_Rect s,c,w;
    
	c.x = 1000;
	c.y = 100;
	c.w = 100;
	c.h = 100;

	s.y = 100;
	s.w = 100;
	s.h = 100;
    w.x = 200;
	w.y = 200;
	w.w = 400;
	w.h = 400;
 cout <<"good";
	if(!init())
cout <<"error";
else
{
if(!loadMedia())
	cout<<"image load failed";
else
{
	
SDL_RenderCopy(rend,back,NULL,NULL);
draw_rect();

while(!quit)
{
while(SDL_PollEvent(&e) != 0)
{
if(e.type == SDL_QUIT)
	quit = true;
else if(e.type  == SDL_MOUSEBUTTONDOWN)
{
	if(e.button.button == SDL_BUTTON_LEFT)
	{
	x = e.button.x;
	y = e.button.y;

	rec.player_move(x,y,&s);
   SDL_RenderCopy(rend,text,NULL,&s);

   rec.computer_move();
   SDL_RenderCopy(rend,text2,NULL,&c);
}
	
	//SDL_RenderCopy(rend,winner,NULL,&w);
	}
}
 SDL_RenderPresent(rend);
}
}
}//while
return 0;
}