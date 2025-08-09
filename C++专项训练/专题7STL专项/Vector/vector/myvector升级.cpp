#include <iostream>


class MyVector
{
private:
	int* m_data;
	size_t m_size;
	size_t m_capacity;
	


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


	T& operator[] (size_t index)
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

};

void print_vector_state(const char* name, const MyVector& vec) {
	std::cout << name << " -> "
		<< "Size: " << vec.size()
		<< ", Capacity: " << vec.capacity() << std::endl;
}

int main()
{
	// === 测试 1: 观察 push_back 导致的自动扩容 ===
	std::cout << "========= 测试 1: 自动扩容 =========" << std::endl;
	MyVector vec_auto;
	print_vector_state("vec_auto (初始)", vec_auto);
	for (int i = 0; i < 10; ++i) {
		vec_auto.push_back(i);
		std::cout << "push_back(" << i << ") 后: ";
		print_vector_state("", vec_auto);
	}

	// === 测试 2: 验证 public reserve 的效果 ===
	std::cout << "\n========= 测试 2: 主动 Reserve =========" << std::endl;
	MyVector vec_manual;
	print_vector_state("vec_manual (初始)", vec_manual);

	std::cout << "\n执行 reserve(20) ..." << std::endl;
	vec_manual.reserve(20); // 您的 reserve 需要是 public 才能这样调用
	print_vector_state("vec_manual (reserve后)", vec_manual);

	std::cout << "\n连续 push_back 10次..." << std::endl;
	for (int i = 0; i < 10; ++i) {
		vec_manual.push_back(i);
	}
	print_vector_state("vec_manual (10次push_back后)", vec_manual);
	std::cout << "--> 观察: Capacity 在此期间应保持不变。\n" << std::endl;

	std::cout << "验证程序结束。" << std::endl;
	return 0;
}

