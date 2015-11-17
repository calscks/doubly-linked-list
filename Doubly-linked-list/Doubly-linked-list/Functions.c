#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Universal.h"

int count = 0;// we use count to determine number of our structures

void create() //create a new struct for new customer inputs
{
	temp = (node*)malloc(sizeof(node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("Enter customer's name:\n");
	do
	{
		fflush(stdin);
		fgets(&temp->customer, l, stdin);
		/* fgets actually takes \n as 1 char. for example
		input aaaa and then enter, the strlen will be 5 because "aaaa\n". below is the fix */
		if (temp->customer[strlen(temp->customer) - 1] == '\n')
			temp->customer[strlen(temp->customer) - 1] = 0;
	} while (validchar(true)); //this is the boolean function

	printf("Enter customer's number:\n");
	do
	{
		fflush(stdin);
		fgets(&temp->customerNum, l, stdin);
		if (temp->customerNum[strlen(temp->customerNum) - 1] == '\n')
			temp->customerNum[strlen(temp->customerNum) - 1] = 0;
	} while (validnum(true)); //this is the boolean function

	printf("Enter customer's gender:\n");
	do
	{
		fflush(stdin);
		fgets(&temp->gender, l, stdin);
		if (temp->gender[strlen(temp->gender) - 1] == '\n')
			temp->gender[strlen(temp->gender) - 1] = 0;
	} while (validgend(true)); //boolean function to check gender

	printf("Enter order description:\n");
	fflush(stdin);
	fgets(&temp->orderDes, l, stdin);
	printf("Enter customer address:\n");
	fflush(stdin);
	fgets(&temp->customerAdd, l, stdin);
	count++;
}

_Bool validnum() //simple input checking for customerNum
{
	int length, n;
	/*int length will carry the value of the length of customerNum string.
	For example, strlen("tttt") = 4*/
	length = strlen(temp->customerNum);

	if (length == 0)
	{
		printf("Please at least enter something\n");
		return true;
	}
	for (n = 0; n < length; n++)
	{
		/*checks every characters whether one or more do carry something other than numerical value.
		isdigit requires <ctype.h>*/
		if (!isdigit(temp->customerNum[n]))
		{
			printf("You need to input numerical values only! Please try again:\n");
			return true;
		}
	}
	return false;
}

_Bool validchar() //simple input checking for customer name
{
	int len, ch;
	len = strlen(temp->customer); //string length

	if (len == 0)
	{
		printf("Please at least enter something\n");
		return true;
	}

	for (ch = 0; ch <= len; ch++)
	{
		if (isdigit(temp->customer[ch]))
		{
			printf("Name shall not consist of numbers! Please try again:\n");
			return true;
		}
	}
	return false;
}

_Bool validgend() //gender validation
{
	char gend[8][10] = { "Male", "M", "male", "m", "Female", "F", "female", "f" }; //2-D arrays to store strings
	int gendin = strlen(temp->gender), i;

	if (gendin == 0)
	{
		printf("Please at least enter something\n");
		return true;
	}

	for (i = 0; i < 8; i++)
	{
		if (strcmp(temp->gender, gend[i]) == 0)
		{
			return false;
		};
	}
	printf("Gender is not valid. Please try again:\n");
	return true;
}

void insertB() //insert at beginning
{
	create(); // call node create
	if (endcus == NULL)
	{
		endcus = temp; //if endcus is nothing, your endcus is the temp (newly created node)
	}
	if (headcus != NULL)
	{
		temp->next = headcus; //when original headcus is not empty, the next of your newly create node will be that headcus
		headcus->prev = temp; //the prev of that headcus is your new node
	}
	headcus = temp; //set your new node as headcus
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

	while (currec) //remember this: (xx) means xx != NULL, (!xx) means xx == NULL
	{
		system("cls");
		printf("Customer's name: ");
		printf("%s", currec->customer);
		printf("\nCustomer's number: ");
		printf("%s", currec->customerNum);
		printf("\nCustomer's gender: ");
		printf("%s", currec->gender);
		printf("\nOrder description: ");
		printf("%s", currec->orderDes);
		printf("Customer's address: ");
		printf("%s", currec->customerAdd);
		currec = currec->next; //iterate to next record and print again

		if (currec != NULL)
			printf("Press any key to load next customer.");
		else
			printf("No more customer to show. Press any key to return back to menu.");
		system("pause >nul");
	}
}

void displayE(char a[l], char b[l], char c[l], char d[l], char e[l]) //display from the end, another way to display
{
	currec = endcus;
	while (currec)
	{
		system("cls");
		a = currec->customer;
		b = currec->customerNum;
		c = currec->gender;
		d = currec->orderDes;
		e = currec->customerAdd;
		printf("Customer's name: ");
		printf("%s", a);
		printf("\nCustomer's number: ");
		printf("%s", b);
		printf("\nCustomer's gender: ");
		printf("%s", c);
		printf("\nOrder description: ");
		printf("%s", d);
		printf("Customer's address: ");
		printf("%s", e);
		currec = currec->prev; //iterate from endcus to first (last to first)

		if (currec != NULL)
			printf("Press any key to load next customer.");
		else
			printf("No more customer to show. Press any key to return back to menu.");
		
		system("pause >nul");
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

	if (headcus) //if headcus != NULL
	{
		for (i; i < pos; i++)
			currec = currec->next;
		printf("%2d. %s", i, currec->customer);
		printf("\nYou are deleting this customer.\n"); //you gonna delete currec!
		system("pause >nul");
		if (currec->next != NULL) //if next of currec got something
			currec->next->prev = currec->prev; //(currec's next)'s previous will be (currec's previous). So currec's chain is breaked.
		if (currec->prev != NULL) //if prev of currec got something
			currec->prev->next = currec->next; //(currec's previous)'s next will be (currec's next). Currec's chain is fully breaked!
		if (headcus == currec) //if deleting headcus
			headcus = currec->next; //next of the headcus to be deleted will be the new headcus
		if (endcus == currec) //if deleting endcus
			endcus = currec->prev; //previous of the endcus to be deleted will be the new endcus
		free(currec); //free the memory!
		printf("deleted\n");
		count--; //deduct the count of total no of nodes
	}
}

void writefile() //saving data
{
	FILE *f;
	currec = headcus;
	if (headcus == NULL)
	{
		printf("There is nothing to be saved. ");
		system("pause >nul");
		return;
	}

	f = fopen("saves.dat", "wb+"); //open (create) save.dat as reading and writing binary
	
	while (currec)
	{
		fwrite(currec->customer, sizeof(currec->customer), 1, f);
		fwrite(currec->customerNum, sizeof(currec->customerNum), 1, f);
		fwrite(currec->gender, sizeof(currec->gender), 1, f);
		fwrite(currec->orderDes, sizeof(currec->orderDes), 1, f);
		fwrite(currec->customerAdd, sizeof(currec->customerAdd), 1, f);
		printf("Save successful\n");
		currec = currec->next; //write all the nodes into file
	}
	fclose(f);
	system("pause >nul");
}

void readfile()
{
	FILE *f;
	
	if ((f = fopen("saves.dat", "rb")) == NULL)
	{
		printf("The saved file does not exist.\n");
		system("pause >nul");
		return;
	}

	while (headcus) //deletion
	{
		currec = headcus;
		if (currec->next != NULL)
			currec->next->prev = currec->prev;
		if (currec->prev != NULL)
			currec->prev->next = currec->next;
		if (headcus == currec)
			headcus = currec->next;
		if (endcus == currec)
			endcus = currec->prev; //breaking the node chain in a safer way!!
		free(currec);
		
	}
	//above codes have problems, what i am doing is deleting the whole linked list but gt problem
	//above codes have NO MORE PROBS CUZ I FIXED IT USING A SAFER WAY

	int counter = 0;
	while (!feof(f))
	{
		temp = malloc(sizeof(node)); //PROBLEM: after clearance, vs will automatically breaks here, and when continue,
		//print from beginning no prob, print from end keep looping e.g. b->a->b->a->b...
		//PROB FIXED
		temp->prev = NULL;
		temp->next = NULL;

		fread(temp->customer, sizeof(temp->customer), 1, f);
		fread(temp->customerNum, sizeof(temp->customerNum), 1, f);
		fread(temp->gender, sizeof(temp->gender), 1, f);
		fread(temp->orderDes, sizeof(temp->orderDes), 1, f);
		fread(temp->customerAdd, sizeof(temp->customerAdd), 1, f);
		count++;
		counter++;
		if (!headcus) //==NULL
		{
			headcus = temp;
		}
		if (endcus) //!=NULL
		{
			endcus->next = temp;
			temp->prev = endcus;
		}
		endcus = temp;
	}
	fclose(f);

	currec = headcus;
	int i = 1, position = counter; //i'm deleting the last node that was retrieved as a null or /0 value.
	for (i; i < position; i++)
		currec = currec->next;
	if (currec->next != NULL)
		currec->next->prev = currec->prev;
	if (currec->prev != NULL)
		currec->prev->next = currec->next;
	if (headcus == currec)
		headcus = currec->next;
	if (endcus == currec)
		endcus = currec->prev;
	free(currec);
	count--;
	for (int ii = 1; ii < counter; ii++)
	printf("Load successful\n");
	system("pause >nul");
}

void search()
{
	char a[l];
	int counter = 1;
	temp = headcus;
	if (temp == NULL)
	{
		printf("\nList empty to search for data\n\a");
		system("pause");
		return 1;
	}

	else
	{
		printf("Enter customer's name:\n");
		do
		{
			fflush(stdin);
			fgets(&a, l, stdin);
			if (a[strlen(a) - 1] == '\n')
				a[strlen(a) - 1] = 0;
		} while (validchar(true));

		while (temp != NULL)
		{
			if (!strcmp(temp->customer, a))
			{
				printf("Customer's name: ");
				printf("%s", temp->customer);
				printf("\nCustomer's number: ");
				printf("%s", temp->customerNum);
				printf("\nCustomer's gender: ");
				printf("%s", temp->gender);
				printf("\nOrder description: ");
				printf("%s", temp->orderDes);
				printf("Customer's address: ");
				printf("%s", temp->customerAdd);
				system("pause >nul");
				return 1;
			}
			else
			{
				temp = temp->next;
				counter++;
			}
		}
		printf("\n%s not found in list\n", a);
		system("pause");
	}
}


/* for line 211 and 213 if u still not clear, imagine a,b,c as the doubly linked list and currec = b.
Now i want to delete b, (b->next)->previous is c->previous, i set c->previous is equal to b->previous.
Then, (b->prev)->next is a->next, set a->next is euqal to b->next! So all chains chained to b is breaked and a is chained with
c and vice versa. */