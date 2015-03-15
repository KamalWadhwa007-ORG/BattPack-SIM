
#include "../bat_cell/bat_cell.h"

// pack of 3 cells
#define _N 3

#include<iostream>
#include<string.h>

using namespace std;

class Bat_pack{

private:
//indicates if simulator is running or not 

float R_load;
bool Sim_ON;

public:

//3 bat cell pack.
Bat_cell bat[_N];
//load on bat in Ohms and the i_load for on each battery(deduced from Millman's theoram)
float i_load[_N];

Bat_pack();
~Bat_pack();

void run_sim();

int set_R_Load(float);
float get_R_Load();

bool sim_is_ON();
void stop_sim();
};

