// vector的普通和安全实现方式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>


class MyVector
{
private:
	int* m_data;
	size_t m_size;
	size_t m_capacity;
	void reserve(size_t new_capacity)
	{
		if (new_capacity <= m_capacity)return;
		int* new_data = new int[new_capacity];
		for (int i = 0; i < m_size; i++)
		{
			new_data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
		new_data = nullptr;
	}


public:
	MyVector() :m_data(nullptr), m_size(0), m_capacity(0) {};
	~MyVector()
	{
		delete[] m_data;
	}


	MyVector(const MyVector& other)
	{
		m_data = new int[other.size()];
		for (size_t i = 0; i < other.m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
		m_size = other.m_size;
		m_capacity = other.m_size;
		std::cout << "MyVector 拷贝构造函数被调用" << std::endl;

	}

	MyVector& operator= (const MyVector& other)
	{

	}

	void push_back(const int& value)
	{
		if (m_size == m_capacity)
		{
			size_t new_cap = (m_capacity == 0) ? 1 : m_capacity * 2;
			reserve(new_cap);
		}
		m_data[m_size++] = value;
	}

	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return  m_capacity;
	}
};

int main()
{
	MyVector vec;
	std::cout << "初始状态 -> "
		<< "Size: " << vec.size()
		<< ", Capacity: " << vec.capacity() << std::endl;

	std::cout << "\n开始添加元素..." << std::endl;
	for (int i = 0; i < 5; ++i) {
		vec.push_back(i);
		std::cout << "push_back(" << i << ") 后 -> "
			<< "Size: " << vec.size()
			<< ", Capacity: " << vec.capacity() << std::endl;
	}
	vec.push_back(200);
	MyVector vec2 = vec;
	return 0;
}

