#include <stdio.h>
#include "bitarray.h"

int main(){
    int32_t array[10];

    cdsc_bitarray_set1(array, 167);

    printf("%d\n", array[5]);

    printf("%d\n", cdsc_bitarray_is0(array, 167));


    return 0;
}