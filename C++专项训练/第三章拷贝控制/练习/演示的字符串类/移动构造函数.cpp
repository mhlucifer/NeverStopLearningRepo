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


    // 【新增】移动构造函数
    // 参数是右值引用 MyClass&&
    DemoString(DemoString&& other) noexcept { // noexcept是性能优化的好习惯
        // 打印信息，以便我们观察
        std::cout << "调用[移动构造函数] from \"" << other.data_ << "\"" << std::endl;

        // 1. 【核心】直接“窃取”源对象的指针
        // 不需要new新内存，直接把other的data_指针拿过来给自己用
        data_ = other.data_;

        // 2. 【核心】将源对象“掏空”
        // 把other的指针设为nullptr，这样它的析构函数被调用时，就不会释放我们已经“窃取”过来的内存了
        other.data_ = nullptr;
    }

    // 【移动赋值运算符】
    DemoString& operator=(DemoString&& other) noexcept { // 注意参数是 &&
        std::cout << "调用[移动赋值运算符] from \"" << other.data_ << "\"" << std::endl;

        // 1. 检查自我赋值
        if (this != &other) {
            // 2. 释放当前对象已有的旧资源
            delete[] data_;

            // 3. 直接窃取 other 的资源
            data_ = other.data_;

            // 4. 将 other 掏空
            other.data_ = nullptr;
        }
        // 5. 返回自身引用
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

    std::cout << "\n>>> 创建 s1..." << std::endl;
    // std::move() 是一个工具，它能把一个左值（比如s2）强制转换成右值
    // 这样我们就能显式地触发移动构造函数来观察
    DemoString s2("Temporary");
    DemoString s1 = std::move(s2);

    std::cout << "\n>>> 移动后状态:" << std::endl;
    s1.print("s1");
    //s2.print("s2"); // 看看被“掏空”的s2是什么样子

    std::cout << "\n--- 场景结束 ---" << std::endl;
    return 0;
}