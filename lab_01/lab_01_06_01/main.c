#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define ERR_TRIANGLE 3

#define EPS 0.0000001

// Функция для рассчета площади по координатам точек
double triangle(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
    double s;
    s = fabs(((x_b - x_a) * (y_c - y_a) - (x_c - x_a) * (y_b - y_a))) / 2.0;
    return s;
}

// Функция проверяет что точки не лежат на одной прямой, находя разницу между координатами данными по одной оси
int difference(double a, double b, double c)
{
    double difference_1 = fabs(a - b);
    double difference_2 = fabs(c - b);
    double difference_3 = fabs(a - c);
    if (difference_1 <= EPS && difference_2 <= EPS && difference_3 <= EPS)
        return ERR_TRIANGLE;
    else
        return OK;
}

// Проверка, что точки не лежат на одной оси по их координатам
int is_line(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
    if (difference(x_a, x_b, x_c) == ERR_TRIANGLE || difference(y_a, y_b, y_c) == ERR_TRIANGLE)
    {
        return ERR_TRIANGLE;
    }
    return OK;
}

// Нахождение длины стороны по координатам точек
double len_side(double x_1, double y_1, double x_2, double y_2)
{
    double side = sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
    return side;
}

// Проверка на существования треугольника по трем его сторонам
int is_triangle(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
    double a = len_side(x_a, y_a, x_b, y_b);
    double b = len_side(x_b, y_b, x_c, y_c);
    double c = len_side(x_a, y_a, x_c, y_c);
    if (a + b <= c || b + c <= a || a + c <= b)
        return ERR_TRIANGLE;
    return OK;
}

int main(void)
{
    double x_a, y_a, x_b, y_b, x_c, y_c;

    printf("Input coordinates of dot a: ");
    if (scanf("%lf %lf", &x_a, &y_a) != 2)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }
    printf("Input coordinates of dot b: ");
    if (scanf("%lf %lf", &x_b, &y_b) != 2)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }
    printf("Input coordinates of dot c: ");
    if (scanf("%lf %lf", &x_c, &y_c) != 2)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }

    if (is_line(x_a, y_a, x_b, y_b, x_c, y_c) == ERR_TRIANGLE)
    {
        printf("Dots place on the one line\n");
        return ERR_RANGE;
    }

    if (is_triangle(x_a, y_a, x_b, y_b, x_c, y_c) == ERR_TRIANGLE)
    {
        printf("Dots doesnt place the triangle\n");
        return ERR_TRIANGLE;
    }
    printf("S = %lf\n", triangle(x_a, y_a, x_b, y_b, x_c, y_c));
    return OK;
}
