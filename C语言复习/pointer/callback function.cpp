#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
//�ص�����
void Bubble_sort(int arr[], int sz)
{
	int i = 0;
	
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//������������
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
	//�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ����Ϊ�������ݸ���һ������
	//�����ָ�뱻������������ָ��ĺ���ʱ�����ǽлص�����
	//ð��������Ϊ����
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
