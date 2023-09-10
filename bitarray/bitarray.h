#ifndef BITARRAY_
#define BITARRAY_

#include<stdlib.h>
#include <stdint.h>

void cdsc_bitarray_set1(int32_t array[], int bit);
void cdsc_bitarray_set0(int32_t array[], int bit);
int cdsc_bitarray_is1(int32_t array[], int bit);
int cdsc_bitarray_is0(int32_t array[], int bit);
#endif