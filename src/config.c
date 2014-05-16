#include "config.h"
#include <assert.h>
#include <stdio.h>

// struct Configuration
// {
	// int XResolution, YResolution;
	// double ShipSpeed;
	// double RocketSpeed;
// };

// struct Configuration LoadConfigFile(const char *filename);

struct Configuration LoadConfigFile(const char *filename)
{
	assert(filename != NULL);
	struct Configuration xd;
	FILE *f = fopen(filename, "rt");
	int i = 1;
	char line[512] = {0};
	char name[512] = {0};
	char val[512] = {0};
	
	while(fgets(line, 512, f) != NULL)
	{
		printf("%d %s", i++ , line);
		if(sscanf(line, "%[^=] %d", name, val) == 2)
		{
			//valid entry
			if(strcmp("XResolution", name))
				xd.XResolution = atoi(val);
		}
	}
	printf("%d", xd.XResolution);
	fclose(f);
	return xd;
}
