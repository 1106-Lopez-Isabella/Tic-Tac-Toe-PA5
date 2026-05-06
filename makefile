game: computer.o player.o user.o board.o main.o helper.o
	g++ -o game computer.o player.o user.o board.o main.o helper.o

main.o: main.cpp helper.h board.h computer.h player.h user.h
	g++ -c main.cpp

player.o:  player.cpp player.h user.h board.h helper.h
	g++ -c player.cpp

computer.o: computer.cpp computer.h  user.h
	g++ -c computer.cpp

user.o: user.cpp user.h 
	g++ -c pet.cpp

board.o: board.cpp board.h 
	g++ -c toy.cpp

helper.o: helper.cpp helper.h 
	g++ -c helper.cpp

clean:
	rm *.o game
