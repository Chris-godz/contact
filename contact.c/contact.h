#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define name_max 20
#define tel_max  20
#define addr_max 30
#define initialcapacity 3
struct peopleinformation
{
	char name[name_max];
	char tel[tel_max];
	char sex[3];
	char age[3];
	char addr[addr_max];
};
struct peoplecontact
{
	struct peopleinformation* date;
	int capacity;
	int size;
}; 
void contact_add(struct peoplecontact* ptr);
void initialcontact(struct peoplecontact* ptr);
void savecontact(struct peoplecontact* ptr);
void checkcapacity(struct peoplecontact* ptr);
void contact_del(struct peoplecontact* ptr);
void contact_search(struct peoplecontact* ptr);
void contact_Printf(struct peoplecontact* ptr);