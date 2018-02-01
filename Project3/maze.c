#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int debugMode = 0;

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

/*Prototypes for our linked list stack implementation*/
STACK* createStack();
NODE* createNode(int elem);
int empty(STACK* s);
void push(STACK* s, int elem);
int pop(STACK* s);
int top(STACK* s);
void reset(STACK* s);
void printStack(STACK* s);
void printCoordinates(char** arr,STACK* x, STACK* y, char c);
typedef struct mazeStruct
{
 char **arr; /*dynamically allocates memory for an array many elements*/
 int xsize, ysize;
 int xstart, ystart;
 int xend, yend;
} maze;

int main (int argc, char **argv)
{

/*checks if there are multiple text files or  if too little arguments where given
if either case occurs, the program aborts*/
  if(argc > 3 || argc <= 1){
    printf("%s\n","sorry too many/few arguments. only one text file at a time" );
    exit(-1);
  }
/*turns debug mode on if either of the arguments is the d flag*/
  for(int i = 1; i < argc; i++){
    if(!strcmp(argv[i], "-d")){
      printf("%s\n","debug mode is on" );
      debugMode = 1;
    }
  }
  maze m1;
  int xCoor, yCoor;
  int xpos, ypos;
  int i,j;
  int valInFlag;
  FILE *src;


  /* Try to open the input file. */
  if ( ( src = fopen( argv[1], "r" )) == NULL )
  {
    printf ( "Can't open input file: %s", argv[1] );
    exit(-1);
  }

  /* read in the size, starting and ending positions in the maze */
  /*I created a monster... WHAT HAVE I DONE!!!!!!!*/
int isInvalid;
isInvalid =  fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
if(isInvalid == -1){printf("%s\n","sorry, EOF reached, program aborted" ); exit(-1);}
  while(!(m1.xsize > 0 && m1.ysize > 0)){
    printf("%d, %d",m1.xsize, m1.ysize);
    printf("%s\n","     => Invalid: Maze sizes must be greater than 0" );
    isInvalid = fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
    if(isInvalid == -1){printf("%s\n","sorry, EOF reached, program aborted" ); exit(-1);}
  }
   printf("%d, %d",m1.xsize, m1.ysize);
   printf("%s %d %s %d\n","    => Maze becomes",m1.xsize, " x ", m1.ysize );
/*this is where the maze changes in size*/

m1.arr = (char**)malloc((m1.xsize + 2) * sizeof(char*));
for(int i = 0; i < m1.xsize + 2; i++){
  m1.arr[i] = (char*)malloc(m1.ysize * sizeof(char));
}

   fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
   while(!(m1.xstart > 0 && m1.xstart <= m1.xsize
     && m1.ystart > 0 && m1.ystart <= m1.ysize))
     {
       printf ("%d, %d", m1.xstart, m1.ystart);

       if(!(m1.xstart > 0 && m1.xstart <= m1.xsize)){
         printf("%s %d %s %d %s %d\n","   => Invalid: row ", m1.xstart, " is outside of range", 1, "to", m1.xsize);
       }
       else if(!(m1.ystart > 0 && m1.ystart <= m1.ysize)){
         printf("%s %d %s %d %s %d\n","   => Invalid: column ", m1.ystart, " is outside of range", 1, "to", m1.ysize);
       }
      isInvalid = fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
      if(isInvalid == -1){printf("%s\n","sorry, EOF reached, program aborted" ); exit(-1);}
    }

    if ((m1.xstart > 0 && m1.xstart <= m1.xsize
      && m1.ystart > 0 && m1.ystart <= m1.ysize))  {
     printf ("%d, %d", m1.xstart, m1.ystart);
     printf("%s %d %s %d\n","    => starting position is at ",m1.xstart, " , ", m1.ystart );
    }
      isInvalid = fscanf (src, "%d %d", &m1.xend, &m1.yend);
      if(isInvalid == -1){printf("%s\n","sorry, EOF reached, program aborted" ); exit(-1);}

      if((m1.arr[m1.xstart][m1.ystart] == '*'))
      {
        printf("%s\n", "       =>  invalid start position");
      }

     while(!(m1.xend > 0 && m1.xend <= m1.xsize
       && m1.yend > 0 && m1.yend <= m1.ysize))
       {
         printf ("%d, %d", m1.xend, m1.yend);
         if(!(m1.xend > 0 && m1.xend<= m1.xsize)){
           printf("%s %d %s %d %s %d\n","   => Invalid: row ", m1.xend, " is outside of range", 1, "to", m1.xsize);
         }
         if(!(m1.yend > 0 && m1.yend <= m1.ysize)){
           printf("%s %d %s %d %s %d\n","         => Invalid: column ", m1.yend, " is outside of range", 1, "to", m1.ysize);
         }
          isInvalid = fscanf (src, "%d %d", &m1.xend, &m1.yend);
          if(isInvalid == -1){printf("%s\n","sorry, EOF reached, program aborted" ); exit(-1);}
       }

       if ((m1.xend > 0 && m1.xend <= m1.xsize
         && m1.yend > 0 && m1.yend <= m1.yend)) {
        printf ("%d, %d", m1.xend, m1.yend);
        printf("%s %d %s %d\n","    => Ending position is at ",m1.xend, " , ", m1.yend );
       }


  /*
  for (i = 0; i < m1.xsize+1; i++)
     for (j = 0; j < m1.ysize+1; j++)
     printf("%c\n", marked[i][j]);
     */
  /* initialize the maze to empty */
  for (i = 0; i < m1.xsize+2; i++)
     for (j = 0; j < m1.ysize+2; j++)
       m1.arr[i][j] = '.';



  /* mark the borders of the maze with *'s */
  for (i=0; i < m1.xsize+2; i++)
    {
     m1.arr[i][0] = '*';
     m1.arr[i][m1.ysize+1] = '*';
    }
  for (i=0; i < m1.ysize+2; i++)
    {
     m1.arr[0][i] = '*';
     m1.arr[m1.xsize+1][i] = '*';
    }

  /* mark the starting and ending positions in the maze */
  m1.arr[m1.xstart][m1.ystart] = 's';
  m1.arr[m1.xend][m1.yend] = 'e';

  /* mark the blocked positions in the maze with *'s */
  while (fscanf (src, "%d %d", &xpos, &ypos) != EOF)
    {
      printf("%d, %d\n", xpos, ypos );
      if(xpos <= m1.xsize && ypos <= m1.ysize
        && xpos >= 1 && ypos >= 1 )
      {

     m1.arr[xpos][ypos] = '*';
     if(m1.arr[m1.xstart][m1.ystart] == '*')
     {
       m1.arr[xpos][ypos] = '.';
       printf("%s %d %s %d\n","blocked start at  ",xpos, " , ", ypos );
     }

   }
   }

  /*mark visited*/
  /*mark asterisks*/
  int marked[m1.xsize + 2][m1.ysize + 2];
  for (i = 0; i < m1.xsize+2; i++)
    {
     for (j = 0; j < m1.ysize+2; j++)
      {
        if(m1.arr[i][j] == '*'){
        marked[i][j] = 1;
      }
        else{
        marked[i][j] = 0;
      }
      }
    }
  STACK * xStack = (STACK*)malloc(sizeof(STACK));
  STACK * yStack = (STACK*)malloc(sizeof(STACK));
  STACK * xVisited = (STACK*)malloc(sizeof(STACK));
  STACK * yVisited = (STACK*)malloc(sizeof(STACK));
  push(xStack, m1.xstart);
  push(yStack, m1.ystart);
  marked[top(xStack)][top(xStack)] = 1;
  int endFound = 0;
  while(!empty(xStack) && !empty(yStack) && !endFound ){
    if((top(xStack) == m1.xend) && (top(yStack) == m1.yend)){
       endFound = 1;
    }
    if(marked[top(xStack)][top(yStack) + 1] != 1 ){
       marked[top(xStack)][top(yStack) + 1] = 1;
       if(debugMode)
       {printf("%s","x coordinate being pushed is " ); printf("%d, ",top(xStack) );}
       push(xStack, top(xStack));
       if(debugMode)
         {printf("%s","y coordinate being pushed is " ); printf("%d\n",top(yStack) );}
       push(yStack, top(yStack) + 1);
    }
    else if (marked[top(xStack)+1][top(yStack)] != 1 ){
       marked[top(xStack)+1][top(yStack)] = 1;
       if(debugMode)
       {printf("%s","x coordinate being pushed is " ); printf("%d, ",top(xStack) );}
       push(xStack, top(xStack)+1);
       if(debugMode)
         {printf("%s","y coordinate being pushed is " ); printf("%d\n",top(yStack) );}
       push(yStack, top(yStack));
    }
    else if (marked[top(xStack)][top(yStack)-1] != 1 ){
       marked[top(xStack)][top(yStack)-1] = 1;
       if(debugMode)
       {printf("%s","x coordinate being pushed is " ); printf("%d, ",top(xStack) );}
       push(xStack, top(xStack));
       if(debugMode)
         {printf("%s ","y coordinate being pushed is " ); printf("%d\n",top(yStack) );}
       push(yStack, top(yStack)-1);
    }
    else if (marked[top(xStack)-1][top(yStack)] != 1 ){
       marked[top(xStack)-1][top(yStack)] = 1;
       if(debugMode)
       {printf("%s","x coordinate being pushed is " ); printf("%d, ",top(xStack) );}
       push(xStack, top(xStack)-1);
       if(debugMode)
         {printf("%s","y coordinate being pushed is " ); printf("%d\n",top(yStack) );}
       push(yStack, top(yStack));
    }
    else{
      if(debugMode)
      {printf("%s","x coordinate being popped is " ); printf("%d, ",top(xStack) );}
      push(xVisited,(pop(xStack)));
      if(debugMode)
        {printf("%s ","y coordinate being popped is " ); printf("%d\n", top(yStack) );}
      push(yVisited, (pop(yStack)));
    }

  }
  printf("\n");
    printf("%s\n","original maze: " );
    printf("%s %d%s %d\n","size: ", m1.xsize, ",", m1.ysize);
    printf("%s %d%s %d\n","start: ", m1.xstart, ",", m1.ystart);
    printf("%s %d%s %d\n","end: ", m1.xend, ",", m1.yend);
    printf("\n");
  /* print out the initial maze */
  for (i = 0; i < m1.xsize+2; i++)
    {
     for (j = 0; j < m1.ysize+2; j++)
       printf ("%c", m1.arr[i][j]);
     printf("\n");
    }
/*pops the stack andprints out coordinates*/
if(empty(xStack), empty(yStack)){
  printf("%s\n","very empty, no solucion" );
}
else{
  printf("\n");
  printf("%s\n","coordinates for path (p): " );
  printCoordinates(m1.arr,xStack,yStack, 'p');
  printf("%s\n","coordinates for visted path (@): " );
  printCoordinates(m1.arr,xVisited,yVisited, '@');
}
printf("\n");
printf("%s\n","solved maze: " );
  printf("%s %d%s %d\n","size: ", m1.xsize, ",", m1.ysize);
  printf("%s %d%s %d\n","start: ", m1.xstart, ",", m1.ystart);
  printf("%s %d%s %d\n","end: ", m1.xend, ",", m1.yend);
  printf("\n");
  /* print out the initial maze */
  for (i = 0; i < m1.xsize+2; i++)
    {
     for (j = 0; j < m1.ysize+2; j++)
       printf ("%c", m1.arr[i][j]);
     printf("\n");
    }
/*frees my array*/
    for(int i = 0; i < m1.xsize + 2; i++){
      free(m1.arr[i]);
    }
        free(m1.arr);
        m1.arr = NULL;
}
/*print coordinates*/
void printCoordinates(char **arr, STACK* x, STACK* y, char c){
  int printx;
  int printy;
  if(!empty(x) && !empty(y)){
  printx = pop(x);
  printy = pop(y);
  arr[printx][printy] = c;
  printCoordinates(arr, x, y, c);
  printf("%d, %d\n",printx, printy );
}
return;

}
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
