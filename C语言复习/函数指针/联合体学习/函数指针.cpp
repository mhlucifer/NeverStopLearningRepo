#include <stdio.h>

int add(int *a, int *b)
{
    return (*a + *b);
}
// ���庯�� add

int main() {
    int a = 20;
    int b = 30;
    typedef int (*pFuncType)(int *, int *);
    pFuncType pFunc2 = add;
    int rest = pFunc2(&a, &b);
    printf("%d", rest);
    
    // ���庯��ָ�� pFunc ��ָ�� add
    // ͨ�� pFunc ���� add������ 3 �� 5 �ĺ�
    return 0;
}