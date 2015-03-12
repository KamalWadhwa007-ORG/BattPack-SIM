#include "bat_cell.h"

//Bat_cell Contructor
Bat_cell::Bat_cell()
{	
	// 5V
	vol = 5.0;
	// 1 ohm series Resistance
	ser_res = 1.0;
	// 10mOhm internal resistance
	int_res = 0.010;
	// SW state ON by default
	SW_state = 1;
}

//Bat_cell Destructor

Bat_cell::~Bat_cell(){}

/** set APIs**/
int Bat_cell::set_vol(float v)
{


	if(v < 0.0)
	{
		//voltage of battery can't be negitive
		return -1; 
	}else
	{
		vol=v;
		return 0;

	}
	
}

int Bat_cell::set_ser_res(float sr)
{
	if(sr < 0.0)
	{
		//battery ser resistance can't be negitive
		return -1; 
	}else
	{
		ser_res=sr;
		return 0;

	}

}

int Bat_cell::set_SW_state(bool sw_s)
{
	if(SW_state == sw_s)
	{
		//already in the expected state
		return -1;
	}else
	{
		SW_state=sw_s;
		return 0;	
	}
	
}

/** GET APIs**/
float Bat_cell::get_vol()
{
	return vol;
}

float Bat_cell::get_ser_res()
{
	return ser_res;
}

bool Bat_cell::get_SW_state()
{
	return SW_state;
}


