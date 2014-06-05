#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "AnimatedSprite.h"
#include "config.h"

enum ENEMY_AI {IDIOT, KAMIKADZE};

struct Enemy
{
	struct AnimatedSprite Sprite;
	float YVelocity, XVelocity;
	struct LinkedList *Bullets;
	int ShootInterval;
	int TimeToShoot;
	ENEMY_AI Ai;
};

struct Enemy *CreateStandardEnemy(void)
{
	struct Enemy *enemy = malloc(sizeof(struct Enemy));
	enemy->Sprite = 
}

#endif
