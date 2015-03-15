#include<iostream>
#include<string.h>
#include"3bat_pack.h"


using namespace std;

char **convert_command_to_words(char *)
{


}

int main()
{

Bat_pack batPack;
float temp_f;
string command;


while(command != "exit")
{
 cout << "\n bat-sim $ ";

	cin >> command;
	
	if(!strcmp(command, "set"))	//starts with set
	{
		if(batPack.sim_is_ON())
		{
			cout << "ERROR :: stop simulation first to modify any value \n";

			continue;
		}
		
		cin >> command;
		if(!strcmp(command, "initial")) //second arg is initail	
		{
			cin >> command;
			if(!strcmp(command, "voltage:")) // 3rd arg is 'voltage:'
			{
			
			for(int k=0; k < _N; k++) // 4th arg to _N are voltage values in float
			{
			cin >> command;
			temp_f =stof(command);
			batPack.bat[k].set_vol(temp_f);

			}
			continue;						
	
			}else
			{cout << "ERROR in COMMAND !!!\n";

				continue;
			 }

		}else if(!strcmp(command, "load:")) //second arg 'load:'
		{

			cin >> command; //3rd arg is then R_load in ohms
			temp_f =stof(command);
			batPack.set_R_Load(temp_f);

			continue;			

		}else if(!strcmp(command, "series_Rs:")) //second arg 'series_Rs'
		{
			for(int k=0; k < _N; k++) // 3th arg to _N are series resistance in float
			{
			cin >> command;
			temp_f =stof(command);
		batPack.bat[k].set_ser_res(temp_f);							
			}
			continue;			
		}else
		{cout << "ERROR in 'set' COMMAND !!!\n";

				continue;
		
		}

	}//all set commands completed above	
	else if(!strcmp(command, "get"))
	{
		cin >> command;

		if(!strcmp(command, "switch")) //second arg is initail	
		{
			cin >> command;
			if(!strcmp(command, "state")) // 3rd arg is 'voltage:'
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
		else if(!strcmp(command, "voltage")) //second arg is initail	
		{
			for(int k=0; k < _N; k++) 
			{
				cout << "\nB" << (k+1) << " voltage: " << batPack.bat[k].get_vol()<< endl;							
			}
		continue;		
		}
		else if(!strcmp(command, "current")) //second arg is initail
		{
			for(int k=0; k < _N; k++) // 3th arg to _N are series resistance in float
			{
				cout << "\nB" << (k+1) << " current: " << batPack.bat[k].get_vol()<< endl;							
			}

		continue;
		}else
		{
			cout << "ERROR in the 'get' command\n";
		continue;
		}

	}// all get commands handled
	else if(!strcmp(command, "start"))
	{
		cin >> command;
		if(!strcmp(command, "simulation"))
		{batPack.run_sim();}
		else
		{	cout << "ERROR using 'start' command, expected -- 'start simulation'\n";}

		continue;
		
	}
	else if(!strcmp(command, "stop"))
	{
		cin >> command;
		if(!strcmp(command, "simulation"))
		{batPack.stop_sim();}
		else
		{	cout << "ERROR using 'stop' command, expected -- 'stop simulation'\n";}

		continue;
		
	}


cout << "INVALID Command please refer Readme file\n";


}



}
