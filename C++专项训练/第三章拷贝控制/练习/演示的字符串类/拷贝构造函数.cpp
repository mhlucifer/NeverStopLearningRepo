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

    // 打印函数
    void print(const char* name) const {
        std::cout << name << " -> 地址: " << (void*)data_ << ", 内容: " << data_ << std::endl;
    }

private:
    char* data_;
};


int main() 
{
    std::cout << "--- 场景开始 ---" << std::endl;
    {
        DemoString s1("Hello");
        DemoString s2("World");

        std::cout << "\n>>> 赋值前状态:" << std::endl;
        s1.print("s1");
        

    return 0;
}