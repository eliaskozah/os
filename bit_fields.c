#include <stdio.h>
#include <stdint.h>

uint64_t array_of_bits = 0;

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)   //set a particular bit in a bit field to 1
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N) //clear a particular bit in a bit field to 0
#define IS_BIT_SET(BF, N) (BF >> N) & 0x1



int main() {
    SET_BIT(array_of_bits, 0);
    SET_BIT(array_of_bits, 3);
    SET_BIT(array_of_bits, 1);
    SET_BIT(array_of_bits, 5);
    SET_BIT(array_of_bits, 54);
    SET_BIT(array_of_bits, 20);
    CLR_BIT(array_of_bits, 0);

    printf("bit array %b \n", array_of_bits);
    for (int i = 63; i >= 0; i--) {
        if (IS_BIT_SET(array_of_bits, i))
            printf("+");
            else
            printf("-");
    }
    printf("\n");
    return 0;
}