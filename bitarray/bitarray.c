#include "bitarray.h"

void cdsc_bitarray_set1(int32_t array[], int bit){
    int index = bit/32;
    int pos = bit%32;

    int flag = 1;
    
    flag = flag << pos;

    array[index] = array[index] | flag;
}

void cdsc_bitarray_set0(int32_t array[], int bit){
    int index = bit/32;
    int pos = bit%32;

    int flag = 1;
    
    flag = flag << pos;

    array[index] = array[index] & ~flag;
}