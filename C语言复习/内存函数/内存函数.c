#include<stdio.h>
#include<assert.h>
#include<string.h>
#define _CRT_SECURE_NO_WARININGS 1

void* my_memcpy(void * dest,const void * src,size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	//memove 内存覆盖的时候使用

	return ret;

}
int main()
{
	int arr1[] = { 1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 20);
	int i= 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d", arr2[i]);
	}
	return 0;
}