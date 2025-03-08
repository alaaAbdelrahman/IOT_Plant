
#include <esp_log.h>
#include <esp_err.h>
#include "leaf_config.hpp"
#include "leaf_info.hpp"
#include "wifi_credentials.hpp"
#include <cstring>

#ifndef CONFIG_LOG_MAXIMUM_LEVEL
    #define CONFIG_LOG_MAXIMUM_LEVEL 3  // Equivalent to INFO level
#endif

/** module constants  **************************/

static const char *TAG = "leaf_config ***";

/** module variables  **************************/
wifi_credintials_t wifi_credentials ;
leaf_info_t leaf_info;

/* module functions *****************************/



esp_err_t leaf_config_init(void){
    ESP_LOGI(TAG, "Initializing leaf configuration");
    esp_err_t err_wifi = _load_wifi_cradentials();
    esp_err_t err_leaf = _load_leaf_info();

    if(err_wifi != ESP_OK || err_leaf != ESP_OK){
        ESP_LOGE(TAG, "Failed to initialize leaf configuration");
        return ESP_FAIL;
    }
    ESP_LOGI(TAG, "Leaf configuration initialized");
    ESP_LOGI(TAG, "SSID: %s", wifi_credentials.ssid);
    ESP_LOGI(TAG, "PLANT NAME: %s", leaf_info.plant_name);
    return ESP_OK;
}

/**
 * @brief Loads WiFi credentials from predefined constants.
 *
 * This function copies the SSID and password from predefined constants
 * into the wifi_credentials structure. It logs the process of loading
 * the credentials.
 *
 * @return
 *     - ESP_OK: WiFi credentials loaded successfully.
 */
esp_err_t _load_wifi_cradentials(void){
    ESP_LOGI(TAG, "Loading wifi credentials");
    strncpy(
        reinterpret_cast<char*> ( wifi_credentials.ssid),
        reinterpret_cast<const char*> (SSID), 
        sizeof(wifi_credentials.ssid));

    strncpy(
    reinterpret_cast<char*> (wifi_credentials.password), 
    reinterpret_cast<const char*> (PASSWORD),
    sizeof(wifi_credentials.password));
    
 // null terminate the strings
    wifi_credentials.ssid[strlen(reinterpret_cast<const char*>(SSID))] = '\0';
    wifi_credentials.password[strlen(reinterpret_cast<const char*>(PASSWORD))] = '\0';


    ESP_LOGI(TAG, "Wifi credentials loaded");

    return ESP_OK;
}
/**
 * @brief Loads leaf information from predefined constants.
 *      This function copies the plant name from predefined constants
 *     into the leaf_info structure. It logs the process of loading
 *    the leaf information.
 * @return
 *     - ESP_OK: Leaf information loaded successfully.
 */
esp_err_t  _load_leaf_info(void){

    ESP_LOGI(TAG, "Loading leaf information");
    strncpy(
        reinterpret_cast<char*> (leaf_info.plant_name),
        reinterpret_cast<const char*> (Plant_NAME),
        sizeof(leaf_info.plant_name));
    // null terminate the string
    leaf_info.plant_name[strlen(reinterpret_cast<const char*>(Plant_NAME))] = '\0';
    ESP_LOGI(TAG, "Leaf information loaded");
    return ESP_OK;
}
