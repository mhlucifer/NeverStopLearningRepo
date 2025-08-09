#include<stdio.h>
#include<stdint.h>

/*
 * 函数功能: 设置一个8位状态字节中的模式位 (Bits 6-4)
 * @param status: 当前的状态值
 * @param mode:   要设置的新模式值 (一个3位的数，如 0b101)
 * @return:       更新后的状态值
 */
uint8_t set_mode(uint8_t status, uint8_t mode) {

    // 第一步: 清空目标区域 (Bits 6-4)

    // 1. (0b111 << 4) 生成目标掩码 0b01110000
    // 2. ~ 生成清零模板 10001111
    // 3. &= 将 status 与清零模板做与操作，并将结果存回 status
    status &= ~(0b111 << 4);

    // 第二步: 将新模式值部署到清空后的区域
    // 1. (mode << 4) 将新模式值移动到正确位置
    // 2. |= 将移动后的新模式值，通过或操作，合并到 status 中
    status |= (mode << 4);

    // 返回最终修改后的状态
    return status;

}
int main()
{
	uint8_t register_a = 0b00000000;
	register_a |= 0b00010000;
    printf("结果是: %d\n", register_a);
    
}