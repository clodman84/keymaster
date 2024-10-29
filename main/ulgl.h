#ifndef ULGL
#define ULGL

#include <stdint.h>

void print_bitmap_in_horizontal_mode(uint8_t *screen, int height, int width);
void draw_text(char *text, int page, uint8_t *screen);
void draw_keymaster_logo(uint8_t *screen);

#endif
