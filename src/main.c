#include <allegro5\allegro5.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;

if(!al_init())
{
}

display = al_create_display(640, 480);
al_clear_to_color(al_map_rgb(255,0,255));
if(!display)
{

}
al_flip_display();
al_rest(10);
al_destroy_display(display);

	return 0;
}
