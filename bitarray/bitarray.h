#ifndef BITARRAY_
#define BITARRAY_

#include<stdlib.h>
#include <stdint.h>

int32_t* cdsc_bitarray_create();
void cdsc_bitarray_set1(int32_t array[], int bit);
void cdsc_bitarray_set0(int32_t array[], int bit);
#endif