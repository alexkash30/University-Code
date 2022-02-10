#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node{
	int data;
	Node* next;
};

void revese_list(Node* hNode);


int main(int argc, char* argv[]){
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++){
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL){
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	revese_list(head);


	//print the reversed list.
	temp = head;
	while (temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

void revese_list(Node* hNode) {
	Node* head = hNode;
	Node* next = NULL;
	Node* prev = NULL;

	while(head != NULL){
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	*hNode = *prev;
}
