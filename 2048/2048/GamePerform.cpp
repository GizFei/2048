#include"2048Head.h"

extern int Matrix[4][4];
extern SDL_Renderer *gMainRenderer;
extern int FrontM[4][4];
extern int gameover;

bool ifGameover()
{
	int i, j;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (Matrix[i][j] == Matrix[i][j + 1]) return 0;
		}
	}
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (Matrix[i][j] == Matrix[i + 1][j]) return 0;
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Matrix[i][j] == 0) return 0;
		}
	}
	return 1;
}

void Gameover()
{
	SDL_Rect RendererRect = { 121,180,400,120 };
	PrintPic("..\\..\\Media\\Pic\\Gameover.bmp", NULL, &RendererRect);
}

void ButtonPerform(int mousex, int mousey)
{
	if (mousex >= 35 && mousex <= 85 && mousey >= 35 && mousey <= 85) Reset();
	else if (mousex >= 35 && mousex <= 85 && mousey >= 110 && mousey <= 160) RegretOne();
	return;
}

void Reset()
{
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			Matrix[i][j] = 0;
	InitMatrix();
	gameover = 0;
}

void RegretOne()
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			Matrix[i][j] = FrontM[i][j];
}

bool Gamewin()
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (Matrix[i][j] ==2048 ) return 1;
	return 0;
}

void ShowWin()
{
	SDL_Rect winRect = {221,140,200,200 };
	PrintPic("..\\..\\Media\\Pic\\Gamewin.bmp",NULL,&winRect);
}

void ButtonPress(int mousedown,int mousex,int mousey)
{
	SDL_Rect ResetButtonRect = { 35,35,48,48 };
	SDL_Rect RegretButtonRect = { 35,110,48,48 };

	if (mousedown==1&&mousex >= 35 && mousex <= 85 && mousey >= 35 && mousey <= 85) PrintPic("..\\..\\Media\\Pic\\ResetButton1.bmp",NULL,&ResetButtonRect);
	else if (mousedown==1&&mousex >= 35 && mousex <= 85 && mousey >= 110 && mousey <= 160) PrintPic("..\\..\\Media\\Pic\\RegretButton1.bmp", NULL, &RegretButtonRect);
	if (mousedown == 0&& mousex >= 35 && mousex <= 85 && mousey >= 35 && mousey <= 85) PrintPic("..\\..\\Media\\Pic\\ResetButton2.bmp", NULL, &ResetButtonRect);
	else if (mousedown == 0 && mousex >= 35 && mousex <= 85 && mousey >= 110 && mousey <= 160) PrintPic("..\\..\\Media\\Pic\\RegretButton2.bmp", NULL, &RegretButtonRect);

}