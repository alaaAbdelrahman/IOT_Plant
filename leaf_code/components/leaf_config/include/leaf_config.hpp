#ifndef LEAF_CONFIG_HPP
#define LEAF_CONFIG_HPP

/*Module data structures *********************************/
typedef struct {
    unsigned char ssid[32];
    unsigned char password[64];

}wifi_credintials_t;

extern wifi_credintials_t wifi_credintials;

typedef struct {
    unsigned char plant_name[16];
}leaf_info_t;

extern leaf_info_t leaf_info;

/*Module functions *******************************************************/
/**
 * @function leaf_config_init
 * @brief Initialize leaf configuration
 * 
 * @return esp_err_t: Error code
 */
esp_err_t leaf_config_init(void);

/*Private Functions ******************************************/

/**
 * @brief private: loads loaf_config
 * @return esp_err_t: Error code
 */

 esp_err_t _load_wifi_cradentials(void);

/**
 * @brief private: loads leaf_info
 * 
 * @return esp_err_t: Error code
 */
esp_err_t  _load_leaf_info(void);

#endif // LEAF_CONFIG_HPP
