#ifndef BLOOMFILTER_
#define BLOOMFILTER_

#include<stdlib.h>
#include <math.h>
#include "../bitarray/bitarray.h"

typedef unsigned int (*func_type)();

struct cdsc_bloomfilter{

    // Size of the bit array
    unsigned int size;

    // Bit array
    int32_t *bitarray;

    // The number of hash functions at our disposal
    unsigned int numhfuncs;

    // List of all hashfunctions
    func_type hashfunc;
};

struct cdsc_bloomfilter* cdsc_bloomfilter_create(int elements, double fpr);
void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf);
void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data, int32_t len);
int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data, int32_t len);
void cdsc_bloomfilter_sethashfun(struct cdsc_bloomfilter* bf, unsigned int (*hashfun)());
#endif