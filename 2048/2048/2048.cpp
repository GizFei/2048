#include"2048Head.h"
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define M Matrix

extern int Matrix[4][4];
extern int TempM[4][4];
extern int FrontM[4][4];

void InitMatrix()
{
	int i, j;
	int i1, j1;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (Matrix[i][j] != 0) return;
	srand((int)time(0));
	i = rand() % 4;
	j = rand() % 4;
	i1 = rand() % 4;
	j1 = rand() % 4;
	while (Matrix[i][j] != 0) {
		i = rand() % 4;
		j = rand() % 4;
	}
	Matrix[i][j] = (rand() % 2 + 1) * 2;
	while (Matrix[i1][j1] != 0) {
		i1 = rand() % 4;
		j1 = rand() % 4;
	}
	Matrix[i1][j1] = (rand() % 2 + 1) * 2;
}

void PerformMatrix(char c)
{
	switch (c)
	{
	case 'w':
	case 'W':
		UpMatrix();
		break;
	case 's':
	case 'S':
		DownMatrix();
		break;
	case 'a':
	case 'A':
		LeftMatrix();
		break;
	case 'd':
	case 'D':
		RightMatrix();
		break;
	}
}

void LeftMatrix()
{
	int i, j;

	for (i = 0; i<4; i++)
	{
		AdMatrix(i, -1);
		for (j = 1; j<4; j++)
		{
			if (M[i][j] == M[i][j - 1] && M[i][j] != 0)
			{
				M[i][j - 1] = (M[i][j - 1]) * 2;
				M[i][j] = 0;
			}
		}
		AdMatrix(i, -1);
	}
}

void UpMatrix()
{
	int i, j;

	for (i = 0; i<4; i++)
	{
		AdMatrix(-1, i);
		for (j = 1; j<4; j++)
		{
			if (M[j][i] == M[j - 1][i] && M[j][i] != 0)
			{
				M[j - 1][i] = (M[j - 1][i]) * 2;
				M[j][i] = 0;
			}
		}
		AdMatrix(-1, i);
	}
}

void DownMatrix()
{
	int i, j;

	for (i = 0; i<4; i++)
	{
		AdMatrix2(-1, i);
		for (j = 2; j >= 0; j--)
		{
			if (M[j][i] == M[j + 1][i] && M[j][i] != 0)
			{
				M[j + 1][i] = (M[j + 1][i]) * 2;
				M[j][i] = 0;
			}
		}
		AdMatrix2(-1, i);
	}
}

void RightMatrix()
{
	int i, j;

	for (i = 0; i<4; i++)
	{
		AdMatrix2(i, -1);
		for (j = 2; j >= 0; j--)
		{
			if (M[i][j] == M[i][j + 1] && M[i][j] != 0)
			{
				M[i][j + 1] = (M[i][j + 1]) * 2;
				M[i][j] = 0;
			}
		}
		AdMatrix2(i, -1);
	}
}

void AdMatrix(int row, int col)
{
	int m = 0, n = 0;
	int temp[4] = { 0,0,0,0 };

	if (row == -1)
	{
		for (m = 0; m<4; m++)
		{
			if (M[m][col] != 0) temp[n++] = M[m][col];
		}
		for (m = 0; m<4; m++)
		{
			M[m][col] = temp[m];
		}
		return;
	}
	if (col == -1)
	{
		for (m = 0; m<4; m++)
		{
			if (M[row][m] != 0) temp[n++] = M[row][m];
		}
		for (m = 0; m<4; m++)
		{
			M[row][m] = temp[m];
		}
		return;
	}
	return;
}

void UpdataMatrix()
{
	int i, j;
	int k;

	srand((int)time(0));
	i = rand() % 4;
	j = rand() % 4;
	while (M[i][j] != 0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	k = rand() % 10;
	switch (k)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		M[i][j] = 2;
		break;
	case 8:
	case 9:
		M[i][j] = 4;
	}
	return;
}

void AdMatrix2(int row, int col)
{
	int m, n;
	int temp[4] = { 0,0,0,0 };

	if (row == -1)
	{
		n = 3;
		for (m = 3; m >= 0; m--)
		{
			if (M[m][col] != 0) temp[n--] = M[m][col];
		}
		for (m = 0; m<4; m++)
		{
			M[m][col] = temp[m];
		}
		return;
	}
	if (col == -1)
	{
		n = 3;
		for (m = 3; m >= 0; m--)
		{
			if (M[row][m] != 0) temp[n--] = M[row][m];
		}
		for (m = 0; m<4; m++)
		{
			M[row][m] = temp[m];
		}
		return;
	}
}

void CopyMatrix()
{
	int i, j;

	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			TempM[i][j] = Matrix[i][j];
}

void CopyFrontMatrix()
{
	int i, j;

	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			FrontM[i][j] = Matrix[i][j];
}

int CompareM()
{
	int i, j;

	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (TempM[i][j] != Matrix[i][j]) return 0;
	return 1;
}


void AddButton(SDL_Renderer *gMainRenderer)
{
	SDL_Rect ResetButtonRect = {35,35,48,48};
	SDL_Rect RegretButtonRect = { 35,110,48,48 };
	SDL_Surface *ResetButtonSurface;
	SDL_Surface *RegretButtonSurface;
	SDL_Texture *ResetButtonTexture;
	SDL_Texture *RegretButtonTexture;

	ResetButtonSurface = SDL_LoadBMP("..\\..\\Media\\Pic\\ResetButton2.bmp");
	RegretButtonSurface = SDL_LoadBMP("..\\..\\Media\\Pic\\RegretButton2.bmp");
	ResetButtonTexture = SDL_CreateTextureFromSurface(gMainRenderer, ResetButtonSurface);
	RegretButtonTexture = SDL_CreateTextureFromSurface(gMainRenderer, RegretButtonSurface);
	SDL_FreeSurface(ResetButtonSurface);
	SDL_FreeSurface(RegretButtonSurface);
	SDL_RenderCopy(gMainRenderer, ResetButtonTexture, NULL, &ResetButtonRect);
	SDL_RenderCopy(gMainRenderer, RegretButtonTexture, NULL, &RegretButtonRect);
	SDL_RenderPresent(gMainRenderer);
	return;
}