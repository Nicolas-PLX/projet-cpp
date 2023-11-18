CPP=g++ --std=c++11 -Wall
CCO= $(CPP) -c $<

OBJECTS = Main.o Plateau.o Case.o Piece.o

all: $(OBJECTS)
	$(CPP) -o programme $(OBJECTS)
	./programme

Main.o : Main.cpp
	$(CCO)
Plateau.o : source/plateau/Plateau.cpp header/Plateau.hpp header/Case.hpp
	$(CCO)
Case.o : source/plateau/Case.cpp header/Case.hpp header/Piece.hpp
	$(CCO)
Piece.o : source/plateau/Piece.cpp header/Piece.hpp
	$(CCO)


clean : 
	@rm -f *.o test