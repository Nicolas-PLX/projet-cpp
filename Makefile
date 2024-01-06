CPP=g++ --std=c++11 -Wall
CCO= $(CPP) -c $<

OBJECTS = Main.o Plateau.o Case.o Piece.o Jeux.o Dames.o Incognito.o Joueur.o Partie.o

all: $(OBJECTS)
	$(CPP) -o programme $(OBJECTS)
	./programme

Main.o : Main.cpp
	$(CCO)
Plateau.o : source/plateau/Plateau.cpp header/Plateau.hpp header/Case.hpp header/Joueur.hpp
	$(CCO)
Case.o : source/plateau/Case.cpp header/Case.hpp header/Piece.hpp
	$(CCO)
Piece.o : source/plateau/Piece.cpp header/Piece.hpp header/Joueur.hpp
	$(CCO)
Jeux.o : source/jeux/Jeux.cpp header/Jeux.hpp header/Plateau.hpp header/Joueur.hpp
	$(CCO)
Dames.o : source/jeux/Dames.cpp header/Dames.hpp header/Jeux.hpp
	$(CCO)
Incognito.o : source/jeux/Incognito.cpp header/Incognito.hpp header/Jeux.hpp
	$(CCO)
Joueur.o : source/joueur/Joueur.cpp header/Joueur.hpp 
	$(CCO)
Partie.o : source/Partie.cpp header/Partie.hpp header/Jeux.hpp header/Joueur.hpp header/Dames.hpp header/Incognito.hpp
	$(CCO)


clean : 
	@rm -f *.o test