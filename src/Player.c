#include "Player.h"
#include "util.h"
#include "config.h"

struct Player CreatePlayer(void)
{
	ALLEGRO_BITMAP *bmp = LoadImageFile("gfx/player.png");
	struct Player p;
	p.Sprite = CreateAnimatedSprite(GetScreenCenter(), bmp, 3, 3);
	p.XVelocity = g_GLobalConfiguration.PlayerXVelocity;
	p.YVelocity = g_GLobalConfiguration.PlayerYVelocity;
	return p;
}

void MoveLeft(struct Player *p)
{
	int newX = p->Sprite.Positon.x - p->XVelocity;
	if (newX < 0)
		newX = 0;
	p->Sprite.Positon.x = newX;
}

void MoveRight(struct Player *p)
{
	int newX = p->Sprite.Positon.x + p->XVelocity;
	if (newX + (int)p->Sprite.XFrameSize >= g_GLobalConfiguration.XResolution)
		newX = g_GLobalConfiguration.XResolution - p->Sprite.XFrameSize;
	p->Sprite.Positon.x = newX;
}

void MoveUp(struct Player *p)
{
	int newY = p->Sprite.Positon.y - p->YVelocity;
	if (newY < 0)
		newY = 0;
	
	p->Sprite.Positon.y = newY;
}

void MoveDown(struct Player *p)
{
	int newY = p->Sprite.Positon.y + p->YVelocity;
	if (newY + (int)p->Sprite.YFrameSize >= g_GLobalConfiguration.YResolution)
		newY = g_GLobalConfiguration.YResolution - p->Sprite.YFrameSize;
	p->Sprite.Positon.y = newY;
}
