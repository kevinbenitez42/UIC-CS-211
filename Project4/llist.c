#include "llist.h"
int debug;
struct node{
  char * name;
  int    groupsize;
  char * status;
  NODE * next;
};
struct list_struct{
  NODE * head;
  NODE * back;
  int length;
};
void debugMode(NODE* p);
LIST * createList();
NODE * createNode();
void fillInfo(NODE * node, char * name, int groupsize, char* status);
void pushfront(LIST * ls, char * name, int groupsize, char* status);
void pushback(LIST * ls, char * name, int groupsize, char* status);
void popfront(LIST * ls);
void popback(LIST * ls);
void printList(LIST * l);
NODE * retrieveByName(LIST * l, char * name, int debug);
NODE * retrieveByGroupSize(LIST * l, int groupsize);
int nameExists(LIST * l, char * name);
int groupExists(LIST * l, int groupsize);
int removeNode(LIST * l);

void addToList(LIST * ls, char * name, int groupsize, char * status){
  pushback(ls, name, groupsize, status);
}

int doesNameExist(LIST * ls, char * name){
  return nameExists(ls , name);
}

char * retrieveAndRemove(LIST * ls, int groupsize){
  char * returnString;
  NODE * p = ls->head;

  if(ls->head == NULL){return NULL;}

    if(ls->head->groupsize <= groupsize){
      returnString = ls->head->name;
      popfront(ls);
      return returnString;
    }
if(ls->head->next == NULL){
  return NULL;
}
  while(p->next!= NULL){
    if(p->next->groupsize <= groupsize){
      NODE * temp = p->next;
      p->next = p->next->next;
      returnString = temp->name;
      free(temp);
      return returnString;
    }
    debugMode(p);
    p = p->next;
  }

}

int countGroupsAhead(LIST * ls, char * name){
  NODE * p = ls->head;
  int count = 0;
  while((p != NULL))
  {
    if(strcmp(name, p->name) != 0){
    count++;
  }
    debugMode(p);
    p = p->next;

  }
  return count;
}
NODE * retrieveByName(LIST * l, char * name, int deblug){
  NODE * p = l->head;
  while(p != NULL)
  {
    if(strcmp(name , p->name) == 0)
    {
      return p;
    }

    if(deblug == 1)
    {
      printf("%s\n","----" );
      printf("%s ","Group size: " );
      printf("%d\n",p->groupsize);
      printf("%s\n","----" );
    }
    if(p != NULL)
    debugMode(p);
    p = p->next;
  }
  return NULL;
}
void displayGroupSizeAhead(LIST * ls, char * name){
  NODE * p = retrieveByName(ls, name, 1);
}
void displayListInformation(LIST * ls){
  printList(ls);
}


void printList(LIST * l){
  int groupNum = 0;
  if(l->head == NULL)
  {
    printf("%s\n", "empty list" );
  }
  NODE* p = l->head;
  while (p != NULL) {
    printf("%s","Number: " );
    printf("%d\n", ++groupNum);
    printf("%s\n","--------------- ");
    printf("%s", "Group Name: " );
    printf("%s\n", p->name );
    printf("%s", "Group Size: " );
    printf("%d\n", p->groupsize );
    printf("%s", "Current Status Size: " );
    printf("%s\n", p->status );
    printf("%s\n","---------------" );
    printf("\n");
    debugMode(p);
    p = p->next;
  }
}

LIST * createList(){
  LIST * list = (LIST*)malloc(sizeof(LIST));
  list->head = NULL;
  list->back = NULL;
  list->length = 0;
  return list;
}

NODE * createNode(){
  NODE * node = (NODE*)malloc(sizeof(NODE));
  node->name = NULL;
  node->groupsize = 0;
  node->status = NULL;
  node->next = NULL;
}

void fillInfo(NODE * node, char * name, int groupsize, char* status){
   node->name = name;
   node->groupsize = groupsize;
   node->status = status;
}

void pushfront(LIST * ls, char * name, int groupsize, char* status){
  NODE * node = createNode();
  fillInfo(node, name, groupsize, status);

  if(ls->head == NULL){ls->head = node; ls->back = ls->head; debugMode(ls->head);}
  else{
    NODE * temp = ls->head;
    ls->head = node;
    node->next = temp;
  }
}

void pushback(LIST * ls, char * name, int groupsize, char* status){
  NODE * node = createNode();
  fillInfo(node, name, groupsize, status);
  if(ls->head==NULL){pushfront(ls, name, groupsize, status);}
  else{
    NODE * p = ls->head;
    while(p->next != NULL){
      p = p->next;
      debugMode(p);
    }
    p->next = node;
    ls->back = p->next;
  }
}

void popfront(LIST * ls){
  if(ls->head == NULL)
    return;
  NODE* temp = ls->head;
  ls->head = ls->head->next;
  free(temp);
}

void popback(LIST * ls){
  if(ls->head == NULL)
    return;
  if(ls->head->next == NULL){
    free(ls->head);
    ls->head = NULL;
    return;
  }
  NODE * p = ls->head;
  while(p->next->next != NULL){
    debugMode(p);
    p = p->next;
  }
  free(p->next);
  p->next = NULL;
  ls->back = p;
}

int updateStatus(LIST * ls, char * name, char * status){

  NODE * node = retrieveByName(ls, name, 0);
  if(node == NULL){
    printf("%s\n","nothing done" );
    return -1;
  }
  if(strcmp(node->status, "waiting") == 0)
  return 0;
  if(node == NULL){
    return 0;
  }
  else{
    node->status = status;

    return 1;
  }
}



int nameExists(LIST * l, char * name){
  NODE * p = l->head;
  debugMode(p);
  while(p != NULL)
  {
    if(strcmp(name , p->name) == 0)
      return 1;
      debugMode(p);
      p = p->next;
  }
  return 0;
}

NODE * retrieveByGroupSize(LIST * l, int groupsize){
  NODE * p = l->head;
  debugMode(p);
  while(p != NULL);
  {
    if(groupsize == p->groupsize)
      return p;
    else{
      debugMode(p);
      p = p->next;
    }
  }
  return NULL;
}

int groupExists(LIST * l, int groupsize){
  NODE * p = l->head;
  debugMode(p);
  while(p != NULL);
  {
    if(groupsize == p->groupsize)
      return 1;
    else{
      p = p->next;
      debugMode(p);
    }
  }
  return 0;
}

void debugMode(NODE* p){
  if(debug == 1){
    if(p == NULL){
      printf("%s\n", "empty");
    }
    else{
      printf("\n");
  printf("%s\n","TRAVERSED NODE" );
  printf("%s\n","xxxxxxxxxxxxx ");
  printf("%s", "Group Name: " );
  printf("%s\n", p->name );
  printf("%s", "Group Size: " );
  printf("%d\n", p->groupsize );
  printf("%s", "Current Status Size: " );
  printf("%s\n", p->status );
  printf("%s\n","xxxxxxxxxxxxx" );
  printf("\n");
}
}
}
