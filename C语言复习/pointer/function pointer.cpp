#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
//����ָ�� ָ������ָ��
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
	//����ָ������
	int(*arr[5]) (int, int) = { NULL, Add,Sub,Mul,Div };
	while (1)
	{
        // ��ȷ�ĺ���ָ����������
        pf arr[5] = { NULL, Add, Sub, Mul, Div }; // ʹ��NULL������0

        while (1) {
            printf("\n=== �������˵� ===\n");
            printf("0. �˳�\n");
            printf("1. �ӷ�\n");
            printf("2. ����\n");
            printf("3. �˷�\n");
            printf("4. ����\n");
            printf("��ѡ�����: ");

            int input = 0;
            scanf_s("%d", &input);

            if (input == 0) {
                printf("�˳�������\n");
                break; // ʹ��break�˳�ѭ��
            }
            else if (input >= 1 && input <= 4) {
                printf("����������������: ");
                int x = 0;
                int y = 0;
                scanf_s("%d %d", &x, &y);

                int ret = arr[input](x, y);
                printf("���: %d\n", ret);
            }
            else {
                printf("ѡ�����������ѡ��!\n");
                // ��������뻺�������ܵ��º���scanf��������
                while (getchar() != '\n'); // ������뻺����
            }
        }

        return 0;
	}
	

}