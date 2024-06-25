/*================================================
 * Name        :   Application.h
 * Author      :   Youssef Hossam Eldein
 * Description :   Vehicle Control System Project
 * Date        :   8/16/2023
 *
 * ===============================================
 */

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0
#define WITH_ENGINE_TEMP_CONTROLLER TRUE



typedef struct {
		int vehicle_speed;
		int engine_temperature;
		int room_temperature;
		char engine_temperature_controller;
		char traffic_color;
		char AC;
		char engine_state;

}vehicle_t;
vehicle_t part;
/**
  *==========================================================
  * @brief : function to display the main menu of the system
  * @param : function takes nothing
  * @retval: function returns the chosen option by the user
  *===========================================================
  **/
char start_system (void);
/**
  *==========================================================
  * @brief : function to display sensors set menu
  * @param : function takes nothing
  * @retval: function returns the chosen option by the user
  *===========================================================
  **/
char display_menu (void);
/**
  *======================================================================================================
  * @brief : function to display the current vehicle state
  * @param : function takes current vehicle speed and current engine temp. and current room temprature
  * @retval: function returns void
  *======================================================================================================
  **/
void display_vehicle_state(vehicle_t obj);
/**
  *==============================================================================================
  * @brief : function to set the traffic light color
  * @param : function takes character which is the traffic color
  * @retval: function returns indirectly the modified vehicle speed according to traffic color
  *============================================================================================
  **/

void set_traffic_light_color(char color, vehicle_t *vspeed);
/**
  *===================================================================
  * @brief : function to set the room temperature
  * @param : function takes integer which is required room temperature
  * @retval: function returns indirectly the modified temperature
  *=====================================================================
  **/
void set_room_temperature(vehicle_t *rTemp);
/**
  *==========================================================================
  * @brief : function to set the engine temperature
  * @param : function takes integer which is the required engine temperature
  * @retval: function returns indirectly the modified engine temperature
  *==========================================================================
  **/
void set_engine_temperature(vehicle_t *eTemp);
#endif /* _APPLICATION_H_ */
