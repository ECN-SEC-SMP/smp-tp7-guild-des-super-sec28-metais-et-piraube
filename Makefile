EXEC= tp7
CXXFLAGS= -g -O0 -Wall -std=c++17

$(EXEC) : Point.o Forme.o Cercle.o Rectangle.o Carre.o ListeFormes.o main.o
	g++ -o $(EXEC) Point.o Forme.o Cercle.o Rectangle.o Carre.o ListeFormes.o main.o

main.o : main.cpp Point.h Forme.h Cercle.h Rectangle.h Carre.h
	g++ -c $(CXXFLAGS) main.cpp

Point.o : Point.cpp Point.h
	g++ -c $(CXXFLAGS) Point.cpp

Forme.o : Forme.cpp Forme.h Point.h
	g++ -c $(CXXFLAGS) Forme.cpp

Cercle.o : Cercle.cpp Cercle.h Forme.h Point.h
	g++ -c $(CXXFLAGS) Cercle.cpp

Rectangle.o : Rectangle.cpp Rectangle.h Forme.h Point.h
	g++ -c $(CXXFLAGS) Rectangle.cpp

Carre.o : Carre.cpp Carre.h Rectangle.h Forme.h Point.h
	g++ -c $(CXXFLAGS) Carre.cpp

ListeFormes.o : ListeFormes.cpp ListeFormes.h Point.cpp Point.h Forme.cpp Forme.h Cercle.cpp Cercle.h Rectangle.cpp Carre.cpp Carre.h
	g++ -c $(CXXFLAGS) ListeFormes.cpp

clean :
	rm -f $(EXEC) *.o