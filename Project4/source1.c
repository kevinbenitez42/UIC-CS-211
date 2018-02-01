#include "llist.h"
/*
void doAdd(LIST * ls, char * name, int groupsize){
  if(doesNameExist(ls, name)){
    fprintf(stderr, "%s\n", "Name already exists. group not added" );
    return;
  }
  addToList(ls, name, groupsize,"waiting");
  printf("%s\n","group added" );
}

void doCallAhead(LIST * ls, char * name, int groupsize){
  if(doesNameExist(ls, name)){
    fprintf(stderr, "%s\n", "Name already exists. group not added" );
    return;
  }
  addToList(ls, name, groupsize,"has not arrived");
  printf("%s\n","Call ahead group added" );
}

void doWaiting(LIST *ls, char * name){
  if(updateStatus(ls, name, "waiting") == 0){
    fprintf(stderr, "%s\n","group is already waiting or does not exist" );
    }
}

void doRetrieve(LIST *ls, int tablesize){
char * string =  retrieveAndRemove(ls, tablesize);
printf("%s %s\n",string, "has been removed" );
}

void doList(LIST *ls, char * name){
  if(!doesNameExist(ls, name)){ fprintf(stderr, "%s\n","name does not exist" );}
  printf("%s %s\n","displaying group sizes ahead of ", name );
  displayGroupSizeAhead(ls);
}

void doDisplay(LIST * list){
  printf("%s %d\n","Total number of groups waiting: ", countGroupsAhead(list, " ") );
  printf("%s\n","===========================" );
  displayListInformation(list);
}
*/

void doAdd(LIST * ls)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Add command requires an integer value of at least 1\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 printf ("Adding group \"%s\" of size %d\n", name, size);

 // add code to perform this operation here
 if(doesNameExist(ls, name)){
   fprintf(stderr, "%s\n", "Name already exists. group not added" );
   return;
 }
 addToList(ls, name, size ,"waiting");

}


void doCallAhead (LIST * ls)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 printf ("Call-ahead group \"%s\" of size %d\n", name, size);

 // add code to perform this operation here
 if(doesNameExist(ls, name)){
   fprintf(stderr, "%s\n", "Name already exists. group not added" );
   return;
 }
 addToList(ls, name, size, "has not arrived");
}

void doWaiting (LIST * ls)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
   }



 // add code to perform this operation here
 int myBool = updateStatus(ls, name, "waiting");
 if(myBool == 1)
 {
 printf ("Waiting group \"%s\" is now in the restaurant\n", name);
 }
 if(myBool == 0){

   fprintf(stderr, "%s\n","group is already waiting or does not exist" );
   }
}

void doRetrieve(LIST* ls)
{
 /* get table size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Retrieve command requires an integer value of at least 1\n");
    printf ("Retrieve command is of form: r <size>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    return;
   }
 clearToEoln();
 printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);

 // add code to perform this operation here
 char * string =  retrieveAndRemove(ls, size);

 if(string == NULL)
 {
   printf("%s\n","nothing to remove" );
 }
 else{
 printf("%s %s\n",string, "has been removed" );
 }
}

void doList (LIST * ls)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
   }

 printf ("Group \"%s\" is behind the following groups\n", name);

 if(!doesNameExist(ls, name)){ fprintf(stderr, "%s\n","name does not exist, heres the whole line" );}
 printf("%s %d\n","total number of groups in front is ", countGroupsAhead(ls, name) );
 displayGroupSizeAhead(ls, name);
}

void doDisplay (LIST * ls)
{
 clearToEoln();
 printf ("Display information about all groups\n");

 // add code to perform this operation here
 printf("%s %d\n","Total number of groups next in line: ", countGroupsAhead(ls, " ") );
 displayListInformation(ls);
}
