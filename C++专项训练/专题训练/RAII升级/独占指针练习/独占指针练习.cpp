#include <iostream>
class Engine
{
public:
    Engine()
    {
        std::cout << "构造函数" << std::endl;
    }

    ~Engine()
    {
        std::cout << "析构函数" << std::endl;
    }

    void start() {
        std::cout << "Engine 启动 (Engine started)" << std::endl;
    }

    std::unique_ptr<Engine> createEngine() const
    {
        return std::make_unique<Engine>();
    }


};

void takeOwnership(std::unique_ptr<Engine> p) 
{
    std::cout << "函数 takeOwnership 已获得所有权 (Function takeOwnership has taken ownership)\n";
    p->start(); // 我们可以使用这个对象
    std::cout << "函数 takeOwnership 即将结束 (Function takeOwnership is about to end)\n";
}


int main()
{
    Engine e;
    std::unique_ptr<Engine> rece = e.createEngine();
    std::cout << "\n--- 准备转移所有权 ---\n";
    takeOwnership(std::move(rece));
    std::cout << "--- 所有权已转移 ---\n\n";
    if (!rece) {
        std::cout << "main 函数中，enginePtr 现在是 nullptr。(正确！)\n";
    }
    std::cout << "\n--- main 函数即将结束 ---\n";
    
    return 0;

}

