
#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

#include <stdio.h>
#include "LinkedList.h"

void init(ALLEGRO_DISPLAY **disp, int xres, int yres)
{
	al_init();
	al_install_keyboard();
	al_init_font_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_mouse();

	*disp = al_create_display(xres, yres);
}


int main(int argc, char ** argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	init(&display, 800, 600);
	ALLEGRO_FONT *arial = al_create_builtin_font();

	ALLEGRO_BITMAP *bolek = al_load_bitmap("gfx/bolek.png");


	ALLEGRO_KEYBOARD_STATE KeyboardState;
	ALLEGRO_MOUSE_STATE MouseState;

	double dt = 0.0;
	double lastUpdateTime = al_current_time();
	double accumulator = 0;
	double TIME_STEP = 1. / 30;

	double x = 0, y = 0;

	while (1)
	{
		dt = al_current_time() - lastUpdateTime;
		lastUpdateTime += dt;
		accumulator += dt;

		al_get_mouse_state(&MouseState);
		al_get_keyboard_state(&KeyboardState);
		if (al_key_down(&KeyboardState, ALLEGRO_KEY_ESCAPE))
			break;

		while (accumulator > TIME_STEP)
		{
			if (al_key_down(&KeyboardState, ALLEGRO_KEY_LEFT))
				x -= 1;
			if (al_key_down(&KeyboardState, ALLEGRO_KEY_RIGHT))
				x += 1;
			if (al_key_down(&KeyboardState, ALLEGRO_KEY_UP))
				y -= 1;
			if (al_key_down(&KeyboardState, ALLEGRO_KEY_DOWN))
				y += 1;
			accumulator -= TIME_STEP;
		}
		//render

		al_clear_to_color(al_map_rgb(0x77, 0, 255));
		al_draw_filled_circle(200, 200, 100,al_map_rgb(127,127,127));

		al_draw_bitmap(bolek, x, y, 0);
		
		al_draw_text(arial, al_map_rgb(255, 255, 255), 200, 200, 0, "#walesacontent");
		al_flip_display();
	}

	al_destroy_display(display);

	return 0;
}
