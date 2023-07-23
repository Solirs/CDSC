#ifndef BLOOMFILTER_
#define BLOOMFILTER_

#include<stdlib.h>
#include "../bitarray/bitarray.h"

typedef unsigned int (*func_type)();

struct cdsc_bloomfilter{

    // Size of the bit array
    int size;

    // Bit array
    int32_t *bitarray;

    // The number of hash functions at our disposal
    int numhfuncs;

    // List of all hashfunctions
    func_type hashfuncs[255];
};

struct cdsc_bloomfilter* cdsc_bloomfilter_create(int size);
void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf);
void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data);
int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data);
void cdsc_bloomfilter_addhashfun(struct cdsc_bloomfilter* bf, unsigned int (*hashfun)());
#endif