#include <stdio.h>
#include <math.h>


#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_MEMORY 3

#define EPS 0.000001

//  Расчет суммы  последоватильности при заданном x с точностью до eps
double func(double x, double eps)
{
    double x_n = x;
    double s = 0;
    int n = 0;
    while (fabs(x_n) >= eps)
    {
        n++;
        s += x_n;
        x_n = - (x_n * x * x) / ((2 * n + 1) * (2 * n));
    }
    return s;
}

int main(void)
{
    double x, eps;
    double abs_err, rel_err;
    double s_x, f_x;
    printf("Input x and eps: ");
    if (scanf("%lf %lf", &x, &eps) != 2)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }
    if (eps > 1 || eps <= 0)
    {
        printf("Eps must be from 0 to 1\n");
        return ERR_RANGE;
    }
    s_x = func(x, eps);
    f_x = sin(x);
    if (-EPS < f_x && f_x < EPS)
    {
        printf("The function is zero\n");
        return ERR_MEMORY;
    }

    rel_err = fabs((f_x - s_x) / f_x);
    abs_err = fabs(f_x - s_x);

    printf("The answer: %lf , %lf , %lf , %lf\n", s_x, f_x, abs_err, rel_err);

    return OK;
}
