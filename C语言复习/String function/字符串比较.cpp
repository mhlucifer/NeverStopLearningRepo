#include<stdio.h>
#include<assert.h>
#include<string.h> // ��Ҫ���ͷ�ļ�


int main()
{
	char arr[20] = "zhangsan";
	char arr1[] = "zhangsanfeng";
	//arr��arr1��������������Ԫ�ص�ַ
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