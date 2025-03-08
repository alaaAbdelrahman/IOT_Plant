#include <esp_log.h>
#include <esp_sleep.h>


/* Module constants ******************************/
const uint64_t MOISTURE_TRACKER_WAKEUP_INTERVAL = 60 * 1000000; // 60 seconds


/* Private module constants***************************/

static const char *TAG = "moisture_tracker";

void moisture_tracker_task(void * pvParameters){

    ESP_LOGI(TAG, 
        "Moisture tracker task started");

        while(1){
            ESP_LOGI(TAG, 
                "Moisture tracker task running");

            // Connect to wifi
            ESP_LOGI(TAG, "Starting wifi connection " );
            // getting a moisture reading
            ESP_LOGI(TAG, "getting a moisture reading ");

            // posting the reading
            ESP_LOGI(TAG, "posting the reading ");

            //stopping wifi
            ESP_LOGI(TAG, "stopping wifi ");


            // Sleep for 60 seconds
            esp_sleep_enable_timer_wakeup(MOISTURE_TRACKER_WAKEUP_INTERVAL);
            esp_deep_sleep_start();
        }
}