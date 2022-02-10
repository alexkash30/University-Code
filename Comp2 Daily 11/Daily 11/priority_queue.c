/***********************************************************
Computing II -- COMP.1020 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom,
providing an enriching learning experience for students, and as training as a practicing
computing professional upon graduation. This practice is manifested in the University's
Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and
adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be
dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help
is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner
consistent with this document, the course academic policy on the course website on Blackboard,
and the UMass Lowell academic code.
Author: Alex Kashian
Date: 4/9
Effort: 5 hours 
Purpose: Use and test our understanding of priority queue
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct node {
	int data;
	int priority;
};
typedef struct node Node;

struct queue {
	int size;
	int capacity;
	Node* data;
};
typedef struct queue Queue;

PRIORITY_QUEUE priority_queue_init_default(void) {

	Queue* pQueue = (Queue*)malloc(sizeof(Queue));

	if (pQueue != NULL) {
		pQueue->size = 0;
		pQueue->capacity = 10;
		pQueue->data = (Node*)malloc(sizeof(Node) * pQueue->capacity);
		if (pQueue->data == NULL) {
			free(pQueue);
			pQueue = NULL;
		}

	}
	return (PRIORITY_QUEUE)pQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) {

	Queue* pQueue = (Queue*)hQueue;

	if (pQueue->size >= pQueue->capacity) {

		Node* temp = (Node*)malloc(sizeof(Node) * 2 * pQueue->capacity);

		if (temp == NULL) {
			return FAILURE;
		}
		for (int i = 0; i < pQueue->size; i++) {
			temp[i] = pQueue->data[i];
		}
		pQueue->capacity = 2 * pQueue->capacity;
		free(pQueue->data);
		pQueue->data = temp;
	}

	int i = pQueue->size;

	(pQueue->data[i]).priority = priority_level;
	(pQueue->data[i]).data = data_item;

	int parent_index = (i - 1) / 2;

	while (i >= 1 && ((pQueue->data[i]).priority > (pQueue->data[parent_index]).priority)) {

		Node temp = pQueue->data[parent_index];

		pQueue->data[parent_index] = pQueue->data[i];
		pQueue->data[i] = temp;
		i = parent_index;
		parent_index = (i - 1) / 2;
	}

	pQueue->size++;

	return SUCCESS;
}

Status priority_queue_remove(PRIORITY_QUEUE hQueue) {

	Queue* pQueue = (Queue*)hQueue;
	Node* temp = (Node*)malloc(sizeof(Node));

	if (priority_queue_is_empty(pQueue)) {
		return FAILURE;
	}

	*temp = pQueue->data[0];
	pQueue->data[0] = pQueue->data[pQueue->size - 1];
	pQueue->data[pQueue->size - 1] = *temp;
	pQueue->size--;

	int i = 0;
	int leftChild = (2 * i) + 1;
	int rightChild = (2 * i) + 2;

	while (leftChild < pQueue->size) {
		if (rightChild < pQueue->size && pQueue->data[rightChild].priority > pQueue->data[leftChild].priority) {
			if (pQueue->data[rightChild].priority > pQueue->data[i].priority) {

				Node* hold = (Node*)malloc(sizeof(Node));

				*hold = pQueue->data[i];
				pQueue->data[i] = pQueue->data[rightChild];
				pQueue->data[rightChild] = *hold;
				i = rightChild;
				leftChild = (2 * i) + 1;
				rightChild = (2 * i) + 2;
				free(hold);
			}
			else {
				break;
			}
		}
		else {
			if (pQueue->data[leftChild].priority > pQueue->data[i].priority) {

				Node* temp_hold = (Node*)malloc(sizeof(Node));

				*temp_hold = pQueue->data[i];
				pQueue->data[i] = pQueue->data[leftChild];
				pQueue->data[leftChild] = *temp_hold;
				i = leftChild;
				leftChild = (2 * i) + 1;
				rightChild = (2 * i) + 2;
				free(temp_hold);
			}
			else {
				break;
			}
		}
	}
	free(temp);
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus) {

	Queue* pQueue = (Queue*)hQueue;

	if (priority_queue_is_empty(pQueue)) {
		if (pStatus != NULL) {
			*pStatus = FAILURE;
		}
		return -1;
	}

	if (pStatus != NULL) {
		*pStatus = SUCCESS;
	}
	return (pQueue->data[0]).data;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) {

	Queue* pQueue = (Queue*)hQueue;

	if (pQueue->size == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue) {

	Queue* pQueue = (Queue*)*phQueue;

	free(pQueue->data);
	free(*phQueue);
	*phQueue = NULL;

	return;
}