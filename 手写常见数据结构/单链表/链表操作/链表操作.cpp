// 链表操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//单链表每个节点只能找到下一个，无法回退到上一个
#include <iostream>
struct Node
{
    Node(int data = 0) :data_(data), next_(nullptr) {};
    int data_;
    Node* next_;
};
class Clink
{
    Clink() {
        //给head初始化指向头结点
        head_ = new Node();
    }

    ~Clink()
    {
        //节点的释放
    }
public:
    //尾插法
    void InsertTail(int val)
    {

    }
private:
    Node* head_; //指向链表头结点
};
int main()
{
    std::cout << "Hello World!\n";
}
