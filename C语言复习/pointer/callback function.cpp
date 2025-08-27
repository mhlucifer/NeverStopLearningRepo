#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
//回调函数
void Bubble_sort(int arr[], int sz)
{
	int i = 0;
	
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设数组有序
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

}
int main()
{
	//回调函数就是一个通过函数指针调用的函数，如果你把函数的指针作为参数传递给另一个函数
	//当这个指针被用来调用其所指向的函数时，就是叫回调函数
	//冒泡排序作为例子
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
