
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
#include "AnimatedSprite.h"
#include "Player.h"


struct GameEntity bolek;
ALLEGRO_FONT *arial;
struct Player player;

void DoLogic(void)
{
	if (IsKeyPressed(ALLEGRO_KEY_LEFT))
		MoveLeft(&player);
	else if (IsKeyPressed(ALLEGRO_KEY_RIGHT))
		MoveRight(&player);
	else if (IsKeyPressed(ALLEGRO_KEY_UP))
		MoveUp(&player);
	else if (IsKeyPressed(ALLEGRO_KEY_DOWN))
		MoveDown(&player);

	UpdateAS(&(player.Sprite), 1);
}

void Render(void)
{


	RenderGE(bolek);
	DrawAS(&player.Sprite);

	al_draw_text(arial, al_map_rgb(255, 255, 255), 200, 200, 0, "#walesacontent");
}

int main(int argc, char ** argv)
{
	argc;
	argv;
	ALLEGRO_DISPLAY *display = NULL;

	init(&display);

	arial = al_create_builtin_font();
	ALLEGRO_BITMAP *bolekbmp = LoadImageFile("gfx/bolek.png");

	struct Vector2 zero;
	zero.x = zero.y = 0;
	player = CreatePlayer();

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
