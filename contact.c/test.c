#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"
struct peoplecontact contact;
enum MyEnum
{
	exist,
	add,
	del,
	modify,
	sort,
	Printf,
	search
};
void menu()
{
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*******1 .add   2.del   3 modify ************\n");
	printf("*******4.sort           5.printf ************\n");
	printf("*******6.search         0.exist  ************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
}
int main()
{
	int i = 0;
	initialcontact(&contact);
	do
	{
		menu();
		scanf("%d", &i);
		switch (i)
		{
		case add:
			contact_add(&contact);
			break;
		case del:
			contact_del(&contact);
			break;
		case search:
			contact_search(&contact);
			break;
		case Printf:
			contact_Printf(&contact);
			break;
		


			}

	} while (i);
	savecontact(&contact);
	printf("³É¹¦ÍË³ö£¡£¡£¡£¡£¡");
}