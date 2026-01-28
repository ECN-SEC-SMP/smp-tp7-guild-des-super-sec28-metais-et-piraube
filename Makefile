EXEC= tp7
CXXFLAGS= -g -O0 -Wall -std=c++17

$(EXEC) : Point.o main.o
	g++ -o $(EXEC) Point.o main.o

main.o : main.cpp Point.h
	g++ -c $(CXXFLAGS) main.cpp

Point.o : Point.cpp Point.h
	g++ -c $(CXXFLAGS) Point.cpp

clean :
	rm -f $(EXEC) *.o