//Alexander Young
//Lab 5

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

struct bird_class {
    int x, y;
    int dir;
    int color;
}bird;

#define MAXSPEED 3

void create_bird_bitmap(ALLEGRO_BITMAP* bird_bpm[], ALLEGRO_DISPLAY* display);


int main(void)
{
    ALLEGRO_BITMAP* bird_bpm[4] = { NULL, NULL, NULL, NULL };
    int width = 640;
    int height = 480;
    bool done = false;

    ALLEGRO_DISPLAY* display = NULL;

    if(!al_init()) {
        return -1;
    }

    display = al_create_display(width, height);
    if (!display) {
        return -1;
    }

    al_init_primitives_addon;
    if (!al_init_primitives_addon()) {
        return -1;
    }
    create_bird_bitmap(bird_bpm, display);

    al_get_target_bitmap(al_get_backbuffer(display));
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();

    while (!done) {
        al_draw_bitmap(bird_bpm[0], width / 2, 100, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }
}

void create_bird_bitmap(ALLEGRO_BITMAP* bird_bpm[], ALLEGRO_DISPLAY* display) {
    for (int i = 0; i < 4; i++) {
        bird_bpm[i] = al_create_bitmap(64, 64);
        if (!bird_bpm[i]) {
            exit(1);
            al_destroy_display(display);
        }
    }
}