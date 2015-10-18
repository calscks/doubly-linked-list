#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Universal.h"
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	//system("color f0");
	int choice;
	while (1)
	{
		system("cls");
		printf("Linked list\n\n");
		printf("1. Insert at the beginning\n2. Insert to the end\n3. Print from beginning\n4. Print from the end\n5. Delete from any position\n6. Quit system\nSelection: ");
		fflush(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insertB();
			break;
		case 2:
			insertE();
			break;
		case 3:
			displayB();
			break;
		case 4:
			currec = headcus;
			if (currec == NULL)
			{
				printf("List empty to display. Press any key to continue.\n");
				system("pause >nul");
			}
			else
			{
				printf("\nReverse order of linked list : \n");
				displayE(currec->customer, currec->customerNum, currec->gender, currec->orderDes, currec->customerAdd);
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


