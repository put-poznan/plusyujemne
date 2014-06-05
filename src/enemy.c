#include "Enemy.h"

#include "util.h"
#include "config.h"
#include "Bullet.h"
#include "LinkedList.h"
#include "ImageManager.h"

struct LinkedList *Enemies;
struct LinkedList *Bullets;

void ManageSpawn(void);

void InitEnemy(void)
{
	Enemies = CreateLinkedList();
	Bullets = CreateLinkedList();
}

void CloseEnemy(void)
{
	ReleaseLinkedList(Enemies, true);
	free(Enemies);
	ReleaseLinkedList(Bullets, true);
	free(Bullets);
}

struct Enemy *CreateIdiotEnemy(void)
{
	struct Enemy *e = malloc(sizeof(struct Enemy));
	e->Sprite = CreateAnimatedSprite(GetScreenCenter(), ImageMan.Enemy, 3, 5);
	e->ShootInterval = g_GLobalConfiguration.EnemyShootInterval;
	e->Ai = AI_IDIOT;
	e->TimeToShoot = 0;
	e->XVelocity = 0;
	e->YVelocity = 5;

	return e;
}

struct Enemy *CreateKamikadzeEnemy(void)
{
	struct Enemy *e = malloc(sizeof(struct Enemy));
	e->Sprite = CreateAnimatedSprite(GetScreenCenter(), ImageMan.Enemy, 3, 5);
	e->ShootInterval = g_GLobalConfiguration.EnemyShootInterval;
	e->Ai = AI_KAMIKADZE;
	e->TimeToShoot = 0;
	e->XVelocity = 2;
	e->YVelocity = 5;

	return e;
}

void UpdateEnemies(int playerXPos)
{
	assert(Enemies != NULL);
	struct LinkedListNode *iter = Enemies->head;
	struct LinkedList *toDelete = CreateLinkedList();
	while (iter != NULL)
	{
		struct Enemy*e = iter->val;

		if (e->Sprite.Positon.y > g_GLobalConfiguration.YResolution)
			PrependLL(toDelete, iter->val);
		UpdateAS(&e->Sprite, 1);

		if (e->Ai == AI_IDIOT)
		{
			e->Sprite.Positon.y += e->YVelocity;
		}
		else if (e->Ai == AI_KAMIKADZE)
		{
			e->Sprite.Positon.y += e->YVelocity;
			float xmove = playerXPos - e->Sprite.Positon.x;
			if (xmove > 0)
				xmove = min(e->XVelocity, xmove);
			else
				xmove = max(-e->XVelocity, xmove);
			e->Sprite.Positon.x += xmove;
		}
		else
		{
			assert(false);
		}

		iter = iter->next;
	}

	iter = toDelete->head;
	while (iter != NULL)
	{
		RemoveLL(Enemies, iter->val);
		iter = iter->next;
	}
	ReleaseLinkedList(toDelete, 0);

	ManageSpawn();
}

void RenderEnemies(void)
{
	assert(Enemies != NULL);
	struct LinkedListNode *iter = Enemies->head;
	while (iter != NULL)
	{
		struct Enemy*e = iter->val;
		DrawAS(&e->Sprite);

		iter = iter->next;
	}
}

void SpawnEnemy(enum ENEMY_AI ai)
{
	if (ai == AI_IDIOT)
	{
		struct Enemy *e = CreateIdiotEnemy();
		e->Sprite.Positon.y = - ((int) e->Sprite.YFrameSize);
		e->Sprite.Positon.x = rand() % (g_GLobalConfiguration.XResolution - e->Sprite.XFrameSize);
		PrependLL(Enemies, e);
	}
	else if (ai == AI_KAMIKADZE)
	{
		struct Enemy *e = CreateKamikadzeEnemy();
		e->Sprite.Positon.y = -((int)e->Sprite.YFrameSize);
		e->Sprite.Positon.x = rand() % (g_GLobalConfiguration.XResolution - e->Sprite.XFrameSize);
		PrependLL(Enemies, e);
	}
	else
	{
		assert(false);
	}
}


void ManageSpawn(void)
{
	static int ticksFromLastSpawnIdiot = 10;
	if (ticksFromLastSpawnIdiot++ >= g_GLobalConfiguration.IdiotInterval)
	{
		ticksFromLastSpawnIdiot -= g_GLobalConfiguration.IdiotInterval;
		SpawnEnemy(AI_KAMIKADZE);
	}

}


