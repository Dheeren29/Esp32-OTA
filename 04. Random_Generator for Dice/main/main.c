#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_random.h"

#define tag "DICE"

int dice_role()
{
        int random = esp_random();
        int positiveNumber = abs(random);
        int diceNumber = (positiveNumber % 6) + 1;
        return diceNumber;
}

void app_main(void)
{   
    while(1)
    {   ESP_LOGI(tag, "random number %d", dice_role());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
