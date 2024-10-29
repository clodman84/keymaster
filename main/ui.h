#ifndef KEYPAD_H
#define KEYPAD_H

#include "esp_lcd_types.h"
#include <stdint.h>


typedef struct {
    uint8_t* bitmap;
    esp_lcd_panel_handle_t panel;
} ui_config;

void initialize_ui(ui_config*);

#endif
