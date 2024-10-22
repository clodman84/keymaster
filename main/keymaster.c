#include "oled_esp_lcd.h"
#include <stdint.h>
#include "ulgl.h"

uint8_t screen[1024];

void app_main(void)
{
	esp_lcd_panel_handle_t panel = initialise_oled();
	verify_memory_address_mode(panel, screen);
	display_keymaster_logo(panel, screen);
	print_bitmap_in_horizontal_mode(screen);
} 
