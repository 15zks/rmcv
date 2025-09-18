#include <stdio.h>
#include <stdlib.h>

// 计算斐波那契数列第a个数
int fibonacci(int a) {
    if (a == 1 || a == 2) {
        return 1;
    }
    int f1 = 1, f2 = 1, f3;
    for (int i = 3; i <= a; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f2;
}

int main() {
    int n;
    printf("请输入要计算的数值个数: ");
    scanf("%d", &n);
    
    // 创建一个能存储n个整数的数组
    int *results = (int *)malloc(n * sizeof(int));
    if (results == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }
    
    // 接收输入并计算，存储到数组中
    for (int i = 0; i < n; i++) {
        int a;
        printf("请输入第%d个数值: ", i + 1);
        scanf("%d", &a);
        
        // 计算斐波那契数并存储到数组
        results[i] = fibonacci(a);
    }
    
    // 输出数组中的结果
    printf("\n计算结果数组: [");
    for (int i = 0; i < n; i++) {
        printf("%d", results[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // 释放动态分配的内存
    free(results);
    return 0;
}
