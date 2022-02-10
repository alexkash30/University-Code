#ifndef FERRY_H 
#define FERRY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	struct node* next;
	int data;
};
typedef struct node Node;

struct queue {
	Node* head;
	Node* tail;
};
typedef struct queue Queue;
typedef void* QUEUE;

enum status { FAILURE, SUCCESS };
typedef enum status Status;


Queue* queue_init_default(void);
Node* node_default(int length);
Status enqueue(QUEUE hQueue, int Length);
Status dequeue(QUEUE hQueue);
bool is_empty(QUEUE hQueue);
int lengthOfFerry(int* cars);
int next_queue(QUEUE hQueue);
void queue_destroy(QUEUE* phQueue);

#endif