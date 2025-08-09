#include<stdio.h>
typedef int (*Operationfunc)(int,int) ;

int add(int a, int b)
{
    printf("执行加法...\n");
    return a + b;
}

int subtract(int a, int b)
{
    printf("执行减法...\n");
    return a - b;
}

int execute_op(Operationfunc fp, int a, int b)
{
    return fp(a,b);
}
int main()
{
    // 修正第四处：这是正确的调用流程

    // 1. 声明一个函数指针变量
    Operationfunc fp;

    // 2. 将 'add' 函数的地址赋值给它
    printf("任务: 执行 2 + 3\n");
    fp = add; // 函数名本身就是地址，无需 &

    // 3. 将该指针传入执行器
    int result = execute_op(fp, 2, 3);
    printf("最终值为: %d\n\n", result); // printf需要用 %d 格式化输出整数

    // 4. 更换指针指向的函数，执行新任务
    printf("任务: 执行 10 - 5\n");
    fp = subtract;
    result = execute_op(fp, 10, 5);
    printf("最终值为: %d\n", result);

    return 0;
    
}


