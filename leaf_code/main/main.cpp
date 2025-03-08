#include <esp_log.h>
#include <nvs_flash.h>
#include <esp_err.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_heap_caps.h>

#include "leaf_config.hpp"
#include "mositure_tracker.hpp"

esp_err_t  setup(void){
    size_t free_heap_size = heap_caps_get_free_size(MALLOC_CAP_DEFAULT);

    ESP_LOGI("main", "Free heap size: %d", free_heap_size);

    ESP_LOGI("main", "Initializing NVS flash");
    esp_err_t nvs_err = nvs_flash_init();
    if (nvs_err != ESP_OK)
    {
            ESP_LOGE("main", "Failed to initialize NVS flash: %s", esp_err_to_name(nvs_err));
    }else {
        ESP_LOGI("main", "NVS flash initialized");
    }

    // Initialize leaf configuration
    if(leaf_config_init()!= ESP_OK){
        ESP_LOGE("main", "Failed to initialize leaf configuration");
        return ESP_FAIL;
    }
        ESP_LOGI("main", "Leaf configuration initialized");

    return nvs_err;

}
extern "C" void app_main(void)
{
    ESP_LOGI("main", "Initializing main application");

    if(setup() != ESP_OK){
        ESP_LOGE("main", "Failed to initialize application");
        return;
    }
    ESP_LOGI("main", "Application initialized");

    xTaskCreate(
        moisture_tracker_task,      // Function to implement the task
         "mositure_tracker_task",   // Name of the task
         4096,                // Stack size in words                    
          NULL,                 // Task input parameter
          5,                    // Priority of the task
          NULL);                    // Task handle.
}
