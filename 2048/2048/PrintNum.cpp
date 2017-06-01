#include"2048Head.h"

extern char gMediaPath[256];
extern SDL_Rect *gMainWindow;
extern SDL_Renderer *gMainRenderer;

void PrintNum(int num, char filename[], int x, int y)
{
	char Num[8];
	SDL_Rect NumRect;
	SDL_Color color = { 255,255,255,0 };
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	SDL_itoa(num, Num, 10);
	NumRect.x = x;
	NumRect.y = y;
	TTF_Font *textfont;
	TTF_Init();
	textfont = TTF_OpenFont(filename, 50);
	surface = TTF_RenderText_Blended(textfont, Num, color);
	TTF_CloseFont(textfont);
	texture = SDL_CreateTextureFromSurface(gMainRenderer, surface);
	SDL_FreeSurface(surface);
	NumRect.w = 30;
	NumRect.h = 80;
	SDL_RenderCopy(gMainRenderer, texture, NULL, &NumRect);
	SDL_RenderPresent(gMainRenderer);
	SDL_DestroyTexture(texture);
	TTF_Quit();
}