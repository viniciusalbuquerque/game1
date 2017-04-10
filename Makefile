#Hey, this is my first Makefile;

CXX=g++
CXXFLAGS=-std=c++11 -c -Wall -g -I.
OFLAGS=-o

game: main.o Game.o Player.o Map.o Object.o
	$(CXX) main.o Game.o Player.o Map.o Object.o $(OFLAGS) game

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) Game.cpp

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) Player.cpp

Map.o: Map.cpp
	$(CXX) $(CXXFLAGS) Map.cpp

Object.o: Object.cpp
	$(CXX) $(CXXFLAGS) Object.cpp

clean:
	rm -f *.o game

run:
	./game