
all:
	g++ -c -pthread UT_3bat_pack.cpp 3bat_pack.cpp ../bat_cell/bat_cell.cpp UT.cpp
	g++ -pthread UT_3bat_pack.o 3bat_pack.o ../bat_cell/bat_cell.o -o UT_shell_test.exe
	g++ -pthread UT.o 3bat_pack.o ../bat_cell/bat_cell.o -o UT.exe
