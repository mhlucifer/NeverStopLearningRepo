// 奇偶数调整.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string.h>
#include<time.h>
using namespace std;
void AdjustArray(int arr[], int size)
{
    int* p = arr;
    int* q = arr + size - 1;
    while (p < q)
    {
        if ((*p & 0x1) == 0)
        {
            p++;
            continue;
        }

        if ((*q & 0x1) == 1)
        {
            q--;
            continue;
        }

        int tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
}
int main()
{
    int arr[10] = { 0 };
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    AdjustArray(arr, 10);
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
}
