#include <stdio.h>

int main() {
    int n;
    // ��ȡ���ĸ��� n
    printf("������Ҫ��������ĸ�����");
    scanf("%d", &n);
    int arr[n];
    // ��ȡ n ��Ҫ�������
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // ð�����򣬴�С����
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // �����������
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}