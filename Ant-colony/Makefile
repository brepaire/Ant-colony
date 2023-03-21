# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

all : main

# Les programmes principaux
# On donne le fichier cpp et la liste des fichiers .o qu'ils utilisent
main: main.cpp coord.o ensCoord.o fourmis.o grille.o place.o



# Les différents composants
# on donne le fichier cpp ainsi que la liste des fichiers .hpp dont ils dépendent
coord.o : coord.cpp coord.hpp
ensCoord.o : ensCoord.cpp ensCoord.hpp coord.hpp
fourmis.o : fourmis.cpp fourmis.hpp coord.hpp
place.o : place.cpp place.hpp fourmis.hpp coord.hpp
grille.o : grille.cpp grille.hpp place.hpp fourmis.hpp coord.hpp ensCoord.hpp




# Pour faire le ménage
clean:
	rm -f main test *.o


