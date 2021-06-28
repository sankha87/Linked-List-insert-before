//Add a node before a given node:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}

/* Given a node following_node, insert a new node before the given following_node */
void insertBefore(struct Node *head_ref, int following, int new_data)
{
	struct Node *ptr = head_ref;
	while (ptr->next->data != following)
		ptr = ptr->next;
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node *head = NULL;
	head = push(head, 9);
	head = push(head, 7);
	// while(1)  - for checking Stack Overflow condition
	head = push(head, 2);
	head = push(head, 1);
	printf("\n Created Linked list is : \n");
	printList(head);
	// while(1)  - for checking Stack Overflow condition
	insertBefore(head, 9, 8);
	printf("\n Created Linked list after insertion is : \n");
	printList(head);

	_getch();
}