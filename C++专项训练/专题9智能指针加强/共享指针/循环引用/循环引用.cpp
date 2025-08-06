#include <iostream>
class NodeB;
class NodeA
{
public:
    NodeA()
    {
        std::cout << "构造函数创建" << std::endl;
    }
    ~NodeA()
    {
        std::cout << "析构函数创建" << std::endl;
    }

    std::shared_ptr<NodeB> b;

};


class NodeB
{
public:
    NodeB()
    {
        std::cout << "构造函数创建" << std::endl;

    }
    ~NodeB()
    {
        std::cout << "析构函数创建" << std::endl;
    }

    std::weak_ptr<NodeA> a;
};
int main()
{
    
        auto a = std::make_shared<NodeA>();
        auto b = std::make_shared<NodeB>();
        a->b = b;
        b->a = a;
        std::cout << "A的引用计数: " << a.use_count() << std::endl; // 会是2
        std::cout << "B的引用计数: " << b.use_count() << std::endl; // 会是2
     // a 和 b 离开作用域，但它们互相拉着对方，析构函数不会被调用！
    std::cout << "僵局形成，对象无法被销毁。\n";
}

