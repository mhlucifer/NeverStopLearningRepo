#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student
{
	int ID;
	char name[500];
	int sign;
} student;

int main()
{
	student s;
	student* s1;
	s.ID = 10;
	s.sign = 10;
	
	student* ip = (student*)malloc(sizeof(student));
	printf("ID %d\n", s.ID);
	free(ip);
}