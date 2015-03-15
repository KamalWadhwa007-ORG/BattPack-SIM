#include"3bat_pack.h"
#include<iostream>
#include<cstdlib>
#include<string>


#define SIM_SAMPLE_TIME 50000 //us

using namespace std;
Bat_pack::Bat_pack()
{
	//10 ohms
	R_load = 10;
	Sim_ON =0;
}

Bat_pack :: ~Bat_pack(){}


bool Bat_pack :: sim_is_ON()
{return Sim_ON;}

int Bat_pack :: set_R_Load(float _R)
{
	if(_R > 0)
	{
		R_load =_R;
		return 0;
	}
	else
	{
		cout << "ERROR :: -ive and zero values not allowed";
		return -1;
	}

}
float Bat_pack ::get_R_Load(){return R_load;}

/*void Bat_pack ::run_sim(void)
{
pthread_t threads;
Bat_pack * self_ptr;
self_ptr = this; 

if(!Sim_ON)
{
pthread_create(&threads, NULL, thread_run_sim, (void *)self_ptr);

}
pthread_exit(NULL);

}

void  *thread_run_sim(void *x)
{
*/

void Bat_pack ::run_sim(void)
{
time_t now;
tm *localtm;
Bat_cell *bat_sorter_p[_N];
Bat_cell *highest_vbat;

bool switch_2_apply[_N];
double current_2_apply[_N];


Sim_ON = 1;

//for millman's formula
double _millman_N=0.0;
double _millman_D= (1/R_load);
double _millman_V_load =0.0;

double temp_vbat, temp_rbat, temp_high_vbat;

//copy all the battery address in a pointer table
for(int r =0; r <_N; r++)
bat_sorter_p[r] = &(bat[r]);


time(&now);
localtm =localtime(&now);
string s= asctime(localtm);


while(Sim_ON)
{
system("clear");
cout << "SIMULATION STARTED AT ::"<< s;
//0. print all SW states with voltages
for( int p= 0; p < _N ; p++)
cout << "\nbat[" << p << "]" <<	bat_sorter_p[p]->get_vol() << "\t SW state =" << bat_sorter_p[p]->get_SW_state()<< "\t i = " << bat_sorter_p[p]->get_i_load()<< " mA" << endl;


//1.  find first battery with the highest voltage in pack

//start  with first cell
highest_vbat = bat_sorter_p[0];
for( int j =0; j < (_N-1) ;j++)
{
	temp_vbat =bat_sorter_p[j+1]->get_vol();
	temp_high_vbat = highest_vbat->get_vol();
	if( temp_vbat > temp_high_vbat)
		highest_vbat = bat_sorter_p[j+1];
}


/*2. save the cells SW to be turned ON,  which have < 50mV voltage difference then highest vbat.
also, calculate the load currents in advance before turning on the SW,
 to avoid reverse current into battieres*/

/*
USE: Millman's therom
	V on the R_load = N / D
		
where,
		N = sumation_of(Vn/Rn)
                D=summation(1/Rn) + (1/R_load)

Rn = ser_r + int_r

i for any bat cell n = (Vbatt_n - V on the R_load)/(series_Rn + internal_Rn);

*/

//save highest voltage
temp_high_vbat= highest_vbat->get_vol();
cout<<" \n\n debug -- HIGHEST VOLTAGE: " << temp_high_vbat;

_millman_N =0.0;
_millman_D= (1/R_load);
for( int n =0; n < _N ;n++)
{

	temp_vbat = bat_sorter_p[n]->get_vol();

	if(temp_vbat <= bat_sorter_p[n]->get_V_cutoff())
	{switch_2_apply[n] =0;}
	else if( (temp_high_vbat -  temp_vbat )  < 0.050)
	{
		switch_2_apply[n] =1;
//		cout << "keep SW of bat" << n << "ON";
		temp_rbat = (bat_sorter_p[n]->get_ser_res() + bat_sorter_p[n]->get_int_res() );	
	
		//current drawn if R_load =0 ohm, to be corrected later
		current_2_apply[n] 
		= (temp_vbat) /	(temp_rbat); 

		//keep saving the summations(Vn/Rn)
		_millman_N+= current_2_apply[n] ;
		//keep saving the (summations(1/Rn) + (1/R_load))
		_millman_D+= (1/(temp_rbat));		

	}
	else
	{	//cout << "keep SW of bat" << n << "OFF";
		switch_2_apply[n] =0;
	}
}



// calculations may be repeated(_N -1) times in a worst case
repeat_calc:

//3. find the V on the load
_millman_V_load =(_millman_N)/(_millman_D);

//4. review SW to be enabled arr, to check for possible reverse currents

for(int e =0; e <_N ; e++)
{
	temp_vbat = bat_sorter_p[e]->get_vol();
	temp_rbat = (bat_sorter_p[e]->get_ser_res() + bat_sorter_p[e]->get_int_res() );	

	if(switch_2_apply[e])
	{
		
		//calculate current drawn from battery, and correct the current apply array
		current_2_apply[e] = ( (temp_vbat - _millman_V_load)  / (temp_rbat) );

		if(current_2_apply[e] > 0.0)
		{continue;}
		else// if current is -ive keep the cell OFF
		{// batt_current
			switch_2_apply[e] =0;
			current_2_apply[e] =0;
			//adjust the millman's N and D
			_millman_N -=temp_vbat;
			_millman_D -=(1/temp_rbat);
cout << "\n---------RECALC HIT !!!---------------\n";
			goto repeat_calc;
		}

	}
}

//5. Apply all current load on the switches
	for(int y= 0; y < _N ; y++)
	{
		bat_sorter_p[y]->set_SW_state( switch_2_apply[y] , current_2_apply[y]);
	}

_millman_V_load =(_millman_N)/(_millman_D);

cout << "\nvoltage/current available to load(R = "<< R_load <<") :: " << _millman_V_load << "V / " << (_millman_V_load/R_load) << "mA"<< endl; 

cout << "for millman's debug N & D are " << _millman_N <<" "<<_millman_D ;
cout << "\n\n SIMULATION in progress\n"<< endl;
time(&now);
localtm =localtime(&now);
//10 sec animation
for(int h=0; h< ((localtm->tm_sec)%10); h++)
{cout<<" <::> ";}

cout<<"\n\n";


usleep(SIM_SAMPLE_TIME); //wait for 500 msec

}

stop_sim();

// print the latest values after Sim_stopped to verify SW is closed.
system("clear");
cout << "SIMULATION STARTED AT ::"<< s;

for( int p= 0; p < _N ; p++)
cout << "\nbat[" << p << "]" <<	bat_sorter_p[p]->get_vol() << "\t SW state =" << bat_sorter_p[p]->get_SW_state()<< "\t i = " << bat_sorter_p[p]->get_i_load()<< " mA" ;


cout << "\n\nSIMULATION ENDED AT ::"<< asctime(localtm) << endl;;

}

void Bat_pack ::stop_sim()
{Sim_ON = 0;
	for(int y= 0; y < _N ; y++)
	bat[y].set_SW_state( 0, 0);
}


