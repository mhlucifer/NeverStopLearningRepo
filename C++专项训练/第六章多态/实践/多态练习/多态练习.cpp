#include <iostream>
#include <vector> // 使用标准vector来演示，您可以替换成MyVector

const double PI = 3.1415926535;

// === Shape.h ===
class Shape
{
public:
    // 返回面积，const表明此函数不修改对象状态
    virtual double area() const = 0;
    // 绘制图形，const表明此函数不修改对象状态
    virtual void draw() const = 0;

    // 虚析构函数，确保派生类资源能被正确释放
    virtual ~Shape() { std::cout << "Shape destroyed.\n"; }
};


// === Circle.h ===
class Circle : public Shape
{
public:
    // 构造函数，用于初始化核心属性
    Circle(double radius) : m_radius(radius) {}

    double area() const override
    {
        return PI * m_radius * m_radius;
    }

    void draw() const override
    {
        std::cout << "Drawing a Circle with radius " << m_radius << ".\n";
    }

    ~Circle() { std::cout << "Circle destroyed.\n"; }

private:
    double m_radius; // 核心属性
};

// === Square.h ===
class Square : public Shape
{
public:
    Square(double side) : m_side(side) {}

    double area() const override
    {
        return m_side * m_side;
    }

    void draw() const override
    {
        std::cout << "Drawing a Square with side " << m_side << ".\n";
    }

    ~Square() { std::cout << "Square destroyed.\n"; }

private:
    double m_side; // 核心属性
};

// === main.cpp ===
int main()
{
    // 使用容器管理多态对象是更常见的做法
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(10.0)); // 创建一个半径为10的圆
    shapes.push_back(new Square(5.0));  // 创建一个边长为5的正方形
    shapes.push_back(new Circle(2.5));

    // 多态地调用每个对象的函数
    for (const auto& shape_ptr : shapes)
    {
        shape_ptr->draw();
        std::cout << "Its area is: " << shape_ptr->area() << std::endl;
        std::cout << "-------------------\n";
    }

    // **至关重要：释放所有动态分配的内存**
    for (const auto& shape_ptr : shapes)
    {
        delete shape_ptr;
    }
    shapes.clear(); // 清空容器

    return 0;
}