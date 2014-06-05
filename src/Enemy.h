#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "AnimatedSprite.h"
#include "config.h"

enum ENEMY_AI {AI_IDIOT, AI_KAMIKADZE};

extern struct LinkedList *Enemies;
extern struct LinkedList *Bullets;

struct Enemy
{
	struct AnimatedSprite Sprite;
	float YVelocity, XVelocity;
	//struct LinkedList *Bullets;
	int ShootInterval;
	int TimeToShoot;
	enum ENEMY_AI Ai;
};

void InitEnemy(void);

//struct Enemy *CreateIdiotEnemy(void);
void ReleaseEnemy(struct Enemy *enemy);

void SpawnEnemy(enum ENEMY_AI ai);

void UpdateEnemies(void);
void RenderEnemies(void);

void CloseEnemy(void);

#endif
