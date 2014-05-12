#ifndef _UTIL_H_
#define _UTIL_H_

#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

struct Vector2
{
	double x;
	double y;
};

struct GameEntity
{
	struct Vector2 Pos;
	struct Vector2 Size;
	ALLEGRO_BITMAP *bitmap;
};

void RenderGE(const struct GameEntity entity);


#endif
