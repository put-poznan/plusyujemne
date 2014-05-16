#include "ImageManager.h"
#include "util.h"

struct ImageManager ImageMan;

void LoadImages(void)
{
	ImageMan.StandardBullet = LoadImageFile("gfx/bullet.png");
}