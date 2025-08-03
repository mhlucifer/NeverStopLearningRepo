#include <iostream>
#include <cstring>

// DemoString 类和上次一样，包含了我们手写的拷贝构造函数
class DemoString {
public:
    // 1. 构造函数
    DemoString(const char* s = "") {
        std::cout << "调用[普通构造函数] for \"" << s << "\"" << std::endl;
        size_t n = strlen(s) + 1;
        data_ = new char[n];
        memcpy(data_, s, n);
    }

    // 2. 析构函数
    ~DemoString() {
        std::cout << "调用[析构函数] for \"" << (data_ ? data_ : "空指针") << "\"" << std::endl;
        delete[] data_;
        data_ = nullptr;
    }

    // 3. 拷贝构造函数
    DemoString(const DemoString& other) {
        std::cout << "调用[拷贝构造函数] from \"" << other.data_ << "\"" << std::endl;
        size_t n = strlen(other.data_) + 1;
        data_ = new char[n];
        memcpy(data_, other.data_, n);
    }


    // 【新增】拷贝赋值运算符
    DemoString& operator=(const DemoString& other) {
        // 打印信息，以便我们观察
        std::cout << "调用[拷贝赋值运算符] to copy from \"" << other.data_ << "\"" << std::endl;

        // 1. 检查自我赋值
        if (this == &other) {
            return *this; // 如果是 s1 = s1; 这样的操作，直接返回，避免后续操作出错
        }

        // 2. 释放当前对象已有的资源
        // 如果不释放，"Hello"这块内存就永远丢失了（内存泄漏）
        delete[] data_;

        // 3. 重新分配内存，并拷贝内容（深拷贝逻辑）
        size_t n = strlen(other.data_) + 1;
        data_ = new char[n];
        memcpy(data_, other.data_, n);

        // 4. 返回当前对象的引用，以支持链式赋值
        return *this;
    }


    // 打印函数
    void print(const char* name) const {
        std::cout << name << " -> 地址: " << (void*)data_ << ", 内容: " << data_ << std::endl;
    }

private:
    char* data_;
};


int main() {
    std::cout << "--- 场景开始 ---" << std::endl;
    {
        DemoString s1("Hello");
        DemoString s2("World");

        std::cout << "\n>>> 赋值前状态:" << std::endl;
        s1.print("s1");
        s2.print("s2");

        std::cout << "\n>>> 执行 s1 = s2; ..." << std::endl;
        s1 = s2; 

        std::cout << "\n>>> 赋值后状态:" << std::endl;
        s1.print("s1");
        s2.print("s2");

        std::cout << "\n>>> 即将离开作用域..." << std::endl;
    }
    std::cout << "\n--- 场景结束 ---" << std::endl;

    return 0;
}