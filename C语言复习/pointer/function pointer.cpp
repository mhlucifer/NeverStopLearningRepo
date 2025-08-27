#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
//函数指针 指向函数的指针
typedef int (*pf)(int, int);
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{

	//printf("%p\n", &Add);
	//printf("%p\n", Add); 
	//pf pte= Add;
	//int ret = pte(2, 3);
	//printf("%d", ret);
	//函数指针数组
	int(*arr[5]) (int, int) = { NULL, Add,Sub,Mul,Div };
	while (1)
	{
        // 正确的函数指针数组声明
        pf arr[5] = { NULL, Add, Sub, Mul, Div }; // 使用NULL而不是0

        while (1) {
            printf("\n=== 计算器菜单 ===\n");
            printf("0. 退出\n");
            printf("1. 加法\n");
            printf("2. 减法\n");
            printf("3. 乘法\n");
            printf("4. 除法\n");
            printf("请选择操作: ");

            int input = 0;
            scanf_s("%d", &input);

            if (input == 0) {
                printf("退出计算器\n");
                break; // 使用break退出循环
            }
            else if (input >= 1 && input <= 4) {
                printf("请输入两个操作数: ");
                int x = 0;
                int y = 0;
                scanf_s("%d %d", &x, &y);

                int ret = arr[input](x, y);
                printf("结果: %d\n", ret);
            }
            else {
                printf("选择错误，请重新选择!\n");
                // 不清空输入缓冲区可能导致后续scanf出现问题
                while (getchar() != '\n'); // 清空输入缓冲区
            }
        }

        return 0;
	}
	

}