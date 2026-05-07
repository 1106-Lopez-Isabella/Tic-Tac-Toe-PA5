game: main.o user.o player.o computer.o board.o helpers.o
	g++ -o game main.o user.o player.o computer.o board.o helpers.o

main.o: main.cpp board.h player.h computer.h helpers.h
	g++ -c main.cpp

user.o: user.cpp user.h 
	g++ -c user.cpp

player.o:  player.cpp player.h user.h validInput.h
	g++ -c player.cpp

computer.o: computer.cpp computer.h  user.h
	g++ -c computer.cpp

board.o: board.cpp board.h validInput.h
	g++ -c board.cpp

helpers.o: helpers.cpp helpers.h user.h player.h computer.h board.h validInput.h
	g++ -c helpers.cpp	

clean:
	rm *.o game
