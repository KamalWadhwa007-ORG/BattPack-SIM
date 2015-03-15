#include<iostream>
#include<string>
#include"3bat_pack.h"
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<pthread.h>


Bat_pack batPack;

using namespace std;

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


float temp_f;
string command;
//string::size_type sz;



while(command != "exit")
{
 cout << "\n bat-sim $ ";

	cin >> command;
	
	if((command == "set"))	//starts with set
	{
		/*if(batPack.sim_is_ON())
		{
			cout << "ERROR :: stop simulation first to modify any value \n";

			continue;
		}*/
		
		cin >> command;
		if((command == "initial")) //second arg is initail	
		{
			cin >> command;
			if((command == "voltage:")) // 3rd arg is 'voltage:'
			{
			
			for(int k=0; k < _N; k++) // 4th arg to _N are voltage values in float
			{
			cin >> command;

/*GNU compiler issue with < 4.8 versions with stof and strof, not working directly on 'string' type, using const char* instead*/
			//temp_f =strtof(command,&sz);
			sscanf(command.c_str(), "%f",&temp_f);
			batPack.bat[k].set_vol(temp_f);

			}
			continue;						
	
			}else
			{cout << "ERROR in COMMAND !!!\n";

				continue;
			 }

		}else if((command == "load:")) //second arg 'load:'
		{

			cin >> command; //3rd arg is then R_load in ohms
			//temp_f = strtof(command,&sz);
			sscanf(command.c_str(), "%f",&temp_f);
			batPack.set_R_Load(temp_f);

			continue;			

		}else if((command == "series_Rs:")) //second arg 'series_Rs'
		{
			for(int k=0; k < _N; k++) // 3th arg to _N are series resistance in float
			{
			cin >> command;
			// temp_f =strtof(command,&sz);
			sscanf(command.c_str(), "%f",&temp_f);
		batPack.bat[k].set_ser_res(temp_f);							
			}
			continue;			
		}else
		{cout << "ERROR in 'set' COMMAND !!!\n";

				continue;
		
		}

	}//all set commands completed above	
	else if((command == "get"))
	{
		cin >> command;

		if((command == "switch")) //second arg is initail	
		{
			cin >> command;

			if((command == "state")) // 3rd arg is 'voltage:'
			{
			 for(int k=0; k < _N; k++) 
			{
				cout << "\nS" << (k+1) << ": " << (batPack.bat[k].get_SW_state()? "ON":"OFF") << endl;							
			}
			
			}
			else
			{ cout << "ERROR in COMMAND !!!\n";

			}
		continue;
		}
		else if((command == "voltage")) //second arg is initail	
		{
			for(int k=0; k < _N; k++) 
			{
				cout << "\nB" << (k+1) << " voltage: " << batPack.bat[k].get_vol()<< endl;							
			}
		continue;		
		}
		else if((command == "current")) //second arg is initail
		{
			for(int k=0; k < _N; k++) // 3th arg to _N are series resistance in float
			{
				cout << "\nB" << (k+1) << " current: " << batPack.bat[k].get_i_load()<< endl;							
			}

		continue;
		}else
		{
			cout << "ERROR in the 'get' command\n";
		continue;
		}

	}// all get commands handled
	else if((command == "start"))
	{
		cin >> command;
		if(command == "simulation")
		{	
			pthread_t thread_to_stop;
			pthread_create(&thread_to_stop, NULL, stop_wait, &batPack);
			batPack.run_sim();

		}
		else
		{	cout << "ERROR using 'start' command, expected -- 'start simulation'\n";}

		continue;
		
	}
	else if((command == "stop"))
	{
		cin >> command;
		if((command == "simulation"))
		{batPack.stop_sim();}
		else
		{	cout << "ERROR using 'stop' command, expected -- 'stop simulation'\n";}

		continue;
		
	}
	else if(command != "exit") {
		cout << "INVALID Command please refer Readme file\n";
	}



}
pthread_exit(NULL);


}
