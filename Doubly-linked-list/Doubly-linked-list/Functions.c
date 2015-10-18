#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Universal.h"

int count = 0;// we use count to determine our structures' position.

void create() //create a new struct for new customer inputs
{
	temp = (node*)malloc(sizeof(node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("Enter customer's name:\n");
	fflush(stdin);
	fgets(&temp->customer, l, stdin);
	printf("Enter customer's number:\n");
	fflush(stdin);
	do
	{
		fgets(&temp->customerNum, l, stdin);
	} while (validnum(1));
	printf("Enter customer's gender:\n");
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

int validnum() //simple input checking for customerNum
{
	int length, n;
	/*int length will carry the value of the length of customerNum string.
	For example, strlen("tttt") = 4*/
	length = strlen(temp->customerNum);
	for (n = 0; n < length; n++)
	{
		/*checks every characters whether one or more do carry something other than numerical value.
		isdigit requires <ctype.h>*/
		if (!isdigit(temp->customerNum[n]))
		{
			printf("You need to input numerical values only! Please try again\n");
			return 1;
		}
		else
			return 0;
	}
}

void insertB() //insert at beginning
{
	create();
	if (endcus == NULL)
	{
		endcus = temp;
	}
	if (headcus) // if headcus != NULL
	{
		temp->next = headcus;
		headcus->prev = temp;
	}
	headcus = temp;
}

void insertE() //insert to the end
{
	create();
	if (headcus == NULL)
	{
		headcus = temp;
	}
	if (endcus)
	{
		endcus->next = temp;
		temp->prev = endcus;
	}
	endcus = temp;
}

void displayB() //display from beginning
{
	currec = headcus;

	if (currec == NULL)
	{
		printf("List empty to display. Press any key to continue.\n");
		system("pause >nul");
		return;
	}
	printf("\nLinked list elements from begining : \n");

	while (currec)
	{
		printf("%d", count); //temporary code to check count
		printf("Customer's name:\n");
		printf("%s", currec->customer);
		printf("Customer's number:\n");
		printf("%s", currec->customerNum);
		printf("Customer's gender:\n");
		printf("%s", currec->gender);
		printf("Order description:\n");
		printf("%s", currec->orderDes);
		printf("Customer's address:\n");
		printf("%s", currec->customerAdd);
		currec = currec->next;
		system("pause");
	}
}

void displayE(char a[l], char b[l], char c[l], char d[l], char e[l]) //display from the end
{
	currec = endcus;
	while (currec)
	{
		a = currec->customer;
		b = currec->customerNum;
		c = currec->gender;
		d = currec->orderDes;
		e = currec->customerAdd;
		printf("%d", count); //temporary code to check count
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
		currec = currec->prev;
		system("pause");
	}
}

void deleteNode() //delete node at any position
{
	int i = 1, pos;

	currec = headcus;
	printf("\nEnter position to delete:\n");
	fflush(stdin);
	scanf("%d", &pos);

	if (!headcus)
	{
		printf("Empty list. \n");
		system("pause >nul");
		return; //prevent loading to next line
	}

	if (pos < 1 || pos >= count + 1)
	{
		printf("Out of range!");
		system("pause >nul");
		return; //prevent loading to next line
	}

	if (headcus)
	{
		for (i; i < pos; i++)
			currec = currec->next;
		printf("%2d. %s", i, currec->customer);
		printf("You gonna delete this\n");
		system("pause >nul");
		if (currec->next != NULL)
			currec->next->prev = currec->prev;
		if (currec->prev != NULL)
			currec->prev->next = currec->next;
		if (headcus == currec)
			headcus = currec->next;
		if (endcus == currec)
			endcus = currec->prev;
		free(currec);
		printf("deleted\n");
		count--;
	}

	

	//i don't know why below codes have problem. So I create new codes for this as above.
	/*
	void deleteNode()
	{
		int i = 1, pos;

		printf("\nEnter position to delete:\n");
		scanf("%d", &pos);
		currec = headcus;

		if ((pos < 1) || (pos >= count + 1))
		{
			printf("\nError : Position out of range to delete");
			return;
		}
		if (headcus == NULL)
		{
			printf("\nEmpty linked list.");
			return;
		}
		else
		{
			while (i < pos)
			{
				currec = currec->next;
				i++;
			}
			if (i == 1)
			{
				if (currec->next == NULL)
				{
					printf("Node deleted from list: %d\n", pos);
					free(currec);
					currec = headcus = NULL;
					return;
				}
			}
			if (currec->next == NULL)
			{
				currec->prev->next = NULL;
				free(currec);
				printf("Node deleted from list: %d\n", pos);
				system("pause >nul");
				return;
			}
			currec->next->prev = currec->prev;
			if (i != 1)
				headcus = currec->next;
			if (i = 1)
				headcus = currec->next;
			printf("\nNode deleted");
			free(currec);
			system("pause >nul");
		}
		count--;
	}*/
}