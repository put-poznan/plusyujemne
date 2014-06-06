#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AnimatedSprite.h"
#include "LinkedList.h"

struct Player
{
	struct AnimatedSprite Sprite;
	float YVelocity, XVelocity;
	struct LinkedList *Bullets;
	int StandardShootInterval;
	int TimeToStandardShoot;
	int MissileShootInterval;
	int TimeToMissileShoot;
	int HP;
	int MaxHP;
	int Score;
};


struct Player CreatePlayer(void);
void MoveLeft(struct Player *p);
void MoveRight(struct Player *p);
void MoveUp(struct Player *p);
void MoveDown(struct Player *p);

void ShootStandard(struct Player *p);
void ShootMissile(struct Player *p);
void UpdatePlayer(struct Player *p);

void CheckEnemyBullets(struct Player *p);


#endif
