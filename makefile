CXXFLAGS=-g -std=c++11 -Wall -pedantic

beatTheBeatles: main.o Item.o ItemBag.o Space.o Begin.o End.o Ringo.o John.o Paul.o George.o validateInput.o Player.o
	g++ main.o Item.o ItemBag.o Space.o Begin.o End.o Ringo.o John.o Paul.o George.o validateInput.o Player.o -o beatTheBeatles

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

Item.o: Item.cpp Item.hpp
	g++ $(CXXFLAGS) -c Item.cpp

ItemBag.o: ItemBag.cpp ItemBag.hpp
	g++ $(CXXFLAGS) -c ItemBag.cpp

Space.o: Space.cpp Space.hpp
	g++ $(CXXFLAGS) -c Space.cpp

Begin.o: Begin.cpp Begin.hpp
	g++ $(CXXFLAGS) -c Begin.cpp

End.o: End.cpp End.hpp
	g++ $(CXXFLAGS) -c End.cpp

Ringo.o: Ringo.cpp Ringo.hpp
	g++ $(CXXFLAGS) -c Ringo.cpp

John.o: John.cpp John.hpp
	g++ $(CXXFLAGS) -c John.cpp

Paul.o: Paul.cpp Paul.hpp
	g++ $(CXXFLAGS) -c Paul.cpp

George.o: George.cpp George.hpp
	g++ $(CXXFLAGS) -c George.cpp

validateInput.o: validateInput.cpp validateInput.hpp
	g++ $(CXXFLAGS) -c validateInput.cpp

Player.o: Player.cpp Player.hpp
	g++ $(CXXFLAGS) -c Player.cpp

clean:
	rm *.o beatTheBeatles