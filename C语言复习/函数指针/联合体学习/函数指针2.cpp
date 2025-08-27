#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}
// ��������������add, sub, mul, div
// ʹ��typedef���庯��ָ������
typedef int (*OperationFunc)(int, int);

int main() {
    int choice, a, b;
    // ���庯��ָ������
    int (*operations[4])(int, int) = { add,sub,mul,div };
    printf("Enter two numbers: ");
    scanf_s("%d %d", &a, &b);
    printf("Enter choice (0:add, 1:sub, 2:mul, 3:div): ");
    scanf_s("%d", &choice);

    if (choice >= 0 && choice <= 3) {
        int result = operations[choice](a, b);
        printf("Result: %d\n", result);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}