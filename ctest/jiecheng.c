#include <stdio.h>



int jiecheng(int n)
{
    if (n == 1)
        return 1;
    else
        return n * jiecheng(n - 1);
}

int main()
{
    int n;
    printf("������һ����������");
    scanf("%d", &n);
    printf("%d�Ľ׳���%d\n", n, jiecheng(n));
    return 0;
}
