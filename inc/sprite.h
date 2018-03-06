/**
 * A sprite is a 2D image that is drawn on the screen. It has a position (x and y), a certain number
 * of lives, sprite index, classID, and can draw itself. It also has a special function that will let
 * us call it to let the sprite perform any special functionality it needs, which will be important
 * when we inherit enemy and fire ball.
 */
#ifndef SPRITE_H
#define SPRITE_H

#include "drawEngine.h"

enum
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID,
};

struct vector
{
	float x;
	float y;
};

class Sprite
{
public:
	Sprite(DrawEngine *de, int s_index, float x=1, float y=1, int i_lives=1);
	~Sprite();

	vector getPosition(void);
	float getX(void);
	float getY(void);

	virtual void addLives(int num = 1);
	int getLives(void);
	bool isAlive(void);

	virtual bool move(float x, float y);

protected:
	DrawEngine *drawArea;
	vector pos;
	int spriteIndex;
	int numLives;
	int classID;

	vector facingDirection;

	void draw(float x, float y);
	void erase(float x, float y);

};

#endif













