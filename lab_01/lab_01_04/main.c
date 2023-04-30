#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

// Функция возвращает частное от целочисленного деления a на d
int del(int a, int d, int *q, int *p)
{
    while (a - *q * d >= d)
        *q += 1;
    *p = a - *q * d;
    return OK;
}

int main(void)
{
    int a, d, q = 0, p = 0;
    printf("Input a, b: ");
    if (scanf("%d %d", &a, &d) != 2)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }
    if (a <= 0 || d <= 0)
    {
        printf("Numbers must be positive.\n");
        return ERR_RANGE;
    }
    del(a, d, &q, &p);
    printf("The answer is %d %d\n", q, p);
    return OK;
}
