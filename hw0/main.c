#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node* next;
} Node;

void append(Node** head, char c) {
	Node* newptr = (Node*)malloc(sizeof(Node));
	newptr->data = c;
	newptr->next = NULL;

	if (*head == NULL) {
		*head = newptr;
	}
	else {
		Node* temp = *head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newptr;
	}
}

void printList(Node* head) {
	while (head) {
		printf("%c", head->data);
		head = head->next;
	}
}

void freeList(Node* head) {
	while (head) {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	const char* filename = "hw0.c";
	FILE* file = fopen(filename, "r");
	Node* head = NULL;
	char c;

	while ((c = fgetc(file)) != EOF) {
		append(&head, c);
	}

	fclose(file);
	printList(head);
	freeList(head);
	return 0;
}