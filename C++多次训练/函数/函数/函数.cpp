// 函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
int sub(int &a, int &b)
{
    return a - b;
}
int main()
{
    int w = 10;
    int q = 11;
    int a =sub(w, q);
    std::cout << "Hello World!\n"<<std::endl;
    std::cout << a<<std::endl;
}

