
all:
	g++ -c ./class/bat_cell/bat_cell.cpp -o ./class/bat_cell/bat_cell.o
	g++ -c ./class/bat_pack/3bat_pack.cpp -o ./class/bat_pack/3bat_pack.o
	g++ -c bat-sim_REL.cpp  

	g++ -pthread bat-sim_REL.o ./class/bat_pack/3bat_pack.o ./class/bat_cell/bat_cell.o -o BattPack-SIM.exe

clean: 
	rm -f bat-sim_REL.o ./class/bat_pack/3bat_pack.o ./class/bat_cell/bat_cell.o BattPack-SIM.exe
