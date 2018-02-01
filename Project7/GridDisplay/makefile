GridMain:  GridMain.cpp GridDisplay.o Creature.o Doodlebug.o Ant.o
	g++ -o GridMain GridMain.cpp GridDisplay.o Creature.o Doodlebug.o Ant.o 

gddemo: gddemo.cpp GridDisplay.o
	g++ -o gddemo gddemo.cpp GridDisplay.o

GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -c GridDisplay.cpp

Creature.o: Creature.cpp
	g++ -c Creature.cpp

Doodlebug.o: Doodlebug.cpp Creature.h
	g++ -c Doodlebug.cpp

Ant.o: Ant.o Creature.h
	g++ -c Ant.cpp

clean:
	rm -f *.o GridMain 
