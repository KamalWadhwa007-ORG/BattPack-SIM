#include<iostream>
#include"bat_cell.h"

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

//test 5: Check Switch Toggling
cout << "TEST 5: Check Switch Toggling : ";
if(test_cell.set_SW_state( !(test_cell.get_SW_state())))
{cout << "FAILED" << endl;}
else
{cout << "PASSED" << endl;}

return 0;
}
