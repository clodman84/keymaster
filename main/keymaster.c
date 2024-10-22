#include <stdint.h>
#include <string.h>

#include "oled_esp_lcd.h"
#include "ulgl.h"

uint8_t screen[1024];

void app_main(void)
{
	esp_lcd_panel_handle_t panel = initialise_oled();
	char* text = "   Hello World!";
	draw_text(text, strlen(text), 3, screen);
	display_bitmap(panel, screen);
	print_bitmap_in_horizontal_mode(screen, 64, 128);
} 
