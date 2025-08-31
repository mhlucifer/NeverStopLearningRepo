#include<stdio.h>
#include"数组实现.h"

//链表创建
sqlist* sqlist_create()
{
	sqlist* me;
	me = malloc(sizeof(*me));
	if (me == NULL)
	{
		return NULL;
	}
	me->last = -1;
	return me;
}
void sqlist_create1(sqlist** ptr)
{
	*ptr = malloc(sizeof(**ptr));
	if (*ptr == NULL)
	{
		return;
	}
	(*ptr)->last = -1;
	return;
}
;

int sqlist_insert(sqlist* me, int i, datatype* data)
{
	int j;
	if (me->last == DATASIZE - 1)
	{
		return -1;
	}
	if (i < 0 || i > me->last + 1)
		return -2;

	for (j = me->last; i <= j; j--)
	{
		me->data[j + 1] = me->data[j];
	}
	me->data[i] = *data;
	me->last++;
	return 0;
};
int sqlist_delete(sqlist*, int i);
int sqlist_find(sqlist*, datatype*);
int sqlist_empty(sqlist*);
int sqlist_setempty(sqlist*);
int sqlist_getnum(sqlist*);
void sqllist_display(sqlist*);
int sqlist_destroy(sqlist*);
int sqlist_union(sqlist*, sqlist*);
