#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define l 100

typedef struct NODE
{
	char customer[l];
	char intake[l];
	struct NODE *prev;
	struct NODE *next;
}node;
node *head, *temp, *temp1;

void create()
{
	//char customer[l];
	//char intake[l];
	temp = (node*)malloc(sizeof(node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("Enter customer:\n");
	scanf("%s", temp->customer);
	printf("Enter intake:\n");
	scanf("%s", temp->intake);
}

void insert()
{
	if (head == NULL)
	{
		create();
		head = temp;
		temp1 = head;
	}
	else
	{
		create();
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void main()
{
	int choice;
	while (1)
	{
		printf("1. Insert\n2. Print\nUr choice");
		fflush(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			printf("List:\n");
			temp = head;
			while (temp != NULL){
				printf("%s\n%s\n", temp->customer, temp->intake);
				temp = temp->next;
			}
			break;
		default:
			exit(0);
			break;
		}
	}
}
