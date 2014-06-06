#ifndef _CONFIG_H_
#define _CONFIG_H_

struct Configuration
{
	int XResolution, YResolution;
	float ShipSpeed;
	float RocketSpeed;
	float PlayerXVelocity, PlayerYVelocity;
	int IdiotInterval, KamikadzeInterval;
	int EnemyShootInterval;
	float EnemyCrashDamage, PlayerCrashDamage;
	int KamikadzeScore, IdiotScore;
};

extern struct Configuration g_GLobalConfiguration;

struct Configuration LoadConfigFile(const char *filename);

#endif
