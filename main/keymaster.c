#include "esp_lcd_types.h"
#include "ui.h"
#include "oled_esp_lcd.h"
#include <stdint.h>

uint8_t screen[1024];

void app_main(void) {
    esp_lcd_panel_handle_t panel = initialise_oled();
    display_bitmap(panel, screen);

    ui_config* config = malloc(sizeof(ui_config));
    config->bitmap = screen;
    config->panel = panel;

    initialize_ui(config);
}
