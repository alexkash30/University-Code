#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


int main(int argc, const char* argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	PRIORITY_QUEUE Queue = priority_queue_init_default();
	Status pQueue;
	Boolean test;
	Status teststat, teststat2;
	Status first, second, third;

	if (Queue != NULL) {
		printf("Queue != NULL!\n");
	}
	else {
		printf("Queue = NULL!\n");
	}

	first = priority_queue_insert(Queue, 45, 15);

	if (first == SUCCESS) {
		printf("TEST 1 insert SUCCESS!\n");
	}
	else {
		printf("TEST 1 insert FAILED!\n");
	}

	second = priority_queue_insert(Queue, 55, 20);

	if (second == SUCCESS) {
		printf("TEST 2 insert SUCCESS!\n");
	}
	else {
		printf("TEST 2 insert Failed!\n");
	}

	third = priority_queue_insert(Queue, 35, 25);

	if (third == SUCCESS) {
		printf("TEST 3 insert SUCCESS!\n");
	}
	else {
		printf("TEST 3 insert FAILED!\n");
	}

	teststat = SUCCESS;
	Status* pStatus = &teststat;
	int f1 = priority_queue_front(Queue, pStatus);

	printf("Front Queue: %d\n", f1);

	pQueue = priority_queue_remove(Queue);

	if (pQueue == SUCCESS) {
		printf("Queue remove SUCCESS!\n");
	}
	else {
		printf("Queue remove FAILED!\n");
	}

	teststat2 = FAILURE;
	Status* pStatus1 = &teststat2;
	int f2 = priority_queue_front(Queue, pStatus1);

	printf("Front Queue: %d\n", f2);

	test = priority_queue_is_empty(Queue);

	if (test == FALSE) {
		printf("Queue empty SUCCESS!\n");
	}
	else {
		printf("Queue empty FAILED!\n");
	}

	priority_queue_destroy(&Queue);

	if (Queue == NULL) {
		printf("Queue destroy SUCCESS!\n");
	}
	else {
		printf("Queue destroy FAILED!\n");
	}


	return 0;
}