#include <stdio.h>

int main() {
    int n;
    printf("������¥�ݵĽ���: ");
    scanf("%d", &n);
    
    // �����������
    if (n <= 2) {
        printf("��%d��¥�ݵ��߷���%d��\n", n, n);
        return 0;
    }
    
    // ��̬�滮��������
    int a = 1;  // ��1��¥�ݵ��߷�
    int b = 2;  // ��2��¥�ݵ��߷�
    int result;
    
    // ��3�׿�ʼ���㣬ֱ��n��
    for (int i = 3; i <= n; i++) {
        result = a + b;  // ��i�׵��߷� = ��i-1�� + ��i-2�׵��߷�֮��
        a = b;           // ����ǰ���׵��߷���
        b = result;
    }
    
    printf("��%d��¥�ݵ��߷���%d��\n", n, result);
    return 0;
}
    