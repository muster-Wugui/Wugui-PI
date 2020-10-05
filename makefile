all:main
main:main.o tinpi_lib.o 
	g++  -lwiringPi main.o tinpi_lib.o -o main
main.o:main.cpp
	g++ -c main.cpp -lwiringPi
tinpi_lib.o:tinpi_lib.cpp 
	g++ -c tinpi_lib.cpp -lwiringPi
clean:
	rm -rf *o main
