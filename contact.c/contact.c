#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void savecontact(struct peoplecontact* ptr)
{
	FILE* fp = fopen("pfwrite.date", "wb");
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ptr->size;i++)
	{
		fwrite(&(ptr->date[i]), sizeof(struct peopleinformation), 1, fp);
	}
	fclose(fp);
	fp = NULL;
}
void initialcontact(struct peoplecontact* ptr)
{
	struct peopleinformation tem;
	ptr->size = 0;
	ptr->capacity = initialcapacity;
	ptr->date = (struct peopleinformation*)malloc(initialcapacity * sizeof(struct peopleinformation));
	if (ptr->date == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	FILE* fp = fopen("pfwrite.date", "rb");
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	while(fread(&tem, sizeof(struct peopleinformation), 1, fp)) {
		checkcapacity(ptr);
		ptr->date[ptr->size] = tem;
		ptr->size++;
	}
	fclose(fp);
	fp = NULL;
}
void contact_add(struct peoplecontact* ptr)
{
	checkcapacity(ptr);
	printf("��������->");
	scanf("%s", ptr->date[ptr->size].name);
	printf("����绰->");
	scanf("%s", ptr->date[ptr->size].tel);
	printf("�����Ա�->");
	scanf("%s",&ptr->date[ptr->size].sex);
	printf("��������->");
	scanf("%s", &ptr->date[ptr->size].age);
	printf("�����ַ->");
	scanf("%s", ptr->date[ptr->size].addr);
	savecontact(ptr);
	ptr->size += 1;
	printf("ADD SUCCESSFULLY\n");

}
void checkcapacity(struct peoplecontact* ptr)
{
	if (ptr->size == ptr->capacity)
	{
		struct peopleinformation* pti = realloc(ptr->date, (ptr->capacity + 2) * sizeof(struct peopleinformation));
		if (pti == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		ptr->date = pti;
		ptr->capacity += 2;
	}
}
static int FINDbyname(struct peoplecontact* ptr,char name[])
{
	int i = 0;
	for (i = 0; i < ptr->size; i++)
	{
		if (strcmp(ptr->date[i].name, name)==0)
		{
			return i;
		}
     }
	return -1;

}
void contact_del(struct peoplecontact* ptr)
{
	char name[name_max] = { 0 };
	if (ptr->size == 0)
	{
		printf("NObody can be deleted\n");
		return;
	}
	printf("��������Ҫɾ���Ķ���->");
	scanf("%s", name);
	int j=FINDbyname(ptr,name);
	if (j == -1)
	{
		printf("û����Ҫ�ҵ���\n");
		return;
	}
	for (int i = j; j < ptr->size - 1; i++)
	{
		ptr->date[i] = ptr->date[i + 1];
	}
	ptr->capacity--;
	savecontact(ptr);
}
void contact_search(struct peoplecontact* ptr)
{
	int i = 0;
	char name[name_max] = { 0 };
	printf("��������Ҫ���ҵĶ���->");
	scanf("%s", name);
	int j = FINDbyname(ptr, name);
	if (j == -1)
	{
		printf("û����Ҫ�ҵ���\n");
		return;
	}
	i = j;
	printf("%-20s\t%-15s\t%-10s\t%-10s\t%-20s\n", "����", "�绰", "�Ա�", "����", "��ַ");
	printf("%-20s\t%-15s\t%-10s\t%-10s\t%-20s\n", ptr->date[i].name,
		ptr->date[i].tel,
		&ptr->date[i].sex,
		&ptr->date[i].age,
		ptr->date[i].addr);
}
void contact_Printf(struct peoplecontact* ptr)
{
	int i = 0;
	printf("%-20s\t%-15s\t%-10s\t%-10s\t%-20s\n", "����", "�绰", "�Ա�", "����", "��ַ");
	for (i = 0; i < ptr->size; i++)
	{
		printf("%-20s\t%-15s\t%-10s\t%-10s\t%-20s\n", ptr->date[i].name,
			ptr->date[i].tel,
			&ptr->date[i].sex,
			&ptr->date[i].age,
			ptr->date[i].addr);
	}     
}