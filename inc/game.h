#ifndef GAME_H
#define GAME_H

#include <chrono>
#include "drawEngine.h"
#include "character.h"

using namespace std::chrono;

class Game
{
public:
	bool run(void);

protected:
	bool getInput(char *c);
	void timerUpdate(void);
private:
	Character *player;

	double frameCount;
	time_point<steady_clock, nanoseconds> startTime;
	time_point<steady_clock, nanoseconds> lastTime;

	int posx;
	DrawEngine drawArea;
};

#endif










