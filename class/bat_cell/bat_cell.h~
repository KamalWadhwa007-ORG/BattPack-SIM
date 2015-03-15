#ifndef _BAT_CELL_
#define _BAT_CELL_
#include<time.h>


/**bat_cell class **/
class Bat_cell{

	private: 

/** Fixed parameters of a typical Li-ION battery ****/

		//bat capacity in mAH
		int bat_cap_mAh;

		// lithium ion discharge curve parameters & full and empty battery voltage
		float V_max, V_cutoff, V_top, V_nom;
		long long int Q_max, Q_cutoff, Q_top, Q_nom;

/************************************************/				


/** variable values of Li-ION bat, from end user P.O.V **/


		//current voltage 
		float vol;
		//Series Switch state
		bool SW_state;
		
		// time variables for storing time for voltage update
		time_t time_ON, time_on_last_update, time_now;

		//intenal resistance
		float int_res;

		//series resistance
		float ser_res;		

/* current drawn from the battery by load
this will be calculated by using Millman's theorm in  the bat pack*/
		float i_load_mA;

/*************************************************************/

public:
		//to change the default bat capacity if needed
		int set_cap(int);
		float get_updated_bat_vol();
		double convert_Q_to_V(long long int);
		long long int convert_V_to_Q(float _v);

	

		Bat_cell();
		~Bat_cell();		
		
		// to get the battery capacity		
		int get_cap();

		/* get/set Voltage*/
		float get_vol();
		int set_vol(float);

		/* get/set series resistance*/
		float get_ser_res();
		int set_ser_res(float);

		/* get SW state */
		bool get_SW_state();

/* set SW_state with i_load(2nd arg), if SW = off, 2nd arg is ignored*/
		int set_SW_state(bool,float);
		float get_i_load();

		float get_V_cutoff();
		float get_int_res();

};

#endif
