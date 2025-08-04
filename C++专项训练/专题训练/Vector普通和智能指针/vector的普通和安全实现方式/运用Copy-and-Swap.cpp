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


	MyVector(const MyVector& other) :m_size(other.m_size), m_capacity(other.m_capacity)
	{
		m_data = new int[other.m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
		std::cout << "MyVector 拷贝构造函数被调用" << std::endl;
	}

	void swap(MyVector& other) noexcept {
		using std::swap;
		swap(m_data, other.m_data);
		swap(m_size, other.m_size);
		swap(m_capacity, other.m_capacity);
	}

	MyVector& operator=(MyVector other) // 1. 关键改动：参数从 const MyVector& 变为 MyVector
	{
		std::cout << "Copy-and-Swap 版本的赋值运算符被调用！" << std::endl;

		// 2. 关键操作：与“副本”交换数据
		swap(other);

		// 3. 按约定返回
		return *this;
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

void print_vector_state(const char* name, const MyVector& vec) {
	std::cout << name << " -> "
		<< "Size: " << vec.size()
		<< ", Capacity: " << vec.capacity() << std::endl;
}

int main()
{
	// === 测试 1: 拷贝构造函数 ===
	std::cout << "========= 测试 1: 拷贝构造函数 =========" << std::endl;

	MyVector vec1;
	for (int i = 0; i < 3; ++i) {
		vec1.push_back(i * 10);
	};

	print_vector_state("vec1", vec1);

	MyVector vec2 = vec1; // 这里会调用拷贝构造函数
	print_vector_state("vec2 (从 vec1 拷贝而来)", vec2);

	// 验证是深拷贝：修改 vec1 不应影响 vec2
	std::cout << "\n修改 vec1..." << std::endl;
	vec1.push_back(99);
	print_vector_state("vec1 (修改后)", vec1);
	print_vector_state("vec2 (应保持不变)", vec2);


	// === 测试 2: 拷贝赋值运算符 ===
	std::cout << "\n========= 测试 2: 拷贝赋值运算符 =========" << std::endl;
	MyVector vec3;
	vec3.push_back(111);
	print_vector_state("vec3", vec3);

	vec2 = vec3; // 这里会调用拷贝赋值运算符
	print_vector_state("vec2 (被 vec3 赋值后)", vec2);


	// === 测试 3: 链式赋值 ===
	std::cout << "\n========= 测试 3: 链式赋值 =========" << std::endl;
	MyVector vec4, vec5;
	vec4 = vec5 = vec3; // 测试 operator= 是否正确返回 *this
	print_vector_state("vec4 (链式赋值后)", vec4);
	print_vector_state("vec5 (链式赋值后)", vec5);


	// === 测试 4: 自我赋值 ===
	std::cout << "\n========= 测试 4: 自我赋值 =========" << std::endl;
	print_vector_state("vec1 (自我赋值前)", vec1);
	vec1 = vec1; // 如果没有 if(this == &other) 检查，这里会崩溃
	print_vector_state("vec1 (自我赋值后)", vec1);
	std::cout << "\n自我赋值测试成功，程序未崩溃！" << std::endl;


	std::cout << "\n所有测试完成！" << std::endl;
	return 0;
}

