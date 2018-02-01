#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>  
#include "GridDisplay.h"
class Creature{

private:
int  type;
int  spawnCycle;
int  daysNotEaten;
int  readyToHatch;
int  deadFlag;
int  xpos;
int  ypos;
Creature * next;
public:

Creature();
Creature * spawn(int spawnRate, Creature * c);
void move(Creature * c);
void setType(int t);
int  getType();
void setSpawnCycle(int set);
int  getSpawnCycle();
int  getX();
void setX(int set);
int  getY();
void setY(int set);
int  isDead();
void setDead(int set);
Creature * getNext();
Creature * setNext(Creature * c);
virtual void dailyActions(Creature * c);

int  outOfBounds(int x, int y);
//For List
void addCreature(Creature * head, Creature * c);
void deleteDeadNodes(Creature * c);
void executeDay(int type, GridDisplay * gd, Creature * head);
void updateSpawnCycle(Creature * c);

protected:
};

#endif
