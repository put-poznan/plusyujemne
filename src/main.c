
#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

#include <stdio.h>
#include "LinkedList.h"
#include "input.h"
#include "init.h"
#include "util.h"
#include "config.h"


struct GameEntity bolek;
ALLEGRO_FONT *arial;

void DoLogic(void)
{
	if (IsKeyPressed(ALLEGRO_KEY_LEFT))
		bolek.Pos.x -= 1;
	if (IsKeyPressed(ALLEGRO_KEY_RIGHT))
		bolek.Pos.x += 1;
	if (IsKeyPressed(ALLEGRO_KEY_UP))
		bolek.Pos.y -= 1;
	if (IsKeyPressed(ALLEGRO_KEY_DOWN))
		bolek.Pos.y += 1;
}

void Render(void)
{


	RenderGE(bolek);


	al_draw_text(arial, al_map_rgb(255, 255, 255), 200, 200, 0, "#walesacontent");
}

int main(int argc, char ** argv)
{
	argc;
	argv;
	ALLEGRO_DISPLAY *display = NULL;

	init(&display);

	arial = al_create_builtin_font();
	ALLEGRO_BITMAP *bolekbmp = al_load_bitmap("gfx/bolek.png");

	bolek.bitmap = bolekbmp;
	bolek.Pos.x = 100;
	bolek.Pos.y = 100;



	double dt = 0.0;
	double lastUpdateTime = al_current_time();
	double accumulator = 0;
	double TIME_STEP = 1. / 30;



	UpdateInput();
	int isRunning = 1;
	while (isRunning)
	{
		dt = al_current_time() - lastUpdateTime;
		lastUpdateTime += dt;
		accumulator += dt;

		UpdateInput();

		if (IsKeyPressed(ALLEGRO_KEY_ESCAPE))
			break;

		while (accumulator > TIME_STEP)
		{
			DoLogic();
			accumulator -= TIME_STEP;
		}
		al_clear_to_color(al_map_rgb(0x77, 0, 255));
		Render();
		al_flip_display();
	}

	al_destroy_display(display);

	return 0;
}
