#include <iostream>
#include<vector>
class GameCharacter
{
public:
    GameCharacter()
    {
        std::cout << "构造函数" << std::endl;
    }
    ~GameCharacter()
    {
        std::cout << "析构函数" << std::endl;
    }
};
int main()
{
    // 使用 std::make_shared 创建一个角色 p_hero
    auto p_hero = std::make_shared<GameCharacter>();
    std::cout << "当前引用计数: " << p_hero.use_count() << std::endl; // 应该是 1
    // 创建一个团队
    std::vector<std::shared_ptr<GameCharacter>> team;
    team.push_back(p_hero); // 复制了一份，团队也拥有了英雄
    std::cout << "加入团队后，引用计数: " << p_hero.use_count() << std::endl; // 应该是 2

    // 创建一个搭档指针，也指向这个英雄
    std::shared_ptr<GameCharacter> p_partner = p_hero; // 又复制了一份
    std::cout << "有了搭档后，引用计数: " << p_partner.use_count() << std::endl; // 应该是 3
    // 搭档指针任务完成，重置它
    p_partner.reset();
    std::cout << "搭档离开后，引用计数: " << p_hero.use_count() << std::endl; // 应该是 2
    // 注意：此时 GameCharacter 对象依然存活！
    // 团队解散
    team.clear();
    std::cout << "团队解散后，引用计数: " << p_hero.use_count() << std::endl; // 应该是 1

    // 最初的 p_hero 指针也任务完成
    p_hero.reset();
    std::cout << "所有指针都离开后，对象应该已被析构" << std::endl;
    // 观察此时是否打印了 GameCharacter 的析构函数信息

}

