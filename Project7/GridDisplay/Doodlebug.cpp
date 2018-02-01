#include "Doodlebug.h"
#include "Creature.h"
Doodlebug::Doodlebug()
{
	setType (2);
}


void Doodlebug::starve(){
	if(getDaysNotEaten() >= 8){
		setDead(1);
	}
}


int Doodlebug::getDaysNotEaten(){
    return getDaysNotEaten();
}

void Doodlebug::setDaysNotEaten(int set){
     setDaysNotEaten(set);
}


int Doodlebug::hunt(Creature * c){

    int x;
    int y;
    Creature * p = c;
    
    while( p != NULL){
        x = p->getX();
        y = p->getY();
    if(p->getType() == 1){
        if(x == getX()+1 && y == getY())
         {
            p->setDead(1);
            setX(getX()+1);
            setY(getY());
            return 1;
         }

         if(x == getX()-1 && y == getY()){
            p->setDead(1);
            setX(getX()-1);
            setY(getY());
            return 1;
         }

         if(x == getX() && y == getY()+1){
            p->setDead(1);
            setX(getX());
            setY(getY()+1);
            return 1;
         }

         if(x == getX() && y == getY()-1){
            p->setDead(1);
            setX(getX());
            setY(getY()-1);
            return 1;
         }
     }
      setDaysNotEaten(getDaysNotEaten() + 1);
      return 0;
    }

}


void Doodlebug::dailyActions(Creature * c){
	int succesful = hunt(c);
	if(!succesful)
		move(c);
	starve();
    setDaysNotEaten(getDaysNotEaten() + 1);
}