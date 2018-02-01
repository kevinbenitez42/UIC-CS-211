
#include <stdio.h>
#include <stdlib.h>

typedef struct stack STACK;

struct stack{
	int * arr;
	int size;
	int count;
};



STACK * init();
int isEmpty(STACK * s);
int pop(STACK * s);
int top(STACK * s);
void push(STACK * s, int x);
void Display(STACK * s);
void restore(STACK * s);
void resize(STACK * s);
void printsize(STACK * s);
void printcount(STACK * s);
STACK * init();

int main(int argc, char ** argv){
	STACK * s = init();
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,1);
	push(s,2);
	push(s,3);
	pop(s);
	pop(s);
	pop(s);
	restore(s);
	printsize(s);
	printcount(s);
	printf("%s\n","======" );
	Display(s);
}

STACK * init(){
	STACK * s = (STACK*)malloc(sizeof(STACK));
	s->arr = (int*)malloc(sizeof(int));
	s->size = 1;
	s->count = 0;
	return s;
}
void printsize(STACK * s){
	printf("%s\n","size" );
	printf("%d\n",s->size );
}
void printcount(STACK * s){
	printf("%s\n", "count" );
	printf("%d\n",s->count );
}
void resize(STACK * s){
	int * arrR ;
	arrR = (int*)malloc(sizeof(int) * s->size * 2);
	for(int i = 0; i < s->size; i++){
		arrR[i] = s->arr[i];
	}
 free(s->arr);
 s->arr = arrR;
 s->size *= 2;
}

int isEmpty(STACK * s)
{
	if(s->count == 0)
	return 1;
	else
	return 0;
}

void push(STACK * s, int x){
	s->count++;
	if(s->count == s->size){
         resize(s);
	}
	s->arr[s->count -1 ] = x;
	
}

int pop(STACK * s){
	s->count--;
}

int top(STACK * s){
	return s->arr[s->count - 1];
}

void Display(STACK * s){
	if(isEmpty(s)){
		printf("%s\n","stacks empty" );
	}
	for(int i = 0; i < s->count ; i++){
		printf("%d\n", s->arr[i]);
	}
}
void restore(STACK * s){
	while(!isEmpty(s)){
		pop(s);
	}
}