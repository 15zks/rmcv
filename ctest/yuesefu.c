#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 查找最小的m值
int findMinM(int k) {
    int total = 2 * k;  // 总人数：k个好人 + k个坏人
    int m = 1;          // 从m=1开始尝试
    
    while (1) {
        // 创建人群数组：0表示好人，1表示坏人
        int* people = (int*)malloc(total * sizeof(int));
        for (int i = 0; i < k; i++) {
            people[i] = 0;  // 前k个是好人
        }
        for (int i = k; i < total; i++) {
            people[i] = 1;  // 后k个是坏人
        }
        
        int currentSize = total;  // 当前剩余人数
        int index = 0;            // 当前起始索引
        int badCount = 0;         // 已淘汰的坏人数量
        int valid = 1;            // 标记当前m是否有效
        
        while (badCount < k) {
            // 计算下一个要淘汰的索引
            index = (index + m - 1) % currentSize;
            
            // 检查被淘汰的是好人还是坏人
            if (people[index] == 0) {
                // 淘汰了好人，当前m无效
                valid = 0;
                break;
            } else {
                // 淘汰了坏人，计数加1
                badCount++;
            }
            
            // 移除被淘汰的人（将后面的元素前移）
            for (int i = index; i < currentSize - 1; i++) {
                people[i] = people[i + 1];
            }
            currentSize--;
        }
        
        // 释放内存
        free(people);
        
        // 如果所有坏人都被淘汰且好人未被淘汰，返回当前m
        if (valid && badCount == k) {
            return m;
        }
        
        // 尝试下一个m值
        m++;
    }
}

int main() {
    int k;
    printf("请输入k值：");
    scanf("%d", &k);
    
    int result = findMinM(k);
    printf("最小的m值是：%d\n", result);
    
    return 0;
}
    