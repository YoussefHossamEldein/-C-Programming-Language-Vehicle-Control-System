/*================================================
 * Name        :   Application.c
 * Author      :   Youssef Hossam Eldein
 * Description :   Vehicle Control System Project
 * Date        :   8/16/2023
 *
 * ===============================================
 */

#include <stdio.h>
#include "Application.h"



int main(){
	/*********** local declaration section ******************/
	part.vehicle_speed = 100;
	part.engine_temperature_controller = OFF;
	part.traffic_color = 'g';
	part.AC = OFF;
	part.room_temperature = 35;
	part.engine_temperature = 90;
	part.engine_state = OFF;
	char sensor_set;
	char system_state;
	char flag = TRUE;

	while(1){
		/* Calling the start_system function to display the main menu of the system */
		system_state = start_system();
		/* if user chose the first option from the main menu */
		if('a' == system_state)
		{
		     printf("Turn ON vehicle engine\n");
		     part.engine_state = ON;

		     while(flag == TRUE){
		    	 /* always display the sensor set menu of the vehicle till the user turn off engine */
                    sensor_set = display_menu();

            switch(sensor_set)
                {

                case 'a':
                            printf("Turn off engine\n");
                            flag = FALSE;
                                break;
                case 'b':
                            /* setting the traffic color */
                            printf("Enter the traffic color\n");
                            fflush(stdout);
                            scanf(" %c", &part.traffic_color);
                            set_traffic_light_color(part.traffic_color,&part);
                            /*displaying vehicle state*/

                               if(part.vehicle_speed == 30)
                                    {
                                            part.AC = ON;
                                            part.room_temperature = part.room_temperature*(5/4)+1;
                                            #if(WITH_ENGINE_TEMP_CONTROLLER == TRUE)
                                            part.engine_temperature_controller = ON;
                                            part.engine_temperature = part.engine_temperature*(5/4)+1;
                                            #endif

                                    }
                                        display_vehicle_state(part);


                                break;
                case 'c':
                            /* setting the room temperature */
                            printf("Enter the required room temperature: \n");
                            fflush(stdout);
                            scanf(" %d",&part.room_temperature);
                            set_room_temperature(&part);
                            /* displaying vehicle state */
                               display_vehicle_state(part);



                            break;
                    #if (WITH_ENGINE_TEMP_CONTROLLER == TRUE)
                case 'd':
                        /* setting the engine temperature */
                        printf("Enter the required engine temperature\n");
                        scanf(" %d",&part.engine_temperature);
                        set_engine_temperature(&part);
                        /* displaying vehicle state */
                           display_vehicle_state(part);


                    break;
                    #endif
                default:
                        printf("invalid choice\n");
                        break;

                }


            }
            flag = TRUE;


		}
		/********************** second choice from the system main menu**********************/

		/* if user chose the second option from the main menu of the system */
		else if('b' == system_state)
		{
			printf("Turn OFF vehicle engine\n");
		}
		/*********************** Third choice from the system main menu**********************/
		/*if user chose the third option */
		else if('c' == system_state)
		{
			printf("Quite the system\n");
			break;
		}
		/* if user chose none of the options from the main menu of the system */
		else
		{

		}


	}

    return 0;
}
/**
  *==========================================================
  * @brief : function to display the main menu of the system
  * @param : function takes nothing
  * @retval: function returns the chosen option by the user
  *===========================================================
  **/
char start_system (void){
	char user_selection ;
	printf("a. Turn ON vehicle engine\n");
	printf("b. Turn OFF vehicle engine\n");
	printf("c. Quite the system\n");
	fflush(stdout);
	scanf(" %c",&user_selection);
	return user_selection ;
}
/**
  *==========================================================
  * @brief : function to display sensors set menu
  * @param : function takes nothing
  * @retval: function returns the chosen option by the user
  *===========================================================
  **/
char display_menu (void){

    char user_selection;
    printf("a. Turn off the engine\n");
    printf("b. Set the traffic light color\n");
    printf("c. Set the room temperature\n");
    printf("d. Set the engine temperature\n");
    fflush(stdout);
    scanf(" %c", &user_selection);
    return user_selection;

}
/**
  *======================================================================================================
  * @brief : function to display the current vehicle state
  * @param : function takes current vehicle speed and current engine temp. and current room temperature
  * @retval: function returns void
  *======================================================================================================
  **/
  void display_vehicle_state(vehicle_t obj)
  {
      #if (WITH_ENGINE_TEMP_CONTROLLER == TRUE)
      if(part.AC == OFF && part.engine_temperature_controller == OFF){
      printf("Engine State                  :   ON\n");
      printf("AC                            :   OFF\n");
      printf("Vehicle Speed                 :   %d Km/hr\n",obj.vehicle_speed);
      printf("Room Temperature              :   %d C\n",obj.room_temperature);
      printf("Engine Temperature            :   %d C\n",obj.engine_temperature);
      printf("Engine Temperature controller :   OFF\n");
      }
      else if(part.AC == OFF && part.engine_temperature_controller == ON)
      {
       printf("Engine State                 :   ON\n");
      printf("AC                            :   OFF\n");
      printf("Vehicle Speed                 :   %d Km/hr\n",obj.vehicle_speed);
      printf("Room Temperature              :   %d C\n",obj.room_temperature);
      printf("Engine Temperature            :   %d C\n",obj.engine_temperature);
      printf("Engine Temperature controller :   ON\n");
      }
      else if(part.AC == ON && part.engine_temperature_controller == OFF)
      {
      printf("Engine State                  :   ON\n");
      printf("AC                            :   ON\n");
      printf("Vehicle Speed                 :   %d Km/hr\n",obj.vehicle_speed);
      printf("Room Temperature              :   %d C\n",obj.room_temperature);
      printf("Engine Temperature            :   %d C\n",obj.engine_temperature);
      printf("Engine Temperature controller :   OFF\n");
      }
      else if(part.AC == ON && part.engine_temperature_controller == ON)
      {
      printf("Engine State                  :   ON\n");
      printf("AC                            :   ON\n");
      printf("Vehicle Speed                 :   %d Km/hr\n",obj.vehicle_speed);
      printf("Room Temperature              :   %d C\n",obj.room_temperature);
      printf("Engine Temperature            :   %d C\n",obj.engine_temperature);
      printf("Engine Temperature controller :   ON\n");
      }
      #elif (WITH_ENGINE_TEMP_CONTROLLER == FALSE)
       if(part.AC == OFF){
      printf("Engine State                  :   ON\n");
      printf("AC                            :   OFF\n");
      printf("Vehicle Speed                 :   %d Km/hr\n",obj.vehicle_speed);
      printf("Room Temperature              :   %d C\n",obj.room_temperature);
      }
       else if(part.AC)
      {
      printf("Engine State                  :   ON\n");
      printf("AC                            :   ON\n");
      printf("Vehicle Speed                 :   %d Km/hr\n",obj.vehicle_speed);
      printf("Room Temperature              :   %d C\n",obj.room_temperature);
      }
      #endif
  }
/**
  *======================================================================================
  * @brief : function to set the traffic light color
  * @param : function takes character which is the traffic color
  * @retval: function returns modified vehicle speed indirectly according to traffic color
  *=======================================================================================
  **/
void set_traffic_light_color(char color, vehicle_t *vspeed){


        if('g' == color)
            {
                vspeed->vehicle_speed = 100;
            }
        else if ('o' == color)
        {
                vspeed->vehicle_speed = 30;
        }
        else if ('r' == color)
        {
                vspeed->vehicle_speed = 0;
        }
        else
        {
            printf("Invalid color\n");
        }
}
/**
  *==============================================================================================
  * @brief : function to set the room temperature
  * @param : function takes integer which is the required room temperature
  * @retval: function returns void but modifying the room temperature which is an indirect return
  *==============================================================================================
  **/
void set_room_temperature(vehicle_t *rTemp)
{
    if(rTemp->room_temperature < 10 || rTemp->room_temperature > 30)
    {
        rTemp->AC = ON;
        rTemp->room_temperature = 20;
    }
    else
    {
        rTemp->AC = OFF;
    }


}
/**
  *================================================================
  * @brief : function to set the engine temperature
  * @param : function takes integer which is the engine temperature
  * @retval: function returns void
  *================================================================
  **/
void set_engine_temperature(vehicle_t *eTemp){
    if(eTemp->engine_temperature < 100 || eTemp->engine_temperature > 150)
    {
        eTemp->engine_temperature_controller = ON;
        eTemp->engine_temperature = 125;
    }
    else
    {
        eTemp->engine_temperature_controller = OFF;
    }


}

