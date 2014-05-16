#include "util.h"

#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <stdio.h>

#include "init.h"

void RenderGE(const struct GameEntity entity)
{
	al_draw_bitmap(entity.bitmap, entity.Pos.x, entity.Pos.y, 0);
}

ALLEGRO_BITMAP *LoadImageFile(const char *filename)
{
	ALLEGRO_BITMAP *bmp = al_load_bitmap(filename);
	if (bmp == NULL)
	{
		fprintf(stderr, "Failed to load image: %s", filename);
		exit(1);
	}
	return bmp;

}

struct Vector2 GetScreenCenter(void)
{
	struct Vector2 center;
	center.x = g_GLobalConfiguration.XResolution / 2;
	center.y = g_GLobalConfiguration.YResolution / 2;

	return center;

}


