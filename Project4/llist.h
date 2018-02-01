#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int debug;
typedef struct list_struct LIST;
typedef struct node NODE;

LIST * createList();
extern void addToList(LIST * ls, char * name, int groupsize, char* status);
extern int doesNameExist(LIST * ls, char * name);
extern int updateStatus(LIST * ls, char * name, char * status);
extern char * retrieveAndRemove(LIST * ls, int groupsize);
extern int countGroupsAhead(LIST * l, char * name);
extern void displayGroupSizeAhead();
extern void displayListInformation();

extern void doAdd(LIST * ls);
extern void doCallAhead (LIST * ls);
extern void doWaiting (LIST * ls);
extern void doRetrieve(LIST* ls);
extern void doList (LIST * ls);
extern void doDisplay (LIST * ls);

extern void clearToEoln();
extern int getNextNWSChar();
extern int  getPosInt();
extern char* getName();
extern void printCommands();
