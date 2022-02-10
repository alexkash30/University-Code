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
Date: 3/31
Effort: 10 hrs 
Purpose: use our understanding of queues and calculate the number of trips across the river the ferry needs to take
***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ferry.h"

int main(int argc, const char* argv[]) {

	bool start_left = true;
	int numTests;
	scanf("%d", &numTests);
	int full[1000];
	int x = 0;

	for (int j = 0; j < numTests; j++) {

		start_left = true;
		int cars = 0;
		int* pcars = &cars;
		int LengthOfFerry = lengthOfFerry(pcars);
		QUEUE lBank = queue_init_default();
		QUEUE rBank = queue_init_default();
		int left_size = 0;
		int right_size = 0;
		int timesCrossed = 0;
		int spaceLeft = LengthOfFerry * 100;
		int spaceRight = LengthOfFerry * 100;
		int current = 0;

		
		for (int i = 0; i < cars; i++) {
			int carLength;
			char docks[10];
			scanf("%d %s", &carLength, docks);

			if (docks[0] == 'l') {
				enqueue((QUEUE)lBank, carLength);
				left_size++;
			}
			else if (docks[0] == 'r') {
				enqueue((QUEUE)rBank, carLength);

				right_size++;
			}
			else {
				printf("Error %d location(entered wrong input).\n", i + 1);
				exit(0);
			}
		}
		

		while (is_empty((QUEUE)lBank) == false || is_empty((QUEUE)rBank) == false) {
			if (start_left) {
				current = 0;
				while (is_empty(lBank) == false && next_queue(lBank) + current <= spaceLeft) {
					current += next_queue(lBank);
					dequeue((QUEUE)lBank);
				}
				start_left = false;
			}
			else {
				current = 0;

				while (is_empty(rBank) == false && next_queue(rBank) + current <= spaceRight) {
					
					current += next_queue(rBank);
					dequeue((QUEUE)rBank);
				}
				start_left = true;
			}
			timesCrossed++;
		}
		full[x] = timesCrossed;
		x++;
		queue_destroy(&lBank);
		queue_destroy(&rBank);
	}

	for (int c = 0; c < numTests; c++) {
		printf("%d\n", full[c]);
	}


	return 0;
}

int lengthOfFerry(int* cars) {
	int lengthOfFerry;
	scanf("%d %d", &lengthOfFerry, cars);
	return lengthOfFerry;
}


Queue* queue_init_default(void) {

	Queue* pNode = (Queue*)malloc(sizeof(Queue));

	if (pNode != NULL) {
		pNode->head = NULL;
		pNode->tail = NULL;
		return pNode;
	}

	return NULL;
}

Node* node_default(int length) {

	Node* pNode = (Node*)malloc(sizeof(Node));

	if (pNode != NULL) {
		pNode->data = length;
		pNode->next = NULL;
		return pNode;
	}

	return NULL;
}

bool is_empty(QUEUE hQueue) {

	Queue* pQueue = (Queue*)hQueue;

	if (pQueue->head == NULL && pQueue->tail == NULL)
		return true;
	else
		return false;
}

Status enqueue(QUEUE hQueue, int Length) {

	Node* pNode = node_default(Length);
	Queue* pQueue = (Queue*)hQueue;

	if (is_empty(hQueue)) {
		pQueue->head = pNode;
		pQueue->tail = pNode;
		return SUCCESS;
	}

	pQueue->tail->next = pNode;
	pQueue->tail = pNode;
	pQueue->tail->next = NULL;

	return SUCCESS;

}

Status dequeue(QUEUE hQueue) {

	if (is_empty(hQueue) == false) {

		Queue* pQueue = (Queue*)hQueue;
		Node* pNode = pQueue->head;
		pQueue->head = pQueue->head->next;

		if (pQueue->head == NULL) {

			pQueue->tail = NULL;
		}

		free(pNode);

		return SUCCESS;
	}

	return FAILURE;
}

int next_queue(QUEUE hQueue) {

	Queue* pQueue = (Queue*)hQueue;

	if (is_empty(hQueue) == true)
		return -1;
	else
		return pQueue->head->data;
}

void queue_destroy(QUEUE* phQueue) {
	Queue* pQueue = (Queue*)*phQueue;
	Node* pNode;

	while (!is_empty(pQueue)) {
		pNode = pQueue->head->next;
		free(pQueue->head);
		pQueue->head = pNode;
	}
	free(pQueue);
	*phQueue = NULL;
}
