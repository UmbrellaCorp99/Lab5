//Alexander Young
//Lab 5

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

void create_bird_bitmap(ALLEGRO_BITMAP* bird_bpm[], ALLEGRO_DISPLAY* display);

int main(void)
{
    //An Allegro bitmap pointer
    ALLEGRO_BITMAP* bird_bpm[4] = { NULL, NULL, NULL, NULL };
    int width = 640;
    int height = 480;
    bool done = false;

    //Initializing Allegro, display, and primitives with error handling
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
    
    //creating a bird bitmap to be shown on the display
    create_bird_bitmap(bird_bpm, display);

    //Sets the target bitmap back to current display
    al_set_target_bitmap(al_get_backbuffer(display));
    al_clear_to_color(al_map_rgb(122, 122, 122));
    al_flip_display();

    while (!done) {
        //Draw the bitmap at the center of the display
        al_draw_bitmap(bird_bpm[0], (width  / 2) - 32, (height / 2) -32, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(122, 122, 122));
    }

    //clear up memory used by bitmaps and display when done
    for (int i = 0; i < 4; i++) {
        al_destroy_bitmap(bird_bpm[i]);
    }
    al_destroy_display(display);
}

//This function defines and creates bird bitmaps
//It ttakes the bitmap's memory address and the display as parameters
//No return
void create_bird_bitmap(ALLEGRO_BITMAP* bird_bpm[], ALLEGRO_DISPLAY* display) {
    //creates 4 bitmap renderings with dimensions of 64x64
    for (int i = 0; i < 4; i++) {
        bird_bpm[i] = al_create_bitmap(64, 64);
        if (!bird_bpm[i]) {
            exit(1);
            al_destroy_display(display);
        }

        //sets the target bitmap to the memory address of the bird_bpm
        al_set_target_bitmap(bird_bpm[i]);
        al_clear_to_color(al_map_rgb(122,122,122));

        //The primitives that make up the design of the bitmap
        int x = 32;
        int y = 32;
        al_draw_filled_triangle(32, 27, 32, 37, 64, 32, al_map_rgb(255,255,0));
        al_draw_filled_circle(x, y, 17, al_map_rgb(0, 0, 255));
        al_draw_circle(x + 8, y - 5, 5, al_map_rgb(0,0,0), 2);
        al_draw_filled_rectangle(x + 6, y-8, x + 11, y-2, al_map_rgb(255, 0, 0));
    }
}