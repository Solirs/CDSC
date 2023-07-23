#ifndef BLOOMFILTER_
#define BLOOMFILTER_

#include<stdlib.h>
#include "../bitarray/bitarray.h"

typedef int (*func_type)(void*);

struct cdsc_bloomfilter{
    int size;
    int32_t *bitarray;
    int numhfuncs;
    func_type hashfuncs[255];
};

struct cdsc_bloomfilter* cdsc_bloomfilter_create(int size);
void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf);
void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data);
int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data);
void cdsc_bloomfilter_addhashfun(struct cdsc_bloomfilter* bf, int (*hashfun)(void*));
#endif