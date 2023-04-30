#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

#define FLAT_FLOOR_QUAN 4
#define FLAT_ENT_QUAN 36

int main(void)
{
    int num, ent, floor;
    printf("Input number of the flat: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Wrong input\n");
        return ERR_IO;
    }
    if (num <= 0)
    {
        printf("Enter positive number\n");
        return ERR_RANGE;
    }
    ent = (num - 1) / FLAT_ENT_QUAN + 1;
    floor = (num - FLAT_ENT_QUAN * (ent - 1) - 1) / FLAT_FLOOR_QUAN + 1;
    printf("Flat number is located on the %d entrance on the %d floor\n", ent, floor);
    return OK;
}