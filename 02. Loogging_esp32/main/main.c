
//Note: In both the case, you need to enable the debug and verbose log from menuconfig which are by default off in the system.

#include <stdio.h>
#include "esp_log.h"

void app_main(void)
{   //case:1 Here the logging level with tag "log" printed based on default level of configuration which is till LOGI.
    ESP_LOGE("log", "This is an error log");
    ESP_LOGW("log", "This is an warning log");
    ESP_LOGI("log", "This is an info log");
    ESP_LOGD("log", "This is an debug log");
    ESP_LOGV("log", "This is an verbose log");
    

    //case: 2 Here the logging level with tag "cat" printed based on level_set function.
    esp_log_level_set("LOG", ESP_LOG_VERBOSE); 
    ESP_LOGE("cat", "This is an error log");
    ESP_LOGW("cat", "This is an warning log");
    ESP_LOGI("cat", "This is an info log");
    ESP_LOGD("cat", "This is an debug log");
    ESP_LOGV("cat", "This is an verbose log");
    
}
