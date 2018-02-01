#include "Creature.h"





 Creature::Creature(){
 	setType(0);
 }




 Creature * Creature::spawn(int spawnRate, Creature * c){
 	if(spawnCycle >= spawnRate){
        {

         int x;
         int y;
         Creature * p = c;
   
        while( p != NULL){
        x = p->getX();
        y = p->getY();
        Creature * c;
        if(!(x == getX()+1 && y == getY()))
         {
          c = new Creature();
          c->setX(getX()+1);
          c->setY(getY());
         }
         else if(!(x == getX()-1 && y == getY())){
          c = new Creature();
          c->setX(getX()-1);
          c->setY(getY());
         }
         else if(!(x == getX() && y == getY()+1)){
          c = new Creature();
          c->setX(getX());
          c->setY(getY()+1);
         }
         else if(!(x == getX() && y == getY()-1)){
          c = new Creature();
          c->setX(getX());
          c->setY(getY()-1);
         }
         if(c == NULL){
            return c;
         }
        

         if(spawnRate == 3){
            c->setType(1);
         }
         else{
            c->setType(2);
         }
      return c;
    }

}
 	}
 }





void Creature::move(Creature * c){
 	 int x = 0;
 	 int y = 0;
     int i = rand() % 4 + 1;
     	printf("%d \n", i);
     switch(i){
     	case 1 :
     	x++;
     	break;

     	case 2 :
     	x--;
        break;

     	case 3 :
     	y++;
        break;

     	case 4 :
     	y--;
     	break;

     	default:
     	break;
     }
 	
 	int xtemp = xpos;
 	int ytemp = ypos;
 	xtemp += x;
 	ytemp += y;
    
    Creature * p = c;
    int xD = p->getX();
    int yD = p->getY();
    
    while(p != NULL){
        if(xtemp == xD && ytemp == yD){return;}
         p->setNext(p->getNext());
         xD = p->getX();
         yD = p->getY();
    }
   
    p = c;
    xD = p->getX();
    yD = p->getY();
    
    while(p != NULL){
        if(xtemp == xD && ytemp == yD){return;}
         p->setNext(p->getNext());
         xD = p->getX();
         yD = p->getY();
    }

 	if(outOfBounds(xtemp, ytemp) == 0){
 		setX(xtemp);
 		setY(ytemp);
 	}
 	
 }




 int Creature::outOfBounds(int x, int y){
    if((x > 19 || x < 0) || (y > 19 || y < 0))
    	return 1;
    else
    	return 0;
 }



void Creature::setSpawnCycle(int set){
   spawnCycle = set;
}


int  Creature::getSpawnCycle(){
return spawnCycle;
}

Creature * Creature::getNext(){
    return next;
}

Creature * Creature::setNext(Creature * c){
	next = c;
}




int  Creature::getX(){
	return xpos;
}


void Creature::setX(int set){
	xpos = set;
}


int  Creature::getY(){
     return ypos;
}


void Creature::setY(int set){
	ypos = set;
}


int  Creature::isDead(){
    return deadFlag;
}


void Creature::setDead(int set){
	 deadFlag = set;
}



void Creature::setType(int t){
	type = t;
}



int Creature::getType(){
	return type;
}



void Creature::dailyActions(Creature * c){

}


void Creature::deleteDeadNodes(Creature * head){
  Creature * currentNode = head;
  Creature * prevNode;
  Creature * temp;
  if(head == NULL){
    return;
  }

  if( head->isDead() ){
    temp = head;
    head = head->getNext();
    delete temp;
    return;
  }

  currentNode = head->getNext() ;
  prevNode = head;

  
  while(currentNode != NULL){
     
   if(currentNode->isDead()){
     temp = currentNode;
     prevNode->setNext(currentNode->getNext());
     currentNode = prevNode->getNext();
     delete temp;
   }
   else{
   prevNode = currentNode;
   currentNode->setNext(currentNode->getNext());
   }
  }
}

  void Creature::addCreature(Creature * head, Creature * c){
  if(c == NULL)
    return;
  
    if(head == NULL){
        c = NULL;
        return;
    }

    if(head->getNext() == NULL){
        head->getNext()->setNext(c);
        return;
    }
    Creature * temp = head;
    head->setNext(temp);

}


void Creature::executeDay(int type, GridDisplay * gd, Creature * head){
    Creature * p = head;
    if(head == NULL)
      return;

    while(p!=NULL){
    	if(p->getType() == type)
       p->dailyActions(head);
    	 p->setNext(p->getNext());
    }
    
    p = head;
    while(p!=NULL){
    	if(p->getType() == type)
        p->deleteDeadNodes(head);
        p->setNext(p->getNext());
      
}
    if(p->getType() == 2){
      gd->setChar(getX(),getY(),'%');
    }
    else if(p->getType() == 1){
      gd->setChar(getX(),getY(),'*');
    }
}

void Creature::updateSpawnCycle(Creature * c){
    Creature * p = c;
    while(p != NULL){
        p->setSpawnCycle(p->getSpawnCycle() + 1);
    }
}

