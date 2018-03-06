/**
 * A character is a sprite that will be controlled by the player
 *
 * We need to add the ability for our sprite to respond to player input
 *
 * 	keyPress
 *
 * Variables that specify which key does what
 *
 *  upKey, downkey, leftKey, rightKey
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"

class Character : public Sprite
{
public:
	Character(DrawEngine *de, int s_index, float x=1, float y=1,
			int lives = 3, char up_key = 'w', char down_key = 's', char left_key = 'a', char right_key = 'd');

	virtual bool keyPress(char c);

protected:
	char upKey;
	char downKey;
	char leftKey;
	char rightKey;
};






#endif









