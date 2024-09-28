#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define led1 16
#define led2 4

uint16_t level1 = 1;
uint16_t level2 = 1;

static void Task1code(void * parameter)
{   while (1)
    {   printf("\n Task1 running on core : %d", xPortGetCoreID());
        level1 = !level1;
        gpio_set_level(led1, level1);
        vTaskDelay(100/10);
    }
}
static void Task2code(void * parameter)
{   while (1)
    {   printf("\n Task2 running on core : %d", xPortGetCoreID());
        level2 = !level2;
        gpio_set_level(led2, level2);
        vTaskDelay(400/10);
    }
}

void app_main(void)
{   gpio_set_direction(led1, GPIO_MODE_OUTPUT);
    gpio_set_direction(led2, GPIO_MODE_OUTPUT);

    //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
    xTaskCreatePinnedToCore(Task1code, //Task function Identifier Name
                            "Task1",    //Name of task 
                            10000,      //Stack size of task
                            NULL,       //parameter of the task
                            1,          //priority of the task    
                            NULL,       //Task handle to keep track of created task
                            0);         //pin task to core 0
    
    xTaskCreatePinnedToCore(Task2code, //Task function Identifier Name
                            "Task2",    //Name of task 
                            10000,      //Stack size of task
                            NULL,       //parameter of the task
                            1,          //priority of the task    
                            NULL,       //Task handle to keep track of created task
                            1);         //pin task to core 1
}
