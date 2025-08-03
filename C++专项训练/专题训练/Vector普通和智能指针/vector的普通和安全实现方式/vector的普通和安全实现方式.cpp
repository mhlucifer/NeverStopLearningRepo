// vector的普通和安全实现方式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>

class my_Vector
{
private:
	int* data;
	size_t size;
	size_t capcaity;

public:
	my_Vector(const int* data, size_t size, size_t capcaity) :data(nullptr), size(0), capcaity(0) {};
	void push_back(int value)
	{
		if (size > capcaity)
		{
			int* new_data = new int[capcaity * 2];
			for (int i = 0; i < size; i++)
			{
				new_data[i] = data[i];
			}
			
		}
	}

};

int main()
{
    std::cout << "Hello World!\n";
}

