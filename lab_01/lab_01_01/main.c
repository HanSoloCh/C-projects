#include <stdio.h>
#include <math.h>

#define M_RAD (3.1415926535 / 180)
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

int main(void)
{
    double a, b, fi, h, t, s;

    printf("Input a, b and fi: ");
    if (scanf("%lf%lf%lf", &a, &b, &fi) != 3)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }
    if (a <= 0 || b <= 0 || fi <= 0 || fi > 90)
    {
        printf("Values have wrong range.\n");
        return ERR_RANGE;
    }
    if (a > b)
        t = (a - b) / 2;
    else
        t = (b - a) / 2;

    h = tan(fi * M_RAD) * t;

    s = (a + b) / 2 * h;
    printf("S = %.6lf\n", s);
    return OK;
}