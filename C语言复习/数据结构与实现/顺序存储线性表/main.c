#include<stdio.h>
#include<stdlib.h>
#include"数组实现.h"

int main()
{
	sqlist* list;
	/*list = sqlist_create();*/
	datatype arr[] = { 12,23,45,56 ,67 };
	int i;
	sqlist_create1(&list);
	if (list == NULL)
	{
		fprintf(stderr, "Sqlist_creat() failed!\n");
		exit(1);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		if((err))
	}
	sqlist_insert(list, 1, 10);
	sqllist_display(list);


	sqlist_destroy(list);
	exit(0);
}
