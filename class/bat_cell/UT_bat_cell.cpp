#include<iostream>
#include"bat_cell.h"
#include"unistd.h"

using namespace std;

int main()
{
Bat_cell test_cell;

cout << endl <<"Running UT for CLASS :: \"Bat_cell\" "<< endl;

//TEST 1: Don't ALLOW -ive voltage for set function
cout << "TEST 1: Don't ALLOW -ive voltage for set function : ";
if(test_cell.set_vol(-10.0))
{cout << "PASSED" << endl;}
else
{cout << "FAILED" << endl;}


//TEST 2: Don't ALLOW -ive series resitance for set function
cout << "TEST 2: Don't ALLOW -ive series resitance for set function: ";
if(test_cell.set_ser_res(-10.0))
{cout << " PASSED" << endl;}
else
{cout << " FAILED" << endl;}


//TEST 3: ALLOW Zero or +ive series resitance for set function
cout << "TEST 3: SET Zero or +ive series resistance : ";
if( (test_cell.set_ser_res(0.0)) || (test_cell.set_ser_res(10.0)) )
{cout << "FAILED" << endl;}
else
{cout << "PASSED" << endl;}


//test 4: ALLOW Zero or +ive batt voltage for set function
cout << "TEST 4: ALLOW Zero or +ive batt voltage for set function : ";
if( (test_cell.set_vol(0.0)) || (test_cell.set_vol(10.0)) )
{cout << "FAILED" << endl;}
else
{cout << "PASSED" << endl;}


//test 5: Check Switch Toggling, with Zero load.
cout << "TEST 5: Check Switch Toggling : ";
if(test_cell.set_SW_state( !(test_cell.get_SW_state()) , 0.0 ))
{cout << "FAILED" << endl;}
else
{cout << "PASSED" << endl;}




float V_old, V; // random value
long long int Q;


// TEST6.A : convert V_to_Q, V = 3.92
V_old = V  =3.920;

cout << "\n TEST 6.A : convert V_to_Q, random voltage "<< V <<"( in V_top - V_nom range) \n ";
Q= test_cell.convert_V_to_Q(V);
cout << " \n \n charge(Q) for the voltage(V) =" << V << " is " << Q << "mAseconds / " << (Q/3600) << "mAh" << endl;

// TEST 6.B : convert Q_to_V
cout << "\n TEST 6.B : convert Q_to_V, check voltage "<< V <<"( in V_top - V_nom range) \n ";
V= test_cell.convert_Q_to_V(Q);
cout << "\n\n voltage(V) for the charge(Q) =" << Q << " is " << V << "Volts" << endl;

if(V_old == V)
{cout << "TEST 6 :: PASSED\n\n";}
else
{cout << "TEST 6 :: FAILED\n\n";}


// TEST 7.A : convert V_to_Q, V = 3.3
V_old = V = 3.3;

cout << "\n TEST 7.A : convert V_to_Q, random voltage "<< V <<"( in V_nom - V_cutoff range) \n ";
Q= test_cell.convert_V_to_Q(V);
cout << " \n \n charge(Q) for the voltage(V) =" << V << " is " << Q << "mAseconds / " << (Q/3600) << "mAh" << endl;

// TEST 7.B : convert Q_to_V
cout << "\n TEST 7.B : convert Q_to_V, check voltage "<< V <<"( in V_nom - V_cutoff range) \n ";
V= test_cell.convert_Q_to_V(Q);
cout << "\n\n voltage(V) for the charge(Q) =" << Q << " is " << V << "Volts" << endl;

if(V_old == V)
{cout << "TEST 7 :: PASSED\n\n";}
else
{cout << "TEST 7 :: FAILED\n\n";}

// TEST 8.A : convert V_to_Q, V = 4.08
V_old = V = 4.08;

cout << "\n TEST 8.A : convert V_to_Q, random voltage "<< V <<"( in V_max - V_top range) \n ";
Q= test_cell.convert_V_to_Q(V);
cout << " \n \n charge(Q) for the voltage(V) =" << V << " is " << Q << "mAseconds / " << (Q/3600) << "mAh" << endl;

// TEST 8.B : convert Q_to_V
cout << "\n TEST 8.B : convert Q_to_V, check voltage "<< V <<"( in V_max - V_top range) \n ";
V= test_cell.convert_Q_to_V(Q);
cout << "\n\n voltage(V) for the charge(Q) =" << Q << " is " << V << "Volts" << endl;


if(V_old == V)
{cout << "TEST 8 :: PASSED\n\n";}
else
{cout << "TEST 8 :: FAILED\n\n";}


/*  TEST 9 :: to check for the battery draining by i_load_mA current  */

float _mA = 1000000.0;
cout << "TEST9:: To check discharge curve, with current load(i_load_mA) = " << _mA << " mA \n";

cout << "START :: V = " << test_cell.get_vol() << endl;
cout << "turning ON the SW" << endl;

test_cell.set_SW_state(1, _mA);
float V_temp;
for(int i=0; i<20; i++)
{
//multiple enable/disable SW added to verify proper sequence of Battery voltage update

test_cell.set_SW_state(0, _mA);
test_cell.set_SW_state(1, _mA);
V_temp = test_cell.get_vol();

cout << i << ". " << V_temp << " V  " << test_cell.get_i_load() << " mA" << endl;

usleep(1000000);

test_cell.set_SW_state(0, _mA);
test_cell.set_SW_state(1, _mA);

}

cout << "\nNOTE for TEST 9, OBSERVE THE SEQ ABOVE TO JUDGE IF IT MATCHES THE DISCHARGE CURVE\n\n";






return 0;
}
