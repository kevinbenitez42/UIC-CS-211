#include "Airport.h"

MyNode::MyNode(int value){
	val = value;
	next = NULL;
}


int MyNode::getVal(){
	return val;
}
MyNode * MyNode::getNext(){
	return next;
}
void MyNode::setNext(MyNode* node){
	next = node;
}

MyNode_s::MyNode_s(char * istr){
	str = istr;
}

char * MyNode_s::getString(){
	return str;
}

void MyNode_s::setNext(MyNode_s * node){
	next = node;
}

MyNode_s * MyNode_s::getNext(){
	return next;
}


MyList::MyList(){
	head = NULL;
	count = 0;
}


MyNode * MyList::getHead(){
	return head;
}

void MyList::insertValue(int value){
   MyNode * temp;
   MyNode * nodeToAdd = new MyNode(value);
   if(head == NULL){
   	head = nodeToAdd;
   }
   else{
   	temp = head;
   	head = nodeToAdd;
   	//head->next = temp;
   	head->setNext(temp);

   }
   count++;
}




int MyList::deleteValue(int value){
  // MyNode * p    = head->next;
   
   if( head == NULL )
     return 0;
   MyNode * p = head->getNext();
   MyNode * prev = head;

   MyNode * temp = head;
   
   if(head->getVal() == value){
   	head = temp->getNext();
   	delete temp;
   	return 1;
   }
   
   if(value == head->getVal() && head->getNext() == NULL)
   {
   	//head = temp->next;
   	head = temp->getNext();
   	delete temp;
   	return 1;
   }
 
   	while(p != NULL){
   	if(p->getVal() == value){
   		prev->setNext(p->getNext());
   		delete p;
   		return 1;
   	}
   	 
   	 //prev = prev->next;
       prev = prev->getNext();
   	 //p    = p->next;
   	 p = p->getNext();

   }
return 0;
}




int MyList::getNumberOfCurrentsValues(){
	return count;
}




int MyList::getNthValue(int n){
	MyNode * p = head;
	if(n > count)
		return 0;

	while( n != 1){
		//p = p->next;
		p = p->getNext();
		n--;
	}

	return p->getVal();
}




Airport::Airport(){
	setVisited(0);
	list = new  MyList();
}




int  Airport::getAirportNumber(){
	return airportNumber;
}




void Airport::setAirportNumber(int number){
	airportNumber = number;
}




int  Airport::getVisited(){
	return visited;
}




void Airport::setVisited(int set){
	visited = set;
}

MyList * Airport::getList(){
	return list;
}


void Airport::insertValue(int value){
	list->insertValue(value);
}

void Airport::deleteValue(int value){
	list->deleteValue(value);
}

void Airport::printAirport(){
	std::cout << "Airport number : "; 
	std::cout << airportNumber;
	std::cout << " -> ";
	list->printList();
	std::cout << "\n";
}




void MyList::printList(){
	MyNode * p = head;
	while(p != NULL){
		std::cout << "[";
		std::cout << p->getVal();
		std::cout << "] ";
		//p = p->next;
		p = p->getNext();
	}
}




void MyList::resetList(){
	MyNode * p = head;
	MyNode * temp;
	while(p != NULL)
	{
		temp = p;
		p = p->getNext();
		delete temp;
		count--;
	}
}




void Airport::resetAirport(){
	list->resetList();
	delete list;
	list = NULL;
}

