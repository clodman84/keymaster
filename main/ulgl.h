#ifndef ULGL
#define ULGL

#include <stdint.h>
#include "esp_lcd_types.h"

void display_keymaster_logo(esp_lcd_panel_handle_t panel, uint8_t *screen);
void verify_memory_address_mode(esp_lcd_panel_handle_t panel, uint8_t *screen);
void print_bitmap_in_horizontal_mode(uint8_t *screen);

#endif
