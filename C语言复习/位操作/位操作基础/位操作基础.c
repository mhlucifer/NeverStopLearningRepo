#include <stdio.h>

// 为了方便观察，我们写一个函数来打印二进制表示
void print_binary(unsigned char num) {
    printf(" (二进制: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf(")\n");
}

int main() {
    // 初始状态：设备关闭，所有位为0
    unsigned char device_status = 0;
    printf("初始状态: %d", device_status);
    print_binary(device_status);

    // 任务1: 开启设备电源 (将 bit 0 置为 1)
    // 使用“或”操作。1 << 0 表示一个只有bit 0为1的数 (00000001)
    printf("\n[操作] 开启电源...\n");
    device_status = device_status | (1 << 0);
    printf("当前状态: %d", device_status);
    print_binary(device_status);

    // 任务2: 设置设备为就绪状态 (将 bit 1 置为 1)
    printf("\n[操作] 设置为就绪...\n");
    device_status = device_status | (1 << 1);
    printf("当前状态: %d", device_status);
    print_binary(device_status);

    // 任务3: 检查电源是否开启 (检查 bit 0 是否为 1)
    // 使用“与”操作。如果结果不为0，则该位为1
    printf("\n[检查] 电源是否开启？\n");
    if ((device_status & (1 << 0)) != 0) {
        printf("结果: 电源已开启。\n");
    }
    else {
        printf("结果: 电源已关闭。\n");
    }

    // 任务4: 设置工作模式为 C (10) (设置 bit 4 为 1, bit 3 为 0)
    // 这是一个复合操作：
    // a. 先将 bit 4 置 1: device_status | (1 << 4)
    // b. 再将 bit 3 清 0: ... & ~(1 << 3)
    printf("\n[操作] 设置工作模式为 C (bit4=1, bit3=0)...\n");
    device_status = (device_status | (1 << 4)) & ~(1 << 3);
    printf("当前状态: %d", device_status);
    print_binary(device_status);

    // 任务5: 翻转错误标志位 (翻转 bit 2)
    // 使用“异或”操作
    printf("\n[操作] 模拟一次错误，翻转错误标志位...\n");
    device_status = device_status ^ (1 << 2);
    printf("当前状态: %d", device_status);
    print_binary(device_status);
    printf("[操作] 错误已处理，再次翻转错误标志位...\n");
    device_status = device_status ^ (1 << 2);
    printf("当前状态: %d", device_status);
    print_binary(device_status);

    // 任务6: 关闭电源 (将 bit 0 清零)
    // 使用“与”和“取反”
    printf("\n[操作] 关闭电源...\n");
    device_status = device_status & ~(1 << 0);
    printf("当前状态: %d", device_status);
    print_binary(device_status);

    return 0;
}
