//#include "GridDisplay.h"
#include "Creature.h"
#include "Doodlebug.h"
#include "Ant.h"

int main ( int argc, char** argv )
{
 
GridDisplay gd(20, 20);
int i = 0;

Creature * creatureList = new Creature();
creatureList->setType(1);


for(int i = 0; i < 5; i++){
	
	int x = rand() % 19 + 1;
	int y = rand() % 19 + 1;
 
 Creature * p = creatureList;
 
 while(p != NULL){
 	x = rand() % 19 + 1;
	y = rand() % 19 + 1;
 	if(!(p->getX() == x && p->getY() == y)){
   		Creature * newCreature = new Creature();
   		newCreature->setX(x);
   		newCreature->setY(y);
   		creatureList->addCreature(creatureList, newCreature);
 }
 	}
}

while(1){

 for(int i = 0; i < 20; i++)
 	for (int j = 0; j < 20; j++)
 		gd.setChar(i,j,'.');
creatureList->executeDay(2, &gd, creatureList);
creatureList->executeDay(1, &gd, creatureList);

gd.mySleep(50);
gd.showGrid();
}

 return 1;
}






