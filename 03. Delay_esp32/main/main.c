#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define tag "Loop"

void app_main(void)
{   int i = 0;
    printf("Now you will see a infinite loop below\n");
    while(1)
    {   ESP_LOGI(tag, "in loop %d", i++);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
