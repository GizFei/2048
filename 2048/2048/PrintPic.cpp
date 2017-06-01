#include"2048Head.h"

extern char gMediaPath[256];
extern SDL_Rect *gMainWindow;
extern SDL_Renderer *gMainRenderer;
void PrintPic(char filename[], SDL_Rect *TextureRect, SDL_Rect *RendererRect)
{
	SDL_Surface *surface=NULL;
	SDL_Texture *texture=NULL;

	surface = SDL_LoadBMP(filename);
	texture = SDL_CreateTextureFromSurface(gMainRenderer, surface);
	SDL_FreeSurface(surface);
	SDL_RenderCopy(gMainRenderer, texture, TextureRect, RendererRect);
	SDL_RenderPresent(gMainRenderer);
	SDL_DestroyTexture(texture);
}