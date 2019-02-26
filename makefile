main: main.o Game.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryP.o Queue.o stack.o inputVal.o
	g++ -std=c++0x main.o Game.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryP.o Queue.o stack.o inputVal.o -o main
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Game.o: Game.cpp Game.h
	g++ -std=c++0x -c Game.cpp
	
Character.o: Character.cpp Character.h
	g++ -std=c++0x -c Character.cpp
	
Vampire.o: Vampire.cpp Vampire.h
	g++ -std=c++0x -c Vampire.cpp	
	
Barbarian.o: Barbarian.cpp Barbarian.h
	g++ -std=c++0x -c Barbarian.cpp	
	
BlueMen.o: BlueMen.cpp BlueMen.h
	g++ -std=c++0x -c BlueMen.cpp	
	
Medusa.o: Medusa.cpp Medusa.h
	g++ -std=c++0x -c Medusa.cpp	
	
HarryP.o: HarryP.cpp HarryP.h
	g++ -std=c++0x -c HarryP.cpp	
	
Queue.o: Queue.cpp Queue.h
	g++ -std=c++0x -c Queue.cpp
	
stack.o: stack.cpp stack.h
	g++ -std=c++0x -c stack.cpp
	
inputVal.o: inputVal.cpp inputVal.h
	g++ -std=c++0x -c inputVal.cpp

.PHONY: clean

clean:
	rm *.o main
	
valgrind:
	@valgrind --leak-check=full --track-origins=yes ./main