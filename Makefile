CPP=g++ --std=c++11 -Wall
CCO= $(CPP) -c $<

OBJECTS = Main.o

all: $(OBJECTS)
	$(CPP) -o programme $(OBJECTS)
	./programme

Main.o : Main.cpp
	$(CCO)


clean : 
	@rm -f *.o test