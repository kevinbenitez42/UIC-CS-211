#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node * next;
}NODE;


typedef struct Queue{
	struct node * front;
	struct node * back;
}QUEUE;

QUEUE * init();
int isEmpty(QUEUE * q);
int front(QUEUE * q);
void enqueue(QUEUE * q, int x);
int dequeue(QUEUE * q);
void reset(QUEUE * q);
NODE * createNode(int x);
void display(QUEUE * q);
int main(int argc, char const *argv[])
{
	QUEUE * q = init();
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	printf("%d\n", front(q));
	reset(q);
	display(q);
	


}

QUEUE * init(){
	QUEUE * q = (QUEUE*)malloc(sizeof(QUEUE));
	q->front = NULL;
	q->back = NULL;
	return q;
}

int isEmpty(QUEUE * q){
	if(q->front == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int front(QUEUE * q){
	if(isEmpty(q)){
		return -1;
	}
	else
	{
		return q->front->val;
	}
}

NODE * createNode(int x){
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->val = x;
	node->next = NULL;
}

void enqueue(QUEUE * q, int x){
NODE* newNode = createNode(x);
	if(isEmpty(q)){
		q->front = newNode;
		q->back = q->front;
	}
	else{
		NODE * temp = q->front;
		q->front = newNode;
		newNode->next = temp;
	}
}

int dequeue(QUEUE * q){
	if(isEmpty(q)){
		return -1;
	}
	
	if(q->front->next == NULL){
		int ret = q->front->val;
		free(q->front);
		q->front = NULL;
		q->back = NULL;
		return ret;
	}

	NODE * temp = q->front;
	int ret = q->front->val;
	q->front = q->front->next;
	free(temp);
	return ret;

}

void reset(QUEUE * q){
	NODE * p = q->front;
	while(p != NULL){
		NODE * temp = p;
		p = p->next;
		free(temp);
	}

	q->front = NULL;
	q->back = NULL;
}

void display(QUEUE * q){
	NODE * p = q->front;
	if(isEmpty(q))
	{
		printf("%s\n","empty List" );
		return;
	}
	printf("%s\n","========" );
	while(p != NULL){
		printf("%d\n", p->val );
		p = p->next;
	}
	printf("%s\n","=========" );
}