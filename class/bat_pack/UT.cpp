#include<iostream>
#include<string>
#include"3bat_pack.h"
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<pthread.h>
void *stop_wait(void *x)
{
Bat_pack *w = static_cast<Bat_pack*>(x);

	while(w->sim_is_ON())
	{
		if('.' == getchar())
		{
		w->stop_sim();
		getchar();
		break;
		}	
	}
pthread_exit(NULL);
}

int main()
{

Bat_pack batPack;
pthread_t thread_to_stop;

//TEST 1: worst case switching all the 3 batteries at the margin of 50mV
cout << "\nPLEASE WAIT:: STARTING TESTs, at any time press ('.' + ENTER) move to next UT test";

cout << "\n TEST 1: worst case switching all the 3 batteries at the margin of 50mV\n";
sleep(4);
batPack.bat[0].set_ser_res(0.001);
batPack.bat[1].set_ser_res(0.010);
batPack.bat[2].set_ser_res(0.0001);

batPack.bat[0].set_vol(4.099);
batPack.bat[1].set_vol(4.15);
batPack.bat[2].set_vol(4.1);

batPack.set_R_Load(0.001);


pthread_create(&thread_to_stop, NULL, stop_wait, &batPack);
batPack.run_sim();

//TEST 2: worst case switching all the 3 batteries at the margin of 50mV, near cutoff voltage
cout << "PLEASE WAIT:: STARTING NEXT TEST";
cout << "(press '.' + ENTER) move to next UT test";
cout << "\n TEST 2: worst case switching all the 3 batteries at the margin of 50mV, near cutoff voltage\n";

sleep(4);
batPack.bat[0].set_ser_res(0.001);
batPack.bat[1].set_ser_res(0.010);
batPack.bat[2].set_ser_res(0.0001);

batPack.bat[0].set_vol(4.099);
batPack.bat[1].set_vol(4.15);
batPack.bat[2].set_vol(4.1);

batPack.set_R_Load(0.001);


pthread_create(&thread_to_stop, NULL, stop_wait, &batPack);
batPack.run_sim();


//TEST 3: switching all the 3 batteries having voltages in 3 different discharge curve states.
cout << "PLEASE WAIT:: STARTING NEXT TEST";
cout << "(press '.' + ENTER) move to next UT test";

cout << "\n TEST 3: switching all the 3 batteries having voltages in 3 different discharge curve states.\n";
cout << "(press '.' + ENTER) move to next UT test";
sleep(4);
batPack.bat[0].set_ser_res(0.001);
batPack.bat[1].set_ser_res(0.010);
batPack.bat[2].set_ser_res(0.0001);

batPack.bat[0].set_vol(4.1);
batPack.bat[1].set_vol(3.7);
batPack.bat[2].set_vol(3.0);

batPack.set_R_Load(0.001);


pthread_create(&thread_to_stop, NULL, stop_wait, &batPack);
batPack.run_sim();


//TEST 4: worst case switching all the 3 batteries with same voltage but different series_R

cout << "PLEASE WAIT:: STARTING NEXT TEST";
cout << "(press '.' + ENTER) move to next UT test";
cout << "\n TEST 4: worst case switching all the 3 batteries with same voltage but different series_R\n";


sleep(4);

batPack.bat[0].set_ser_res(0.001);
batPack.bat[1].set_ser_res(0.010);
batPack.bat[2].set_ser_res(0.0001);

batPack.bat[0].set_vol(4.3);
batPack.bat[1].set_vol(4.3);
batPack.bat[2].set_vol(4.3);

batPack.set_R_Load(0.001);


pthread_create(&thread_to_stop, NULL, stop_wait, &batPack);
batPack.run_sim();

cout << "\n\n ALL TESTs COMPLETED(press any key to exit)";

while(!getchar());

return 0;

}

