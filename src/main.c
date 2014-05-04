#include <allegro5\allegro5.h>
#include <stdio.h>

void init(ALLEGRO_DISPLAY **disp, int xres, int yres)
{
	al_init();
	*disp = al_create_display(xres, yres);	
	
}


int main(int argc, char **argv)
{
	puts("start while");
	fflush(stdout);
	ALLEGRO_DISPLAY *display = NULL;
	
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	init(&display,1024,600);
   
    al_install_keyboard();
	
	ALLEGRO_KEYBOARD_STATE KeyboardState;
	puts("przed while");
	fflush(stdout);
	while(1)
	{
		/*
		al_get_keyboard_state(&KeyboardState);
		if(al_key_down(&KeyboardState, ALLEGRO_KEY_ESCAPE))
			;//break;
		*/
		
		
		al_clear_to_color(al_map_rgb(0x77,0,255));
		al_flip_display();
	}
	puts("po while");;

	al_destroy_display(display);

	return 0;
}
