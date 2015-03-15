
BattPack-SIM
--------------

Is a Simualtor for battery pack voltage balancing. based on the series Rs and the LOAD resister connected to battery. which can be set by user before starting the simulation.

commands available to the user

##COMMAND:: 'set'

FORMAT: set [ARG] [value1, ...]

ARG = 
1. 
"initial voltage:" - sets the voltage(V) for the N(3) batteries, need to be followed by 3 values.
eg -

$ set initial voltage: 4.2 4.12 3.995

2. 
"Series_Rs:" - sets the series R(ohm) for the N(3) batteries, need to be followed by 3 values.
eg -
$ set Series_Rs: 54.2 41.12 33.995

3.
"load:" - sets the Load R(ohm) for the N(3) batteries, need to be followed by 1 value.
eg -
$ set load: 54.2 41.12 33.995


##COMMAND:: 'get'

FORMAT: get [ARG]

ARG = 
1. "voltage" - returns the voltage(V) for the N(3) batteries.
eg -
$ get voltage

2. "current" - returns the voltage(V) for the N(3) batteries
eg -
$ get current

3."switch state" - sets the Load R(ohm) for the N(3) batteries, need to be followed by 3 values.
eg -
$ get switch state


##COMMAND:: 'start simulation'

Runs the battery pack simulator, with the battery voltage balancing algorithm.

NOTE: press ('.' + ENTER)  to exit the simulation



