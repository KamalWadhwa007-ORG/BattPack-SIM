#ifndef _BAT_CELL_
#define _BAT_CELL_



/**bat_cell class **/
class Bat_cell{

	private: 
		//voltage
		float vol;
		//intenal resistance
		float int_res;
		//series resistance
		float ser_res;
		//Series Switch state
		bool SW_state;

	public:
		Bat_cell();
		~Bat_cell();		

		/* get/set Voltage*/
		float get_vol();
		int set_vol(float);

		/* get/set series resistance*/
		float get_ser_res();
		int set_ser_res(float);

		/* get/set SW state */
		bool get_SW_state();
		int set_SW_state(bool);

};

#endif
