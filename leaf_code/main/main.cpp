#include <esp_log.h>
#include <nvs_flash.h>
#include <esp_err.h>
#include <freertos/FreeRTOS.h>
#include <esp_heap_caps.h>

extern "C" void app_main(void)
{
    ESP_LOGI("main", "Initializing main application");

    size_t free_heap_size = heap_caps_get_free_size(MALLOC_CAP_DEFAULT);

    ESP_LOGI("main", "Free heap size: %d", free_heap_size);

    ESP_LOGI("main", "Initializing NVS flash");
    esp_err_t nvs_err = nvs_flash_init();
    if (nvs_err != ESP_OK)
    {
            ESP_LOGE("main", "Failed to initialize NVS flash: %s", esp_err_to_name(nvs_err));
            return;
    }
}
