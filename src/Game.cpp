
#include <iostream>
#include <ncurses.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <chrono>

#include "game.h"
#include "drawEngine.h"

using namespace std;
using namespace std::chrono;

# define NUMBER_OF_SECONDS_PER_FRAME 		(1000/30)	//number of seconds per frame

bool Game::run(void)
{
	initscr();	// Initialize the window
	cbreak();
	noecho();	// Don't echo any keypresses
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	drawArea.createSprite(0,'$');
	player = new Character(&drawArea, 0);

	posx = 0;

	char key = ' ';
	frameCount = 0;
	startTime = high_resolution_clock::now();
	lastTime = high_resolution_clock::now();

	while (key != 'q')
	{
		while (!getInput(&key))
		{
			timerUpdate();
		}

		player->keyPress(key);

		refresh();
//		printw("Here is what you have pressed:%c.. %d\n", key, posx);
//		cout << "Here is what you have pressed:" << key << endl;
	}

	endwin();

	delete player;
	cout << frameCount / (duration_cast<milliseconds>(high_resolution_clock::now() - startTime).count() / 1000) << "fps" << endl;
	cout << "End of the game" << endl;

	return true;
}

bool Game::getInput(char *c)
{
	int character = getch();

	if (isascii(character))
	{
		*c = character;
		return true;
	}
	return false;
}

void Game::timerUpdate(void)
{
	double currentTime = duration_cast<milliseconds>(high_resolution_clock::now() - lastTime).count();

	if (currentTime < NUMBER_OF_SECONDS_PER_FRAME)
	{
		return;
	}

	frameCount++;
	lastTime = high_resolution_clock::now();
}






