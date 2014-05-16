#include "init.h"

#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

#include "config.h"

void init(ALLEGRO_DISPLAY **disp)
{
	struct Configuration cfg;
	al_init();
	al_install_keyboard();
	al_init_font_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_mouse();

	cfg = LoadConfigFile("xd");

	*disp = al_create_display(cfg.XResolution, cfg.YResolution);
}
