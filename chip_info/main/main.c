#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

void app_main(void)
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU cores, WiFi%s%s, ", CONFIG_IDF_TARGET, chip_info.cores, 
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "", 
            (chip_info.features & CHIP_FEATURE_BLE)? "/BLE": ""
            );
    printf("silicon revision %d, ", chip_info.revision);
    
    size_t flash_size;
    esp_flash_get_size(NULL, &flash_size);
    printf("%dMB %s flash\n", flash_size / (1024*1024), (chip_info.features & CHIP_FEATURE_EMB_FLASH)?"embedded":"external");
    for(int i=10; i >=0; i--)
        {   printf("Restarting in %d seconds...\n", i);
            vTaskDelay(1000/10);    }

    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}

