all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	g++ PhotoMagic.o LFSR.o -o PhotoMagic -lsfml-graphics -lsfml-window -lsfml-system

pixels.o: PhotoMagic.cpp LFSR.hpp
	g++ -c PhotoMagic.cpp -Wall -Werror -ansi -pedantic -lsfml-graphics -lsfml-window -lsfml-system
	
LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -ansi -pedantic

clean:
	rm *.o PhotoMagic 
