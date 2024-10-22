/*
 ULTRA Lightweight Graphics Library, designed for this project 
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ulgl.h"
#include "images.h"

void print_bitmap_in_horizontal_mode(uint8_t *screen, int height, int width){
	// Helper function to verify the contents of a bitmap 
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
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


void draw_text(char *text, int len, int page, uint8_t *screen){
	int offset = page * 128;
	for (int i = 0; i < len; i++){
		char c = text[i];
		uint8_t* char_glyph = fontData7x8[c - 32];
		// printf("%c\n", c);
		// print_bitmap_in_horizontal_mode(char_glyph, 8, 7);
		// printf("\n");
		memcpy(screen + offset + (7 * i), char_glyph, 7);  // the font is 7 bytes wide
	}
};

void draw_keymaster_logo(uint8_t *screen){
	memcpy(screen, keymaster_logo, 1024);
}
