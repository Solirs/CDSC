#ifndef BLOOMFILTER_
#define BLOOMFILTER_

#include<stdlib.h>
#include "../bitarray/bitarray.h"

struct cdsc_bloomfilter{
    int size;
    int32_t *bitarray;
    int (*hashfuncs[255])(void*);

};

struct cdsc_bloomfilter* cdsc_bloomfilter_create(int size);
void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf);
void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data);
int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data);
#endif