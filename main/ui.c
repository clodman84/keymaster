#include "iot_button.h"
#include <stdint.h>
#include <string.h>

#include "oled_esp_lcd.h"
#include "ulgl.h"
#include "ui.h"

#define BUTTON_NUM 16
static button_handle_t g_btns[BUTTON_NUM] = {0};

char text_buffer[64];

#define NUMBER_OF_ROWS 4
#define NUMBER_OF_COLUMNS 4

#define LONG_PRESS_DURATION_MS 1500
#define SHORT_PRESS_DURATION_MS 100

const char* keys[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {
    {"1", "2", "3", "A"},
    {"4", "5", "6", "B"},
    {"7", "8", "9", "C"},
    {"*", "0", "#", "D"}
};

static const char* get_btn_index(button_handle_t btn)
{
    for (size_t i = 0; i < BUTTON_NUM; i++) {
        if (btn == g_btns[i]) {
            // Calculate row and column from the linear index
            size_t row = i / NUMBER_OF_ROWS; // Integer division to get the row
            size_t col = i % NUMBER_OF_COLUMNS; // Modulo operation to get the column
            return keys[row][col];
        }
    }
    return NULL; // Return NULL if the button is not found
}

static void button_single_click_cb(void *arg, void *data)
{
    ui_config* config = (ui_config *)data;
    strcat(text_buffer, get_btn_index((button_handle_t)arg));

    // drawing the text onto the screen
    draw_text(text_buffer, 0, config->bitmap);
    display_bitmap(config->panel, config->bitmap);
}

void initialize_ui(ui_config* config) {
    // Define the GPIO pins for the keypad rows and columns
    int32_t row_gpio[NUMBER_OF_ROWS] = {19, 18, 5, 17}; // Example GPIOs for rows
    int32_t col_gpio[NUMBER_OF_COLUMNS] = {16, 4, 2, 15}; // Example GPIOs for columns

    button_config_t cfg = {
        .type = BUTTON_TYPE_MATRIX,
        .long_press_time = LONG_PRESS_DURATION_MS,
        .short_press_time = SHORT_PRESS_DURATION_MS,
        .matrix_button_config = {
            .row_gpio_num = 0,
            .col_gpio_num = 0,
        }
    };

    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
        cfg.matrix_button_config.row_gpio_num = row_gpio[i];
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
            cfg.matrix_button_config.col_gpio_num = col_gpio[j];
            g_btns[i * NUMBER_OF_ROWS + j] = iot_button_create(&cfg);
            iot_button_register_cb(g_btns[i * NUMBER_OF_ROWS + j], BUTTON_SINGLE_CLICK, button_single_click_cb, config);
       }
    }
}

