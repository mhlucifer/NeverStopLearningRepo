// 数组逆序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;

void Reverse(char arr[], int size)
{
    char* p = arr;
    char* q = arr + size - 1;
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}
int main()
{
    char arr[] = "hello world";
    Reverse(arr, strlen(arr));
    cout << arr << endl;
}

