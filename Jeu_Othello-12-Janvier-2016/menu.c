#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "menu.h"


/*
int showmenu(SDL_Surface* ecran, TTF_Font* font)
{
	Uint32 time;
	int x,y;
	const int NumMenu = 2;
	const char* labels[NumMenu] = {"Continue","Exit"};
	SDL_Surface* menus[NumMenu];
	bool select[NumMenu]={0,0};
	SDL_Color color[2] = {{255,255,255},{255,0,0}};
	
	menus[0] = TTF_RenderText_Solid(font,labels[0],color[0]);
	menus[1] = TTF_RenderText_Solid(font,labels[1],color[0]);
	SDL_Rect pos[NumMenu];
	pos[0].x=ecran->clip_rect.w/2 - menu[0]->clip_rect.w/2;
	pos[0].y=ecran->clip_rect.h/2 - menu[0]->clip_rect.h;
	pos[1].x=ecran->clip_rect.w/2 - menu[1]->clip_rect.w/2;
	pos[1].y=ecran->clip_rect.h/2 - menu[1]->clip_rect.h;
	
	SDL_FillRect(ecran,&ecran->clip_rect,SDL_MapRGB(ecran->format,0,0,0));
	SDL_Event event;
	while(1)
	{
		time=SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
		 switch(event.type)
			{
			 case SDL_QUIT:
			    SDL_FreeSurface(menu[0]);
			    SDL_FreeSurface(menu[1]);
			    return 1;
			 case SDL_MOUSEMOTION:
			    x=event.motion.x;
			    y=event.motion.y;
			    for(int i=0;i<NumMenu;i++)
			    {
				if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i]+pos[i].h)
				if(!select[i])
				{
				  select[i]=1;
				  SDL_Freesyrface(menu[i]);
				  menu[i]=TTF_RenderText_Solid(font,labels[i],color[1]);
					}else{select[i]=0;SDL_FreeSurface(menu[i]);
						menu[i]=TTF_RenderText_Solid(font,labels[i],color[0]);}
				}
			 case SDL_MOUSEBUTTONDOWN:
			    
			}
		}
	}
}
*/
int showmenu2(INPUT in)
{
	SDL_Surface *othello = NULL;
	SDL_Rect pos_othello;
	SDL_Event event;
	int running=1;int x,y;
	TTF_Font* police;
	SDL_Init(SDL_INIT_VIDEO);
	const int NUMMENU = 2;
	const char* labels[] = {"Continue","Exit"};
	SDL_Surface* menu[NUMMENU];
	SDL_Rect pos[NUMMENU];	
	int select[]={0,0};
	int i=0;
	
	//corps fonction
	/*creer 2 lignes pour afficher les start*/
	
	TTF_Init();
	
	in.screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
	SDL_WM_SetCaption("Bienvenue à Othello",NULL);

	/*afficher l'image de l'othello*/
	//othello = IMG_LOAD("othello.png");
	
	Uint32 blue=SDL_MapRGB(in.screen->format,139,134,130);
	pos_othello.x=in.screen->w / 2 - othello->w / 2;
	pos_othello.y=10; 

	SDL_FillRect(in.screen,NULL,blue);
	/*afficher les select*/
	police=TTF_OpenFont("police.ttf",20);
	SDL_Color color[2]={{1,1,1},{230,230,250}};
	for(i=0;i<NUMMENU;i++){
		menu[i] = TTF_RenderText_Blended(police,labels[i],color[0]);
	 	pos[i].x= in.screen->clip_rect.w/2 - menu[i]->clip_rect.w/2;
	 	pos[i].y= in.screen->clip_rect.h/2 - menu[i]->clip_rect.h+20*i;
	 	SDL_BlitSurface(menu[i],NULL,in.screen,&pos[i]);
	 }
	
	SDL_SetColorKey(othello,SDL_SRCCOLORKEY,blue);
	SDL_BlitSurface(othello,NULL,in.screen,&pos_othello);

	while(running)
	{
	  SDL_PollEvent(&event);
	  switch(event.type)
	  {
		case SDL_QUIT:
		running = 0;break;
		/*case SDL_MOUSEMOTION:
		x = event.motion.x;
		y = event.motion.y;
		for(int i;i < NUMMENU;i++)
		  if((x > pos[i].x) && (x < (pos[i].x+pos[i].w)) && (y > pos[i].y) && (y < (pos[i].y+pos[i].h)))
		    {menu[i] = TTF_RenderText_Blended(police,labels[i],color[1]);}
		  else
		    {menu[i] = TTF_RenderText_Blended(police,labels[i],color[0]);}
		    break;*/
		case SDL_MOUSEBUTTONDOWN:
		for(i=0;i<NUMMENU;i++)
		  if(event.button.button == SDL_BUTTON_LEFT)
		  {
		    if(event.button.x > pos[i].x && event.button.x < pos[i].x+pos[i].w && event.button.y > pos[i].y && event.button.y < pos[i].y + pos[i].h)
		     {
			if(select[i])
			SDL_BlitSurface(menu[i],NULL,in.screen,&pos[i]);
		        select[i]=1;
			}
		  }break;
		case SDL_MOUSEBUTTONUP:
			if(select[0]==1)
			  {
				fprintf(stderr,"commencer l'Othello\n");
				}
			if(select[1]==1)
			{
				running = 0;
				break;
			}
		  default:
			break;
	  }
	SDL_Flip(in.screen);
	}
	for(i=0;i<NUMMENU;i++)
	  fprintf(stderr,"la valeur select[%d]:%d\n",i,select[i]);
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_FreeSurface(othello);
	for(i=0;i<NUMMENU;i++)
	 SDL_FreeSurface(menu[i]);
	SDL_Quit();
	return 0;
}
