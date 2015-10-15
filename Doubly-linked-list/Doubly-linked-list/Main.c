#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define l 100

int count = 0;

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
	count++;
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

	while (temp2->next != NULL)
	{
		printf("Customer's name:\n");
		printf("%s", temp2->customer);
		printf("Customer's number:\n");
		printf("%s", temp2->customerNum);
		printf("Customer's gender:\n");
		printf("%s", temp2->gender);
		printf("Order description:\n");
		printf("%s", temp2->orderDes);
		printf("Customer's address:\n");
		printf("%s", temp2->customerAdd);
		temp2 = temp2->next;
		system("pause");
	}
	printf("Customer's name:\n");
	printf("%s", temp2->customer);
	printf("Customer's number:\n");
	printf("%s", temp2->customerNum);
	printf("Customer's gender:\n");
	printf("%s", temp2->gender);
	printf("Order description:\n");
	printf("%s", temp2->orderDes);
	printf("Customer's address:\n");
	printf("%s", temp2->customerAdd);
	system("pause");
}

void display2(char a[l], char b[l], char c[l], char d[l], char e[l])
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
		printf("Customer's name:\n");
		printf("%s", a);
		printf("Customer's number:\n");
		printf("%s", b);
		printf("Customer's gender:\n");
		printf("%s", c);
		printf("Order description:\n");
		printf("%s", d);
		printf("Customer's address:\n");
		printf("%s", e);
		system("pause");
	}
}

void deleteNode()
{
	int i = 1, pos;

	printf("\nEnter position to delete:\n");
	scanf("%d", &pos);
	temp2 = head;

	if ((pos < 1) || (pos >= count + 1))
	{
		printf("\nError : Position out of range to delete");
		return;
	}
	if (head == NULL)
	{
		printf("\nEmpty linked list.");
		return;
	}
	else
	{
		while (i < pos)
		{
			temp2 = temp2->next;
			i++;
		}
		if (i == 1)
		{
			if (temp2->next == NULL)
			{
				printf("Node delted from list: %d\n",pos);
				free(temp2);
				temp2 = head = NULL;
				return;
			}
		}
		if (temp2->next == NULL)
		{
			temp2->prev->next = NULL;
			free(temp2);
			printf("Node deleted from list: %d\n",pos);
			return;
		}
		temp2->next->prev = temp2->prev;
		if (i != 1)
			head = temp2->next;
		if (i = 1)
			head = temp2->next;
		printf("\nNode deleted");
		free(temp2);
	}
	count--;
}


void main()
{
	system("color f0");
	int choice;
	while (1)
	{
		system("cls");
		printf("Linked list\n\n");
		printf("1. Insert to begining\n2. Insert to ending\n3. Print from beginning\n4. Print from ending\n5. Delete from any position\n6. Quit system\nSelection: ");
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
		case 5:
			deleteNode();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nInvalid input!!\n\a");
			system("pause");
			break;
		}
	}
}


