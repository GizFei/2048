#include"2048Head.h"

void Print(int num,SDL_Rect TextureRect, SDL_Rect RendererRect)
{
	char *filename[] = { "..\\..\\Media\\Pic\\2.bmp","..\\..\\Media\\Pic\\4.bmp" ,
		"..\\..\\Media\\Pic\\8.bmp" ,"..\\..\\Media\\Pic\\16.bmp" ,
		"..\\..\\Media\\Pic\\32.bmp" ,"..\\..\\Media\\Pic\\64.bmp" ,
		"..\\..\\Media\\Pic\\128.bmp" ,"..\\..\\Media\\Pic\\256.bmp" ,
		"..\\..\\Media\\Pic\\512.bmp" ,"..\\..\\Media\\Pic\\1024.bmp" ,
		"..\\..\\Media\\Pic\\2048.bmp"};
	char filename2[] = "E:\\FreeSerif.ttf";
	switch (num)
	{
	case 2:
		PrintPic(filename[0], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 4:
		PrintPic(filename[1], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 8:
		PrintPic(filename[2], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 16:
		PrintPic(filename[3], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 32:
		PrintPic(filename[4], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 64:
		PrintPic(filename[5], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 128:
		PrintPic(filename[6], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 256:
		PrintPic(filename[7], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 512:
		PrintPic(filename[8], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 1024:
		PrintPic(filename[9], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	case 2048:
		PrintPic(filename[10], &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	default:
		PrintPic("..\\..\\Media\\Pic\\0.bmp", &TextureRect, &RendererRect);
		PrintNum(num, filename2, RendererRect.x + 40, RendererRect.y + 10);
		break;
	}
}