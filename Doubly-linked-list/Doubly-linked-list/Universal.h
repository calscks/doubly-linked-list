#ifndef UNIVERSAL
#define UNIVERSAL
#define l 200

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
node *headcus, *endcus, *temp, *currec, *forcount;

void create();

_Bool validnum();

_Bool validchar();

void insertB();

void insertE();

void displayB();

void displayE(char a[l], char b[l], char c[l], char d[l], char e[l]);

void deleteNode();

void writefile();

void readfile();

#endif