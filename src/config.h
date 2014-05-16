#ifndef _CONFIG_H_
#define _CONFIG_H_

struct Configuration
{
	int XResolution, YResolution;
	double ShipSpeed;
	double RocketSpeed;
};

struct Configuration LoadConfigFile(const char *filename);

#endif
