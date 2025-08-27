#include<stdio.h>
#include<assert.h>
#include<string.h> // 需要这个头文件
char * m_strcpy(char* dest, char* src)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	/*while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;*/
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//字符串追加 
char* my_cat(char* dest, char* src)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	/*char name[20] = { 0 };
	snprintf(name, sizeof(name), "%s", "zhangsan");
	printf("%s\n", name);
	m_strcpy(name, "1231");
	printf("%s\n", name);*/
	char arr[20] = "hello";
	strcat_s(arr, sizeof(arr), " world");
	printf("%s\n", arr);
	my_cat(arr, "world");
	printf("%s\n", arr);
	return 0;
}