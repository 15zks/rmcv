#include <stdio.h>

int main() {
    int n;
    printf("请输入楼梯的阶数: ");
    scanf("%d", &n);
    
    // 处理特殊情况
    if (n <= 2) {
        printf("上%d阶楼梯的走法有%d种\n", n, n);
        return 0;
    }
    
    // 动态规划迭代计算
    int a = 1;  // 上1阶楼梯的走法
    int b = 2;  // 上2阶楼梯的走法
    int result;
    
    // 从3阶开始计算，直到n阶
    for (int i = 3; i <= n; i++) {
        result = a + b;  // 第i阶的走法 = 第i-1阶 + 第i-2阶的走法之和
        a = b;           // 更新前两阶的走法数
        b = result;
    }
    
    printf("上%d阶楼梯的走法有%d种\n", n, result);
    return 0;
}
    