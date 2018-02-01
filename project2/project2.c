#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STRINGMAX 300
int debugMode;

typedef struct stack{
  char * arr;
  int size;
  int inUse;
}STACK;

STACK* createStack();
int empty(STACK* s);
void push(STACK* s, int elem);
char pop(STACK* s);
char top(STACK* s);
void reset(STACK* s);
void checkBalance(STACK* s, char* string);
void printStack(STACK *s);


int main(int argc, char *argv[]){

if(argv[1] != NULL){
  char * command_line_string = argv[1];
  if(strcmp(argv[1], "-d") == 0){
    debugMode = 1;
  }
}
  STACK* stack = createStack();
  char string[STRINGMAX];
  int stringLength;
  int flag;
  int isBalanced;
  int isMissing;
  int index;
  char cindex;
  char expected;
  printf("%s%s\n","Hello, give me a set of symbols to check",
          "(press q or Q then enter to quit)" );
while(strcmp(string, "q\n") && strcmp(string, "Q\n")){

  for(int i = 0; i < STRINGMAX; i++)
  {
    string[i] = 0;
  }
  stringLength = -1;
  flag = 1;
  isBalanced = 1;
  isMissing = 0;
  reset(stack);

  fgets(string, STRINGMAX, stdin);

  for(int i = 0;(flag == 1);i++)
  {
    switch(string[i]){
      case '{':
      push(stack, string[i]);
      break;
      case '(':
      push(stack, string[i]);
      break;
      case '[':
      push(stack, string[i]);
      break;
      case '<':
      push(stack, string[i]);
      break;
      case '}':
      if(top(stack) == '{'){pop(stack);}
      else if(!empty(stack)){flag = 0; isBalanced = 0; index = stringLength;
      cindex = top(stack);}
      else{flag = 0; isBalanced = 0; index = stringLength;
      cindex = '}';}
      break;
      case ')':
      if(top(stack) == '('){pop(stack);}
      else if(!empty(stack)){flag = 0; isBalanced = 0; index = stringLength;
      cindex = top(stack);}
      else{flag = 0; isBalanced = 0; index = stringLength;
      cindex = ')';}
      break;
      case ']':
      if(top(stack) == '['){pop(stack);}
      else if(!empty(stack)){flag = 0; isBalanced = 0; index = stringLength;
      cindex = top(stack);}
      else{flag = 0; isBalanced = 0; index = stringLength;
      cindex = ']';}
      break;
      case '>':
      if(top(stack) == '<'){pop(stack);}
      else if(!empty(stack)){flag = 0; isBalanced = 0; index = stringLength;
      cindex = top(stack);}
      else{flag = 0; isBalanced = 0; index = stringLength;
      cindex = '>';}
      break;
      case '\n':
      if(empty(stack))
      {
      flag = 0;
      }
      else{
        flag = 0;
        isBalanced = 0;
        isMissing = 1;
      }
      break;
    }
    stringLength++;
  }

  switch(cindex){
    case '{':
    expected = '}';
    break;
    case '[':
    expected = ']';
    break;
    case '(':
    expected = ')';
    break;
    case '<':
    expected = '>';
    break;
    case '}':
    expected = '{';
    break;
    case ']':
    expected = '[';
    break;
    case ')':
    expected = '(';
    break;
    case '>':
    expected = '<';
    break;
  }

  if((flag == 0) && (isBalanced == 0) && (isMissing == 0) && (debugMode == 0)){

    for(int i = 0; i < index + 1 ; i++)
    {
      printf("%s"," ");
    }
    printf("%s","^" );
    printf("%s", " expecting ");
    printf("%c",expected);
    printf("\n");
  }
  else if((flag == 0) && (isBalanced == 0) && (isMissing == 1) && (debugMode == 0)){
    for(int i = 0; i < stringLength ; i++)
    {
      printf("%s"," ");
    }
    printf("%s","   ^" );
    printf("%s\n"," is missing" );
  }
  else if(debugMode == 0){
    printf("%s\n","Expression is balanced" );
  }
}
}

void printStack(STACK* s){
for(int i = 0; i < (s->inUse-1); i++)
printf("%c",s->arr[i] );
printf("\n");
}


STACK* createStack(){
  STACK* s = (STACK*)malloc(sizeof(STACK));
  s->arr = (char*)malloc(sizeof(char) * 2);
  s->size = 2;
  s->inUse = 0;
  return s;
}

int empty(STACK* s){
if(s->inUse == 0){return 1;}
else{return 0;}
}

void push(STACK* s, int elem){
  char* temp;
  if(debugMode == 1)
  printf("%s%c%s\n","character ", elem, " is being pushed");
  if(s->inUse == s->size)
  {

    s->size = s->size + 2;
    char* arr = (char*)malloc(sizeof(char) * s->size);
    for(int i = 0; i < (s->size)-2; i++)
    {
    arr[i] = s->arr[i];
    }
    temp = s->arr;
    s->arr = arr;
    free(temp);
    if(debugMode == 1)
    {
    printf("%s%d\n","old size is: ", s->size - 2);
    printf("%s%d\n","new size is: ", s->size);
    printf("%d%s\n",s->inUse + 1, " values copied into new array");
    }
  }
  s->inUse++;
  s->arr[s->inUse - 1] = elem;


}

char pop(STACK* s){
  if((debugMode == 1) && (s->inUse != 0))
  printf("%s%c%s\n","the character ", top(s), " is popped");
  else if(debugMode == 1)
  printf("%s\n","the stack is empty");
  if(s->inUse == 0){return '\0';}
  char temp = 0;
  temp = s->arr[s->inUse - 1];
  s->inUse--;
  return temp;
}

char top(STACK* s){
  if(s->inUse == 0){return 'F';}
  else{return s->arr[s->inUse-1];}
}
void reset(STACK* s){
   char* temp;
   temp = s->arr;
   free(temp);
   free(s);
   s = createStack();
}
