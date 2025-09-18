#include <stdio.h>
#include <math.h>

// 判断一个数是否为质数
int is_prime(int num) {
    if (num < 2) {
        return 0; // 不是质数
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // 不是质数
        }
    }
    return 1; // 是质数
}

int main() {
    int L;
    printf("请输入正整数L: ");
    scanf("%d", &L);
    
    // 定义数组存储符合条件的质数（假设最多不超过1000个，可根据需要调整）
    int primes[1000];
    int count = 0; // 记录质数的个数
    int current_sum = 0; // 当前质数的总和
    int num = 2; // 从2开始检查质数
    
    while (1) {
        if (is_prime(num)) {
            // 检查加上当前质数后是否超过L
            if (current_sum + num > L) {
                break;
            }
            // 将质数存入数组
            primes[count] = num;
            current_sum += num;
            count++;
        }
        num++;
    }
    
    // 输出所有符合条件的质数
    for (int i = 0; i < count; i++) {
        printf("%d\n", primes[i]);
    }
    // 输出质数的个数
    printf("%d\n", count);
    
    return 0;
}
    