#include <stdio.h>
#include <stdlib.h>

// ����쳲��������е�a����
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
    printf("������Ҫ�������ֵ����: ");
    scanf("%d", &n);
    
    // ����һ���ܴ洢n������������
    int *results = (int *)malloc(n * sizeof(int));
    if (results == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return 1;
    }
    
    // �������벢���㣬�洢��������
    for (int i = 0; i < n; i++) {
        int a;
        printf("�������%d����ֵ: ", i + 1);
        scanf("%d", &a);
        
        // ����쳲����������洢������
        results[i] = fibonacci(a);
    }
    
    // ��������еĽ��
    printf("\n����������: [");
    for (int i = 0; i < n; i++) {
        printf("%d", results[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // �ͷŶ�̬������ڴ�
    free(results);
    return 0;
}
