#ifndef _ANIMATED_SPRITE_H_
#define _ANIMATED_SPRITE_H_

#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

#include <stddef.h>
#include "util.h"

struct AnimatedSprite
{
	struct Vector2 Positon;
	ALLEGRO_BITMAP *Bitmap;
	size_t XFrames;
	size_t XFrame;
	int TickElapsed;
	int FrameTicks;
	size_t XFrameSize, YFrameSize;
};

struct AnimatedSprite CreateAnimatedSprite(struct Vector2 pos, ALLEGRO_BITMAP *bmp, size_t frameCount, size_t frameTime);
void UpdateAS(struct AnimatedSprite *as, int ticks);
void DrawAS(struct AnimatedSprite *as);
int Intersects(struct AnimatedSprite *a, struct AnimatedSprite *b);

#endif
