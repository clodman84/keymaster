/*
 ULTRA Lightweight Graphics Library, designed for this project 
*/
#include <stdint.h>
#include <string.h>
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_types.h"
#include "images.h"
#include "freertos/idf_additions.h"
#include "portmacro.h"
#include "ulgl.h"

#define HEIGHT 64 
#define WIDTH 128 


void print_bitmap_in_horizontal_mode(uint8_t *screen) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int page = y / 8;// Determine which byte
			int index = page * 128 + x;
			int bit = y & 0b111;// Determine the bit position (equivalent to y % 8)
			// Check if the pixel is set (1) or not (0)
			if (screen[index] & (1 << bit)){
				printf("#"); // Pixel is on
			} else {
				printf(" "); // Pixel is off
			}
		}
	printf("\n"); 
	} 
}


void verify_memory_address_mode(esp_lcd_panel_handle_t panel, uint8_t *screen){
	uint8_t* start = screen;
	for (int i = 0; i < 64; i++){
		for (int j = 0; j < 16; j++){
			memset(start, 0xFF, 1);
			start += 1;
	 		esp_lcd_panel_draw_bitmap(panel, 0, 0, 128, 64, screen);
			vTaskDelay(23 / portTICK_PERIOD_MS);	
		}
	}
}

void display_keymaster_logo(esp_lcd_panel_handle_t panel, uint8_t *screen){
	memcpy(screen, keymaster_logo, 1024);
	esp_lcd_panel_draw_bitmap(panel, 0, 0, 128, 64, screen);
}

