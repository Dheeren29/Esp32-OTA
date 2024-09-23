#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define PIN 2

void app_main(void)
{
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    uint32_t ledOn = 1;

    while(1)
    {
        ledOn = ! ledOn;
        gpio_set_level(PIN, ledOn);
        vTaskDelay(1000 / portTICK_PERIOD_MS);          // 1000ms / 10ms where 10ms is the portTick_PERIOD_MS which equivalent to ticks period i.e., 100 ticks because 1 tick = 10ms
    }
}