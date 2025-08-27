#include <stdio.h>

int add(int *a, int *b)
{
    return (*a + *b);
}
// 定义函数 add

int main() {
    int a = 20;
    int b = 30;
    typedef int (*pFuncType)(int *, int *);
    pFuncType pFunc2 = add;
    int rest = pFunc2(&a, &b);
    printf("%d", rest);
    
    // 定义函数指针 pFunc 并指向 add
    // 通过 pFunc 调用 add，计算 3 和 5 的和
    return 0;
}