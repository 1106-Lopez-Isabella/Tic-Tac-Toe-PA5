game: computer.o player.o user.o board.o main.o helper.o
	g++ -o game computer.o player.o user.o board.o main.o helper.o

main.o: main.cpp helper.h
	g++ -c main.cpp

player.o: player.h player.cpp helper.h
	g++ -c player.cpp

helper.o: helper.h helper.cpp
	g++ -c helper.cpp

computer.o: computer.h computer.cpp
	g++ -c computer.cpp

user.o: user.h user.cpp
	g++ -c pet.cpp

board.o: board.h board.cpp
	g++ -c toy.cpp

clean:
	rm *.o game
