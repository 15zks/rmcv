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
    printf("请输入一个正整数：");
    scanf("%d", &n);
    printf("%d的阶乘是%d\n", n, jiecheng(n));
    return 0;
}
