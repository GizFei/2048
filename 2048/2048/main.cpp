#include<stdio.h>
#include"SDL.h"
#include"2048Head.h"
#define SDL_MAIN_HANDLED
#pragma comment(lib,"SDL2.lib")

int gameover = 0;
int GamewinPara = 1;
char gMediaPath[256];
SDL_Rect gMainWinRect = { 500,100,640,480 };
SDL_Window *gMainWindow=NULL;
SDL_Renderer *gMainRenderer=NULL;
typedef struct
{
	int mousex;
	int mousey;
	int mousedown;
	char keypressed;
}UIState;
UIState uistate;
int Matrix[4][4] = {
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0
};
int TempM[4][4];
int FrontM[4][4];

void runMainLoop();
void handleEvent(SDL_Event *e);
void display();
void Perform2048(char key);
void initApp();
void endApp();
void UpdataApp();

int main(int argc, char *argv[])
{
	initApp();
	Perform2048('I');
	CopyMatrix();
	CopyFrontMatrix();
	runMainLoop();
	SDL_Delay(2000);
	endApp();
	return 0;
}

void runMainLoop()
{
	SDL_Event e;
	int gamewin = 0;
	while (!gameover)
	{
		while (!gameover&&SDL_PollEvent(&e))
		{
			if ((e.type == SDL_KEYUP&&e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT||ifGameover())
			{
				gameover = 1;
				if(gameover==1&&ifGameover()) Gameover();
			}
			if (gamewin == 1)
			{
				gamewin = 0;
				SDL_RenderClear(gMainRenderer);
				UpdataApp();
				display();
			}
			if (Gamewin()&&GamewinPara==1)
			{
				ShowWin();
				gamewin = 1;
				GamewinPara = 0;
			}
			handleEvent(&e);
		}
		SDL_Delay(10);
	}
}

void handleEvent(SDL_Event *e)
{
	switch (e->type)
	{
	case SDL_MOUSEMOTION:
		uistate.mousex = e->motion.x;
		uistate.mousey = e->motion.y;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (e->button.button == 1)
			uistate.mousedown = 1;
		ButtonPress(uistate.mousedown,uistate.mousex, uistate.mousey);
		break;
	case SDL_MOUSEBUTTONUP:
		if (e->button.button == 1)
			uistate.mousedown = 0;
		ButtonPerform(uistate.mousex, uistate.mousey);
		ButtonPress(uistate.mousedown, uistate.mousex, uistate.mousey);
		display();
		break;
	case SDL_KEYDOWN:
			uistate.keypressed = e->key.keysym.sym;
			CopyFrontMatrix();
			Perform2048(uistate.keypressed);
			if (CompareM()) break;
			UpdataMatrix();
			CopyMatrix();
			display();
			break;
	default:
			uistate.keypressed = 'A';
			break;
	}
	return ;
}

void display()
{
	SDL_Rect TextureRect = { 0,0,100,100 };
	SDL_Rect RendererRect = { 120,35,100,100 };

	{
		Print(Matrix[0][0], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[0][1], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[0][2], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[0][3], TextureRect, RendererRect);
	}
	RendererRect.x = 120;
	RendererRect.y += RendererRect.h + 1;
	{
		Print(Matrix[1][0], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[1][1], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[1][2], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[1][3], TextureRect, RendererRect);
	}
	RendererRect.x = 120;
	RendererRect.y += RendererRect.h + 1;
	{
		Print(Matrix[2][0], TextureRect, RendererRect);

		RendererRect.x += RendererRect.w + 1;

		Print(Matrix[2][1], TextureRect, RendererRect);

		RendererRect.x += RendererRect.w + 1;

		Print(Matrix[2][2], TextureRect, RendererRect);

		RendererRect.x += RendererRect.w + 1;

		Print(Matrix[2][3], TextureRect, RendererRect);
	}
	RendererRect.x = 120;
	RendererRect.y += RendererRect.h + 1;
	{
		Print(Matrix[3][0], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[3][1], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[3][2], TextureRect, RendererRect);
		RendererRect.x += RendererRect.w + 1;
		Print(Matrix[3][3], TextureRect, RendererRect);
	}
}

void Perform2048(char key)
{
	switch (key)
	{
	case 'I':
		InitMatrix();
		display();
		break;
	case 'R':
		PerformMatrix('w');
		break;
	case 'Q':
		PerformMatrix('s');
		break;
	case 'O':
		PerformMatrix('d');
		break;
	case 'P':
		PerformMatrix('a');
		break;
	default:
		return;
	}
	return ;
}

void initApp()
{
	SDL_Surface *iconSurface;
	SDL_Rect iconRect = { 0,0,30,20 };
	SDL_Init(SDL_INIT_VIDEO);
	gMainWindow = SDL_CreateWindow("2048", gMainWinRect.x, gMainWinRect.y, gMainWinRect.w, gMainWinRect.h, 0);
	gMainRenderer = SDL_CreateRenderer(gMainWindow, -1, SDL_RENDERER_ACCELERATED);
	iconSurface = SDL_LoadBMP("..\\..\\Media\\Pic\\2048icon1.bmp");
	SDL_SetWindowIcon(gMainWindow, iconSurface);
	SDL_FreeSurface(iconSurface);
	PrintPic("..\\..\\Media\\Pic\\Background.bmp", NULL, NULL);
	PrintPic("..\\..\\Media\\Pic\\2048icon.bmp", NULL, &iconRect);
	AddButton(gMainRenderer);
}

void endApp()
{
	SDL_DestroyWindow(gMainWindow);
	SDL_DestroyRenderer(gMainRenderer);
	SDL_Quit();
}

void UpdataApp()
{
	SDL_Surface *iconSurface;
	SDL_Rect iconRect = { 0,0,30,20 };
	PrintPic("..\\..\\Media\\Pic\\Background.bmp", NULL, NULL);
	PrintPic("..\\..\\Media\\Pic\\2048icon.bmp", NULL, &iconRect);
	AddButton(gMainRenderer);
}