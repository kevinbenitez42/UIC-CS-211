#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Creature.h"

class Doodlebug: public Creature{
private:
public:
Doodlebug();
void dailyActions(Creature * c);
int hunt();
void starve();
int hunt(Creature * c);
void  setDaysNotEaten(int set);
int   getDaysNotEaten();
protected:
};

#endif 

