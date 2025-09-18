#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������С��mֵ
int findMinM(int k) {
    int total = 2 * k;  // ��������k������ + k������
    int m = 1;          // ��m=1��ʼ����
    
    while (1) {
        // ������Ⱥ���飺0��ʾ���ˣ�1��ʾ����
        int* people = (int*)malloc(total * sizeof(int));
        for (int i = 0; i < k; i++) {
            people[i] = 0;  // ǰk���Ǻ���
        }
        for (int i = k; i < total; i++) {
            people[i] = 1;  // ��k���ǻ���
        }
        
        int currentSize = total;  // ��ǰʣ������
        int index = 0;            // ��ǰ��ʼ����
        int badCount = 0;         // ����̭�Ļ�������
        int valid = 1;            // ��ǵ�ǰm�Ƿ���Ч
        
        while (badCount < k) {
            // ������һ��Ҫ��̭������
            index = (index + m - 1) % currentSize;
            
            // ��鱻��̭���Ǻ��˻��ǻ���
            if (people[index] == 0) {
                // ��̭�˺��ˣ���ǰm��Ч
                valid = 0;
                break;
            } else {
                // ��̭�˻��ˣ�������1
                badCount++;
            }
            
            // �Ƴ�����̭���ˣ��������Ԫ��ǰ�ƣ�
            for (int i = index; i < currentSize - 1; i++) {
                people[i] = people[i + 1];
            }
            currentSize--;
        }
        
        // �ͷ��ڴ�
        free(people);
        
        // ������л��˶�����̭�Һ���δ����̭�����ص�ǰm
        if (valid && badCount == k) {
            return m;
        }
        
        // ������һ��mֵ
        m++;
    }
}

int main() {
    int k;
    printf("������kֵ��");
    scanf("%d", &k);
    
    int result = findMinM(k);
    printf("��С��mֵ�ǣ�%d\n", result);
    
    return 0;
}
    