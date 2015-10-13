#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define l 100


typedef struct NODE
{
	char customer[l];
	char customerNum[l];
	char gender[l];
	char orderDes[l];
	char customerAdd[l];
	struct NODE *prev;
	struct NODE *next;
}node;
node *head, *temp, *temp1, *temp2;

void create()
{
	temp = (node*)malloc(sizeof(node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("Enter customer:\n");
	fflush(stdin);
	fgets(&temp->customer, l, stdin);
	printf("Enter customer number:\n");
	fflush(stdin);
	fgets(&temp->customerNum, l, stdin);
	printf("Enter gender:\n");
	fflush(stdin);
	fgets(&temp->gender, l, stdin);
	printf("Enter order description:\n");
	fflush(stdin);
	fgets(&temp->orderDes, l, stdin);
	printf("Enter customer address:\n");
	fflush(stdin);
	fgets(&temp->customerAdd, l, stdin);
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

void insert2()
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
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
}

void display()
{
	temp2 = head;

	if (temp2 == NULL)
	{
		printf("List empty to display \n");
		return;
	}
	printf("\nLinked list elements from begining : \n");

	while (temp2!= NULL)
	{
		printf("%s", temp2->customer);
		printf("%s", temp2->customerNum);
		printf("%s", temp2->gender);
		printf("%s", temp2->orderDes);
		printf("%s", temp2->customerAdd);
		temp2 = temp2->next;
	}
}

void display2(char a,char b,char c,char d,char e)
{
	if (temp2 != NULL)
	{
		a = temp2->customer;
		b = temp2->customerNum;
		c = temp2->gender;
		d = temp2->orderDes;
		e = temp2->customerAdd;
		temp2 = temp2->next;
		display2(a,b,c,d,e);
		printf("%s%s%s%s%s", a,b,c,d,e);

	}
}


void main()
{
	int choice;
	while (1)
	{
		printf("1. Insert to begining\n2. Insert to ending\n3. Print\nUr choice");
		fflush(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			insert2();
			break;
		case 3:
			display();
			break;
		case 4:
			temp2 = head;
			if (temp2 == NULL)
				printf("\nList empty to display");
			else
			{
				printf("\nReverse order of linked list : \n");
				display2(temp2->customer, temp2->customerNum, temp2->gender, temp2->orderDes, temp2->customerAdd);
			}
			break;
		default:
			exit(0);
			break;
		}
	}
}


