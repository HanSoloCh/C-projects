#include <stdio.h>
#define OK 0

int main(void)
{
    double v_1, v_2, t_1, t_2, t_new;
    printf("Input v_1, t_1 and v_2, t_2: ");
    scanf("%lf %lf %lf %lf", &v_1, &t_1, &v_2, &t_2);

    t_new = (v_1 * t_1 + v_2 * t_2) / (v_1 + v_2);
    printf("New volume and new temperature are %.6lf , %.6lf", v_1 + v_2, t_new);
    return OK;
}