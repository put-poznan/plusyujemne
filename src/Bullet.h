#ifndef _ALLY_BULLET_
#define _ALLY_BULLET_

#include "AnimatedSprite.h"

struct Bullet
{
	struct AnimatedSprite as;
	float Velocity;
	int IsAlive;
	float Damage;
};

struct Bullet *CreateStandardBullet(struct Vector2 spawn);

struct Bullet *CreateMissile(struct Vector2 spawn);

void UpdateBullet(struct Bullet *b);



#endif 
