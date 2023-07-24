#include "bitarray.h"

//Set the bit at index 'bit' to 1
void cdsc_bitarray_set1(int32_t array[], int bit){
    int index = bit/32;
    int pos = bit%32;

    int flag = 1;
    
    flag = flag << pos;

    array[index] = array[index] | flag;
}

//Set the bit at index 'bit' to 0
void cdsc_bitarray_set0(int32_t array[], int bit){
    int index = bit/32;
    int pos = bit%32;

    int flag = 1;
    
    flag = flag << pos;

    array[index] = array[index] & ~flag;
}

// Check if the bit at index 'bit' is 1
int cdsc_bitarray_is1(int32_t array[], int bit){
    int index = bit/32;
    int pos = bit%32;

    return (array[index] & (1 << pos)) != 0;
}


// Check if the bit at index 'bit' is 0
int cdsc_bitarray_is0(int32_t array[], int bit){
    int index = bit/32;
    int pos = bit%32;

    return (array[index] & (1 << pos)) == 0;
}