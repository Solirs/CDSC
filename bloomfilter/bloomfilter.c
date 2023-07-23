#include "bloomfilter.h"

struct cdsc_bloomfilter* cdsc_bloomfilter_create(int size){
    struct cdsc_bloomfilter* ret = malloc(sizeof(struct cdsc_bloomfilter));
    ret->size = size;
    ret->bitarray = malloc(size/8 + 1);
    ret->numhfuncs = 0;
    return ret;
}

void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf){
    free(bf->bitarray);
    free(bf);
}

void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data){

    int i = 0;
    while (1){
        if (i == bf->numhfuncs){
            break;
        }
        cdsc_bitarray_set1(bf->bitarray, bf->hashfuncs[i](data));
        i++;
    }
}

int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data){
    int i = 0;
    while (1){
        if (i == bf->numhfuncs){
            return 1;
        }
        if (cdsc_bitarray_is1(bf->bitarray, bf->hashfuncs[i](data))){
            i++;
        }else{
            return 0;
        }
    }    
}

void cdsc_bloomfilter_addhashfun(struct cdsc_bloomfilter* bf, int (*hashfun)(void*)){
    int i = 0;
    while (1){
        if (i == bf->numhfuncs){
            bf->hashfuncs[i] = hashfun;
            bf->numhfuncs++;
            return;
        }else{
            i++;
        }
    }
}