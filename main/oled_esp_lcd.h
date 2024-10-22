#ifndef OLED_INIT
#define OLED_INIT

#include "esp_lcd_types.h"
#include <stdint.h>

esp_lcd_panel_handle_t initialise_oled(void);
void verify_memory_address_mode(esp_lcd_panel_handle_t panel, uint8_t *screen);
void display_bitmap(esp_lcd_panel_handle_t panel, uint8_t *bitmap);
void display_keymaster_logo(esp_lcd_panel_handle_t panel);

#endif
