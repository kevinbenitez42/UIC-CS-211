#include <stdio.h>
#include <stdlib.h>

/*A node made to be used with a linked list*/
typedef struct node {
  int val;
  struct node* next;
}NODE;

/*A stack that uses a linked list for its implementation*/
typedef struct stack {
  NODE* top;
  int size;
}STACK;

/*Prototypes for our stack linked list implementation*/
STACK* createStack();
NODE* createNode(int elem);
int empty(STACK* s);
void push(STACK* s, int elem);
int pop(STACK* s);
int top(STACK* s);
void reset(STACK* s);
void printStack(STACK* s);

/*prints stack*/
void printStack(STACK* s){
  NODE* node = s->top;
  while(node != NULL)
  {
    printf("%d ",node->val);
    node = node->next;
  }
}
/*creates a node*/
NODE* createNode(int elem){
NODE* node = (NODE*)malloc(sizeof(NODE));
node->val = elem;
node->next = NULL;
}

/*creates a stack*/
STACK* createStack(){
  STACK* s = (STACK*)malloc(sizeof(STACK));
  s->top = NULL;
  s->size = 0;
}

/*returns 1 if the stack is empty, returns 0 if it is not*/
int empty(STACK* s){
  if(s->top == NULL){return 1;} else{return 0;}
}

/*pushes node(element) onto the stack*/
void push(STACK *s, int elem){
  NODE* newNode = createNode(elem);
  newNode->next = s->top;
  s->top = newNode;
  s->size++;
}

/*pops top (node) element from the stack if not empty*/
int pop(STACK* s){
  if(!empty(s)){
  NODE* temp = s->top;
  s->top = s->top->next;
  int return_val = temp->val;
  free(temp);
  s->size--;
  return return_val;
  }
  else{
    printf("%s\n","stack is empty");
  }
}
/*retrieves the top element in a stack that is not empty*/
int top(STACK* s){
  if(!empty(s)){
    return s->top->val;
  }
  else{
    printf("%s\n","stack is empty" );
  }
}

/*resets stack*/
void reset(STACK* s){
  while(s->top != NULL)
  pop(s);
}
