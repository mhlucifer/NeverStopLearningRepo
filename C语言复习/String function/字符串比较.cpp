#include<stdio.h>
#include<assert.h>
#include<string.h> // 需要这个头文件


int main()
{
	char arr[20] = "zhangsan";
	char arr1[] = "zhangsanfeng";
	//arr和arr1是数组名，是首元素地址
	/*if (arr == arr1)
	{
		
	}*/
	int flag = strcmp(arr, arr1);
	if (flag < 0)
	{
		printf("<\n");
	}
	else if (flag == 0)
	{
		printf("=\n");
	}
	else
		printf(">\n");
}