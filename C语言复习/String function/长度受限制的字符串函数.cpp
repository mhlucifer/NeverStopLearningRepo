//strncpy
//strncat
//strncmp
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//1£º11£º11
int main()
{
	/*char arr1[20] = "abcdef";
	char arr2[] = "hello bit";
	strncpy(arr1, arr2,sizeof(arr1));
	printf("%s\n", arr1);*/

	char arr1[20] = "abcdef";
	char arr2[] = "hello bit";
	strncat(arr1, arr2, 3);
	printf("%s\n", arr1);


}