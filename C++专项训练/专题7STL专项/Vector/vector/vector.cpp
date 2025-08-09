
#include <iostream>
#include<vector>
int main()
{
    std::vector<int> my_vector;
    std::cout << "开始向vector添加20个整数" << std::endl;
    std::cout << "\n>>> 执行 my_vector.reserve(20); <<<\n\n";
    my_vector.reserve(20);
    for (int i = 0; i < 20; i++)
    {
        my_vector.push_back(i);
        std::cout << i << "\t" << my_vector.size() << "\t" << my_vector.capacity();
        std::cout<<"\n";
    }

    std::cout << "Hello World!\n";
}

