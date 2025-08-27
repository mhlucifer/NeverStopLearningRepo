//字符指针
#define _CRT_SECURE_NO_WARINGS
#include<stdio.h>

int main()
{
	/*char ch = 'w';
	char *pc = &ch;
	*pc = 'b';
	printf("%c\n", ch);*/
	//return 0;

	//const char* p = "abcdef";//把字符串首字符a的地址，赋值给了P
	//*p = "13123";
	//printf("%s\n", p);

	//指针指向常量字符串时，同时创建两个指针都会指向一个地址
	//但是数组在创建两个空间时，即使字符串相同，也不会创建同一个空间


	//指针数组 是数组，用来存放指针的数组
	/*in arr[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[3] = { arr,arr3,arr2 };
	for (int i = 0; i < 2; i++)
	{
		for(int j =0;j < 2;j++)
		printf("%d\n", parr[i][j]);
	}*/
	
	//数组指针
	// 两例外，一是&arr，虽然值相同，但类型不同，这里的数组名依然是整个数组
	// 一个是sizeof(数组名)
	//void (*arr)[]


	//数组指针数组
	


	//数组参数，指针参数
	//最主要的一点就是要确保传递类型是一致的


	
	
}