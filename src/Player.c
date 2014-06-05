#include "Player.h"
#include "util.h"
#include "config.h"
#include "Bullet.h"
#include "Enemy.h"

struct Player CreatePlayer(void)
{
	ALLEGRO_BITMAP *bmp = LoadImageFile("gfx/player.png");
	struct Player p;
	p.Sprite = CreateAnimatedSprite(GetScreenCenter(), bmp, 3, 3);
	p.XVelocity = g_GLobalConfiguration.PlayerXVelocity;
	p.YVelocity = g_GLobalConfiguration.PlayerYVelocity;
	p.Bullets = CreateLinkedList();
	p.StandardShootInterval = 5;
	p.TimeToStandardShoot = 0;
	p.MissileShootInterval = 50;
	p.TimeToMissileShoot = 0;
	p.HP = 67;
	p.MaxHP = 100;
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

void ShootStandard(struct Player *p)
{
	if (p->TimeToStandardShoot == 0)
	{
		p->TimeToStandardShoot = p->StandardShootInterval;
		struct Vector2 pos;
		struct Bullet *b = CreateStandardBullet(p->Sprite.Positon);
		pos.x = p->Sprite.Positon.x + p->Sprite.XFrameSize / 2 - b->as.XFrameSize / 2;
		pos.y = p->Sprite.Positon.y;
		b->as.Positon = pos;
		PrependLL(p->Bullets, b);
	}
}

void ShootMissile(struct Player *p)
{
	if (p->TimeToMissileShoot == 0)
	{
		p->TimeToMissileShoot = p->MissileShootInterval;
		struct Vector2 pos;
		struct Bullet *b = CreateMissile(p->Sprite.Positon);
		pos.x = p->Sprite.Positon.x + p->Sprite.XFrameSize / 2 - b->as.XFrameSize / 2;
		pos.y = p->Sprite.Positon.y;
		b->as.Positon = pos;
		PrependLL(p->Bullets, b);
	}
}

void CheckCollistions(struct Player *p)
{
	struct LinkedListNode *iter = Enemies->head;
	while (iter != NULL)
	{
		struct Enemy *e = iter->val;
		if (Intersects(&e->Sprite, &p->Sprite))
			p->HP--;

		iter = iter->next;
	}

}

void UpdatePlayer(struct Player *p)
{
	CheckCollistions(p);

	UpdateAS(&(p->Sprite), 1);
	struct LinkedListNode *iter = p->Bullets->head;
	struct LinkedList *toDelete = CreateLinkedList();
	while (iter != NULL)
	{
		UpdateBullet(iter->val);
		struct Bullet *b = iter->val;
		if(!b->IsAlive)
			PrependLL(toDelete, iter->val);
		iter = iter->next;
	}
	iter = toDelete->head;
	while (iter != NULL)
	{
		RemoveLL(p->Bullets, iter->val);
		iter = iter->next;
	}
	ReleaseLinkedList(toDelete, 0);

	if (p->TimeToStandardShoot > 0)
		p->TimeToStandardShoot--;
	if (p->TimeToMissileShoot > 0)
		p->TimeToMissileShoot--;
}