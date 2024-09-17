#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node *next;
} node;

void display(node *head) {
	node *ptr;
	ptr = head;
	if(ptr == NULL) {
		printf("Linked list empty\n");
		return;
	}
	while(ptr != NULL) {
		printf("%d ", ptr ->data);
		ptr = ptr -> next;
	}
	printf("\n");
}

void insfront( node **head, int data) {
	node *ptr;
	ptr = malloc(sizeof(node));
	ptr -> data = data;
	ptr -> next = NULL;
	if(*head == NULL) {
		*head = ptr;
		return;
	}
	ptr -> next = *head;
	*head = ptr;

}

void insrear( node **head, int data) {
	node *ptr, *temp;
	ptr = malloc(sizeof(node));
	ptr -> data = data;
	ptr -> next = NULL;
	if (*head == NULL) {
		*head = ptr;
		return;
	}
	temp = *head;
	while(temp->next != NULL) {
		temp = temp -> next;
	}
	temp -> next = ptr;
}

void delfront(node **head) {
	node *temp = NULL;
	if(*head == NULL) {
		printf("Empty list\n");
		return;
	}
	temp = *head;
	*head = temp -> next;
	free(temp);
}

void delrear(node **head) {
	node *temp = NULL;
	node *ptr = NULL;
	if(*head == NULL){
		printf("List Empty\n");
		return;
	}
	ptr = *head;
	if(ptr -> next == NULL) {
		free(ptr);
		*head = NULL;
		return;
	}
	while(ptr -> next -> next != NULL) {
		ptr = ptr -> next;
	}
	temp = ptr -> next;
	ptr -> next = NULL;
	free(temp);
}

void reverse(node **head) {
	node *prev, *curr, *next;
	prev = NULL;
	curr = *head;
	next = NULL;
	if(*head == NULL) {
		printf("Empty list\n");
		return;
	}
	while(curr != NULL) {
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

int main(int argc, char **argv) {
	node *head1 = NULL;
	node *head2 = NULL;
	for(int  i = 1; i < 6; i++) {
		insfront(&head1, i);
	}
	display(head1);
	reverse(&head1);
	display(head1);
	printf("\nDeleting Linked List contents from the front\n");
	for(int  i = 1; i < 6; i++) {
		delfront(&head1);
		display(head1);
	}
	printf("End of Deletion from the front\n\n");
	for(int i = 10; i > 5; i--) {
		insrear(&head2, i);
	}
	display(head2);
	printf("\nDeleting Linked List contents from the rear\n");
	for(int  i = 1; i < 6; i++) {
		delrear(&head2);
		display(head2);
	}
	printf("End of Deletion from the rear\n\n");
	return 0;
}
