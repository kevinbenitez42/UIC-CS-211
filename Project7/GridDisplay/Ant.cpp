#include "Ant.h"

Ant::Ant(){
	setType(1);
}

void Ant::dailyActions(Creature * c){
	move(c);
	spawn(3, c);
}