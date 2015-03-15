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

//TEST 1: worst case switching all the 3 batteries at the margin

batPack.bat[0].set_ser_res(0.001);
batPack.bat[1].set_ser_res(0.010);
batPack.bat[2].set_ser_res(0.0001);

batPack.bat[0].set_vol(4.099);
batPack.bat[1].set_vol(4.15);
batPack.bat[2].set_vol(4.1);

batPack.set_R_Load(0.001);

pthread_t thread_to_stop;
pthread_create(&thread_to_stop, NULL, stop_wait, &batPack);
batPack.run_sim();

}

