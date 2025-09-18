#include <stdio.h>
#include <math.h>

// �ж�һ�����Ƿ�Ϊ����
int is_prime(int num) {
    if (num < 2) {
        return 0; // ��������
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // ��������
        }
    }
    return 1; // ������
}

int main() {
    int L;
    printf("������������L: ");
    scanf("%d", &L);
    
    // ��������洢����������������������಻����1000�����ɸ�����Ҫ������
    int primes[1000];
    int count = 0; // ��¼�����ĸ���
    int current_sum = 0; // ��ǰ�������ܺ�
    int num = 2; // ��2��ʼ�������
    
    while (1) {
        if (is_prime(num)) {
            // �����ϵ�ǰ�������Ƿ񳬹�L
            if (current_sum + num > L) {
                break;
            }
            // ��������������
            primes[count] = num;
            current_sum += num;
            count++;
        }
        num++;
    }
    
    // ������з�������������
    for (int i = 0; i < count; i++) {
        printf("%d\n", primes[i]);
    }
    // ��������ĸ���
    printf("%d\n", count);
    
    return 0;
}
    