#include<stdio.h>
#include<string.h>
#include<assert.h>
//�ַ�������
//strlen
size_t my_strlen(const char* a);
int main()
{
	char arr[] = "abcdef";//����\0
	size_t len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
	
}

//�ַ������ȵ����ַ���
//1.���������� 2.ָ��-ָ�� 3.�ݹ�ķ�ʽ

size_t my_strlen(const char* a)
{
	size_t count = 0;
	assert(a);
	while(*a != '\0')
	{
		count++;
		a++;
	}
	return count;
}


//