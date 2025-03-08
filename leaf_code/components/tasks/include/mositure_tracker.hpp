#ifndef MOISTURE_TRACKER_HPP
#define MOISTURE_TRACKER_HPP

/*module constants *********************************/
extern const uint64_t MOISTURE_TRACKER_SLEEP_DURATION;

/*Module functions *******************************************************/
/**
 * @function moisture_tracker_task
 * @brief Task to track moisture levels
 * 
 * @param pvParameters: void pointer to task parameters
 */
void moisture_tracker_task(void * pvParameters);
 
#endif // MOISTURE_TRACKER_HPP