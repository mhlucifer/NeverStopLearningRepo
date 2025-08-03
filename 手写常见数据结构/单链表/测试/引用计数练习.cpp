#include <iostream>
#include <memory>
#include <vector>

// (复用上面的 Entity 结构体)
struct Entity {
	Entity() { std::cout << "Entity created!" << std::endl; }
	~Entity() { std::cout << "Entity destroyed!" << std::endl; }
	void Greet() { std::cout << "Hello from Entity!" << std::endl; }
};
int main() {
    std::cout << "Entering main..." << std::endl;
    std::shared_ptr<Entity> shared_e; // 声明一个空的 shared_ptr
    {
        std::shared_ptr<Entity> ptr = std::make_shared<Entity>();
        // 1. 创建一个 shared_ptr，并用 make_shared 初始化
        std::cout << "第一个count是" << ptr.use_count() << std::endl;
        // 2. 打印它的 use_count()
        std::cout << "创建第二个拷贝ptr2" << std::endl;
        // 3. 创建第二个 shared_ptr，作为第一个的拷贝
        std::shared_ptr<Entity> ptr2= ptr;
        // 4. 再次打印第一个或第二个的 use_count()
         std::cout << "第二个count是" << ptr2.use_count() << std::endl;
        // 5. 将它们都放入一个 std::vector<std::shared_ptr<Entity>> 中
         std::vector<std::shared_ptr<Entity>> ptr_v = {};
         ptr_v.push_back(ptr);
         ptr_v.push_back(ptr2);
         std::cout << "总体值" << ptr.use_count() << std::endl;
         //vector等于拷贝了两个值进去，所以这里最后的结果应该是4
        // 6. 再次打印 use_count()
    } // 观察当作用域结束时，Entity 何时被销毁
    std::cout << "Leaving main..." << std::endl;
    return 0;
}