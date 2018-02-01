#include <iostream>

class MyNode{

private:
	int val;

	MyNode * next;
public:
	MyNode(int value);
	int getVal();
	MyNode * getNext();
	void setNext(MyNode* node);
};

class MyNode_s{

private:
	char * str;

	MyNode_s * next;
public:
	MyNode_s(char * istr);
	char * getString();
	MyNode_s * getNext();
	void setNext(MyNode_s * node);

};



class MyList{

private:
	MyNode * head;
	int count;

public:
	MyList();

	void insertValue(int value);
	int  deleteValue(int value);
	int  getNumberOfCurrentsValues();
	int  getNthValue(int n);
	MyNode * getHead();
    void printList();
    void resetList();
};



class Airport{

private:
int airportNumber;
int visited;
MyList * list;

public:

	Airport();
	int  getAirportNumber();
	void setAirportNumber(int number);
	void deleteValue(int value);
	int  getVisited(); 
	void setVisited(int set);
	MyList * getList();
	void insertValue(int value);
	void printAirport();
    void resetAirport();
};