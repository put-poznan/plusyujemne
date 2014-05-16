#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AnimatedSprite.h"

struct Player
{
	struct AnimatedSprite Sprite;
	float YVelocity, XVelocity;

};


struct Player CreatePlayer(void);
void MoveLeft(struct Player *p);
void MoveRight(struct Player *p);
void MoveUp(struct Player *p);
void MoveDown(struct Player *p);



#endif