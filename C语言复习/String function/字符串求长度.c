#include<stdio.h>
#include<string.h>
#include<assert.h>
//字符串长度
//strlen
size_t my_strlen(const char* a);
int main()
{
	char arr[] = "abcdef";//还有\0
	size_t len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
	
}

//字符串长度的三种方法
//1.计数器方法 2.指针-指针 3.递归的方式

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