#include <stdio.h>

int main() {
    int n;
    // 读取数的个数 n
    printf("请输入要排序的数的个数：");
    scanf("%d", &n);
    int arr[n];
    // 读取 n 个要排序的数
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // 冒泡排序，从小到大
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // 输出排序后的数
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}