#include<iostream>


template <typename T>
class MyUniquePtr {
private:
    T* m_ptr; // 独占的“王权”——指向资源的裸指针

public:
    // 构造函数：获取资源。explicit防止隐式转换。
    explicit MyUniquePtr(T* ptr = nullptr)
        : m_ptr(ptr) {
    }

    // 析构函数：释放资源。RAII的核心体现！
    ~MyUniquePtr() {
        delete m_ptr;
    }

    // 在 public 区域内，紧接着构造和析构函数之后，添加以下代码：
    // 禁止拷贝构造
    MyUniquePtr(const MyUniquePtr& other) = delete;
    // 禁止拷贝赋值
    MyUniquePtr& operator=(const MyUniquePtr& other) = delete;
    
    //移动构造函数
    MyUniquePtr(MyUniquePtr&& other) noexcept : m_ptr(other.m_ptr)
    {
        //原指针退位，放弃所有权
        other.m_ptr = nullptr;
    }

    MyUniquePtr& operator=(const MyUniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            //如果不是相等的，那么先释放自己的
            delete m_ptr;

            //窃取别人的
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }
    // 解引用运算符
    T& operator*() const
    {
        return *m_ptr;
    }

    // 箭头运算符
    T* operator->() const
    {
        return m_ptr;
    }
    // 获取裸指针
    T* get() const
    {
        return m_ptr;
    }

    // 释放所有权，并返回裸指针
    T* release() {
        T* temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    // 重置指针，销毁旧对象，获取新对象
    void reset(T* ptr = nullptr) {
        delete m_ptr;
        m_ptr = ptr;
    }
};

struct MyData {
    MyData() { std::cout << "MyData 被创建.\n"; }
    ~MyData() { std::cout << "MyData 被销毁.\n"; }
    void foo() { std::cout << "foo() 被调用.\n"; }
};

int main()
{
    // 测试1：基本RAII
    {
        MyUniquePtr<MyData> p1(new MyData());
        p1->foo();
    } // p1离开作用域，MyData应该被自动销毁

    // 测试2：移动语义
    MyUniquePtr<MyData> p2(new MyData());
    MyUniquePtr<MyData> p3 = std::move(p2); // 测试移动构造

    // 测试3：多态
    // MyUniquePtr<Shape> p_shape = MyUniquePtr<Circle>(new Circle(10.0));
    // p_shape->draw();
}