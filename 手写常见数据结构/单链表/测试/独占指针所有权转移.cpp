#include <iostream>
#include <memory>

struct Entity {
    Entity() { std::cout << "Entity created!" << std::endl; }
    ~Entity() { std::cout << "Entity destroyed!" << std::endl; }
    void Greet() { std::cout << "Hello from Entity!" << std::endl; }
};

// TODO: 实现这个函数
// 这个函数应该创建一个 Entity 的 unique_ptr 并返回它
std::unique_ptr<Entity> create_entity() {
    std::cout << "创建实体" << std::endl;
	return std::make_unique<Entity>();
}

int main() {
    std::cout << "Entering main..." << std::endl;
    {
		// 在这里调用 create_entity() 函数
        std::unique_ptr<Entity> ptr = create_entity();
        // 调用 create_entity() 来获取 unique_ptr
        // 并观察它在离开作用域时，Entity 是否被自动销毁
        if(ptr)
		ptr->Greet();
    }
    std::cout << "Leaving main..." << std::endl;
    return 0;
}