#ifndef _CONFIG_H_
#define _CONFIG_H_

struct Configuration
{
	int XResolution, YResolution;
	float ShipSpeed;
	float RocketSpeed;
	float PlayerXVelocity, PlayerYVelocity;
	int IdiotInterval;
};

extern struct Configuration g_GLobalConfiguration;

struct Configuration LoadConfigFile(const char *filename);

#endif
