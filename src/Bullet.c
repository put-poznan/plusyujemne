#include "Bullet.h"
#include "ImageManager.h"
#include "AnimatedSprite.h"
#include "config.h"

struct Bullet *CreateStandardBullet(struct Vector2 spawn)
{
	struct Bullet *b = malloc(sizeof(struct Bullet));
	b->as = CreateAnimatedSprite(spawn, ImageMan.StandardBullet, 4, 1);
	b->Damage = 10;
	b->IsAlive = 1;
	b->Velocity = 9;

	return b;

}

void UpdateBullet(struct Bullet *b)
{
	if (b->as.Positon.y + b->as.YFrameSize < 0)
		b->IsAlive = 0;
	else if (b->as.Positon.y > g_GLobalConfiguration.YResolution)
		b->IsAlive = 0;

	UpdateAS(&b->as, 1);
	b->as.Positon.y -= b->Velocity;

}
