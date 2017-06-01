#pragma once
#include<stdio.h>
#include"SDL.h"
#include"SDL_ttf.h"


void PrintPic(char filename[],SDL_Rect *TextureRect,SDL_Rect *RendererRect);
void PrintNum(int num,char filename[],int x,int y);
void Print(int num, SDL_Rect TextureRect, SDL_Rect RendererRect);

void InitMatrix();    //��ʼ������ 
void UpdataMatrix();  //���¾��� 
void PerformMatrix(char c); //�������� 
void UpMatrix();
void DownMatrix();
void LeftMatrix();
void RightMatrix();
void AdMatrix(int row, int col);
void AdMatrix2(int row, int col);
void CopyMatrix();
void CopyFrontMatrix();
int CompareM();

void AddButton(SDL_Renderer *gMainRenderer);

bool ifGameover();
void Gameover();
void ButtonPerform(int mousex,int mousey);
void Reset();
void RegretOne();
bool Gamewin();
void ShowWin();
void ButtonPress(int mousedown,int mousex,int mousey);