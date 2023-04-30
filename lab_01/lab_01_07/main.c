#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#define OK 0
#define ERR_IO 1

#define BYTE 255
#define BYTE_RANGE 8


// Упаковка четырех байт в беззнаковое
uint32_t pack(uint8_t b4, uint8_t b3, uint8_t b2, uint8_t b1)
{
    uint32_t pack_num = (((((b4 << BYTE_RANGE) + b3) << BYTE_RANGE) + b2) << BYTE_RANGE) + b1;
    return pack_num;
}

// Распкаовка байт из беззнакового
uint8_t unpack(uint32_t num, unsigned poz)
{
    uint8_t b = (num >> BYTE_RANGE * (poz - 1)) & BYTE;
    return b;
}


int main(void)
{
    uint8_t b1, b2, b3, b4;
    uint32_t num;
    printf("Input four unsigned bytes in decimal number system: ");
    if (scanf("%" SCNu8 "%" SCNu8 "%" SCNu8 "%" SCNu8, &b1, &b2, &b3, &b4) != 4)
    {
        printf("Error: wrong input\n");
        return ERR_IO;
    }


    num = pack(b1, b2, b3, b4);


//  Ввыод в двоичной сс
    size_t nbits = sizeof(num) * CHAR_BIT;
    uint32_t mask = 1, n;
    printf("Result: ");
    mask = mask << (nbits - 1);
    while (mask)
    {
        n = num & mask;
        mask = mask >> 1;

        if (n > 0)
            printf("1");
        else
            printf("0");
    }

    printf(" ");

    printf("%" PRIu8 " ", unpack(num, 4));
    printf("%" PRIu8 " ", unpack(num, 3));
    printf("%" PRIu8 " ", unpack(num, 2));
    printf("%" PRIu8 " ", unpack(num, 1));
    return OK;
}
