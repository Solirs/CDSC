#include <stdio.h>
#include "bitarray.h"

int main(){
    int32_t array[10];

    cdsc_bitarray_set1(array, 1);

    printf("%d\n", array[0]);


    cdsc_bitarray_set0(array, 1);

    printf("%d\n", array[0]);

    return 0;
}