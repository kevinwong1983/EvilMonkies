#include "drawEngine.h"
#include <ncurses.h>
#include <iostream>
#include <sys/select.h>
#include <termios.h>

using namespace std;

DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeigth = ySize;

	printf("drawengine constructor");
	// set cursor visibility to false
	cursorVisibility(false);
}

DrawEngine::~DrawEngine()
{
	// set cursor visibility to true
	cursorVisibility(true);
}

int DrawEngine::createSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteImage[index] = c;
		return index;
	}

	return -1;
}

void DrawEngine::deleteSprite(int index)
{
	// in this implementation we don't need it
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	gotoxy(posx, posy);
	printw("%c", spriteImage[index]);
}

void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	printw(" ");
}

void DrawEngine::gotoxy(int x, int y)
{
	move(y, x);
	refresh();
//	HANDLE output_handle;
//	COORD pos;
//	pos.X = x;
//	pos.Y = y;
//
//	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(output_handle, pos);
}

void DrawEngine::cursorVisibility(bool visibility)
{
	if (visibility)
	{
		curs_set(2);
	}
	else
	{
		curs_set(FALSE);
	}

//	HANDLE output_handle;
//	CONSOLE_CURSOR_INFO cciInfo;
//	cciInfo.bVisible = visivility;
//
//	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	SetConsoleCursorInfo(output_handle, &cciInfo);
}





