#ifndef _IMAGE_MAN_H_
#define _IMAGE_MAN_H_

#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

struct ImageManager
{
	ALLEGRO_BITMAP *Player;
	ALLEGRO_BITMAP *StandardBullet;
	ALLEGRO_BITMAP *Background;

};

extern struct ImageManager ImageMan;

void LoadImages(void);

#endif