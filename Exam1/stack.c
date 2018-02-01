#include <stdio.h>
#include <stdlib.h>
#define SENTINAL -999

typedef struct stack STACK;
typedef struct node NODE;

struct node{
	int val;
	struct node * next;
};

struct stack{
	struct node * head;

};
typedef struct stack STACK;
typedef struct node NODE;
STACK * init();
int isEmpty(STACK * s);
int pop(STACK * s);
int top(STACK * s);
NODE * createNode(int x);
void push(STACK * s, int x);
void Display(STACK * s);
void restore(STACK * s);

STACK * init(){
	return (STACK*)malloc(sizeof(STACK));
}

int isEmpty(STACK * s){
	if( s->head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int pop(STACK * s){
 	if(isEmpty(s)){
 		return -1;
 	}
 	else{
 		NODE* temp = s->head;
 		s->head = s->head->next;
 		int returnval = temp->val;
 		free(temp);
 		return returnval;
 	}
}

int top(STACK * s){
	if(isEmpty(s)){
		return -1;
	}
	else{
		return s->head->val;
	}
}

NODE * createNode(int x){
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->val = x;
	temp->next = NULL;
	return temp;
}

void push(STACK * s, int x){
	if(isEmpty(s)){
		s->head = createNode(x);
	}
	else{
		NODE* oldHead = s->head;
		s->head = createNode(x);
		s->head->next = oldHead;
	}
}

void Display(STACK * s){
	NODE * p = s->head;
	if(isEmpty(s)){
		printf("%s\n", "this is an empty stack" );
	}
	while(p!=NULL){
		printf("%d\n",p->val );
		p = p->next;
	}
}

void restore(STACK * s){
	NODE * p = s->head;
	NODE * temp;
	while(p != NULL){
		temp = p->next;
		p = p->next;
		free(temp);
	}
	s->head = NULL;
}


int main(int argc, char ** argv){
	STACK * s = (STACK*)malloc(sizeof(STACK));
	int input;
	printf("%s\n","GIVE ME INPUT" );
	scanf("%d", &input);
	while(SENTINAL != input){
		push(s, input);
		printf("%d\n", top(s));
		pop(s);
		printf("%d\n", top(s));
		scanf("%d", &input);
	} 
	
	printf("%s\n", "=========" );
		Display(s);
		printf("%s\n", "=========" );
}


