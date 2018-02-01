#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Airport.h"
class TravelNetwork
{
 private:
   // Create the Data Members for the Travel Network here
   Airport * travelNetwork;
   MyNode_s * filenames;
   MyNode_s * head;
   int size;
   int count_filenames;
 public:
 
 // Use a constructor to initialize the Data Members for Travel Network
 TravelNetwork()
 {
 	travelNetwork = createNetwork(10);
 	size = 10;
 	head = NULL;
 }
  
 MyNode_s * getFileNames(){
 	return filenames;
 }

void insertFileName(char * istr){
   MyNode_s * temp;
   MyNode_s * nodeToAdd = new MyNode_s(istr);
   if(head == NULL){
   	head = nodeToAdd;
   }
   else{
   	temp = head;
   	head = nodeToAdd;
   	head->setNext(temp);

   }
   count_filenames++;
}

 Airport * createNetwork(int numOfAirports){
 	Airport * returnAirports = new Airport[numOfAirports];
 	size = numOfAirports;
 	for(int i = 0; i < size; i++){
 		returnAirports[i].setAirportNumber(i + 1);
 	}

 	return returnAirports;
 } 

 void printNetwork(){
 	for(int i = 0; i < size; i++)
 		travelNetwork[i].printAirport();
 }

 int checkArgs(char * arg1, char * arg2){
 	if(arg1 == NULL || arg2 == NULL){
    		printf("%s \n", "invalid input: not enough arguments");
    		return 0;
    	}
    return 1;
 }


 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
  std::cout << input;
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    char* firstNum;
    char* secondNum;
    command   = strtok (input ,  " \r\n\t");
    firstNum  = strtok (NULL  ,  " \r\n\t");
    secondNum = strtok (NULL  ,  " \r\n\t");
   
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      exit(1);
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel(firstNum, secondNum);
     
    else if ( strcmp (command, "r") == 0) 
      doResize(firstNum);

    else if ( strcmp (command, "i") == 0) 
      doInsert(firstNum,secondNum);

    else if ( strcmp (command, "d") == 0) 
      doDelete(firstNum,secondNum);

    else if ( strcmp (command, "l") == 0)
      doList(); 

    else if ( strcmp (command, "f") == 0) 
      doFile(firstNum);

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
    input = fgets ( buffer, 300, inFile );   // get the next line of input
     
  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 
 void doTravel(char * firstNum, char * secondNum)
 {
   
   	if(checkArgs(firstNum, secondNum) == 0){ return;}
 	int val1_t = atoi(firstNum);
    int val2_t = atoi(secondNum);

 	 if ( val1_t == 0 && strcmp (firstNum, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   if ( val2_t == 0 && strcmp (secondNum, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1_t, val2_t);
    int airport = atoi(firstNum);
 	int value   = atoi(secondNum);
 	if(testRange(airport) == 0 || testRange(value) == 0){ return ;}
 	depthFirstSearchHelper(airport, value);
 }


void markAirport(int airport, int val){
	if(val == 0)
	travelNetwork[airport - 1].setVisited(0);
	else
	travelNetwork[airport - 1].setVisited(0);
}

void markAirportsUnvisited(){
	for(int i = 0; i <= size; i++)
	{
		markAirport(i, 0);
	}
}

void depthFirstSearchHelper(int x, int y){
	markAirportsUnvisited();
	if(dfs(x,y) == 1)
		printf("%s%d%s%d%s ","You can get from airport ", x," to airport ", y, " in one or more flights" );
  else
   	printf("%s%d%s%d%s ","You can NOT get from airport ", x," to airport ", y, " in one or more flights\n" );
}


int dfs(int a, int b){
	MyNode * head_d = travelNetwork[a - 1].getList()->getHead();
	MyNode * p = head_d;
	while(p != NULL){
		if(p->getVal() == b)
			return 1;
		if(travelNetwork[p->getVal() - 1].getVisited() == 0){
		   travelNetwork[p->getVal() - 1].setVisited(1);
		   if(dfs(p->getVal(),b) == 1)
		   {
		   	return 1;
		   }
		}
		p = p->getNext();
}
return 0;
}











 
 void doResize(char * val)
 {

int resizeVal = atoi(val);
 if(resizeVal <= 0){
  printf("%s\n","no resize was done" );
  return;
 }
  for(int i = 0; i < size; i++){
  	travelNetwork[i].resetAirport();
  	
  
  }
  free(travelNetwork);
  travelNetwork = createNetwork(resizeVal);
 }
 
 int testRange(int test){
 	if((test > size) || (test <= 0)){ 
 		printf("%s\n","invalid: out of range" );
 		return 0;
 		}
 		return 1;
 }

 void doInsert(char * firstNum, char * secondNum)
 {
 	if(checkArgs(firstNum, secondNum) == 0){ return;}
 	int val1_i = atoi(firstNum);
    int val2_i = atoi(secondNum);

 	 if ( val1_i == 0 && strcmp (firstNum, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

 if ( val2_i == 0 && strcmp (secondNum, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

 	
 	int airport = atoi(firstNum);
 	int value   = atoi(secondNum);
 	if(testRange(airport) == 0 || testRange(value) == 0){ return ;}
 	travelNetwork[airport - 1].insertValue(value);
 	//printNetwork();
 }
 
 void doDelete(char * firstNum, char * secondNum)
 {
 	if(checkArgs(firstNum, secondNum) == 0){ return;}
   int val1_d = atoi(firstNum);
   int val2_d = atoi(secondNum);

 	if ( val1_d == 0 && strcmp (firstNum, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

 if ( val2_d == 0 && strcmp (secondNum, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

 	if(checkArgs(firstNum, secondNum) == 0){ return;}
 	int airport = atoi(firstNum);
 	int value   = atoi(secondNum);

 	if(testRange(airport) == 0 || testRange(value) == 0){ return ;}
 	travelNetwork[airport - 1].deleteValue(value);
 	//printNetwork();
 }
 
 void doList()
 {
   printNetwork();
 }
 
 void doFile(char * fname)
 {
   
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);
   
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns
   
   
   MyNode_s * p = head;
   while(p != NULL){
   	printf("            %s\n",p->getString());
   	if(strcmp (p->getString(), fname) == 0){
   		//printf("             %s\n",p->getString());
   		//printf("             %s\n",fname;
   		printf("%s\n", "sorry collision");
    	return;
   	}
   	p = p->getNext();
   	
   }
   insertFileName(fname);
   FILE * newFile = fopen(fname , "r");
   processCommandLoop(newFile);
   fclose(newFile);
 }
};

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the airport adjcency list
  TravelNetwork airportData;
   
  // call the method that reads and parses the input
  airportData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }
