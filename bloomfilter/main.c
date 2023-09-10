#include <stdio.h>
#include "bloomfilter.h"
#include <string.h>
#include <time.h>
#define ASCII_START 32
#define ASCII_END 126

char* randstring(int size) {
    int i;
    char *res = malloc(size + 1);
    for(i = 0; i < size; i++) {
        res[i] = (char) (rand()%(ASCII_END-ASCII_START))+ASCII_START;
    }
    res[i] = '\0';
    return res;
}

int main(){
    srand(time(0));
    struct cdsc_bloomfilter *filter = cdsc_bloomfilter_create(200, 0.01);
    printf("HASH FUNCTIONS: %d\n", filter->numhfuncs);
    printf("SIZE (bits): %d\n", filter->size);

    //cdsc_bloomfilter_add(filter, str, strlen(str));
    for (int i = 0; i < 200; i++){
        char* s = randstring(10);
        cdsc_bloomfilter_add(filter, s, strlen(s));
        free(s);
    }


    int ones = 0;
    int zeroes = 0;

    for (int i = 0; i < 200; i++){
        char* s = randstring(24);
        int res = cdsc_bloomfilter_check(filter, s, strlen(s));
        free(s);
        //printf("%s: %d\n", s, res);

        if (res){
            ones++;
        }else{
            zeroes++;
        }

    }

    printf("FALSE POSITIVES: %d\n", ones);
    printf("CORRECT: %d\n", zeroes);
    double p = (double)ones/(ones + zeroes);
    printf("FALSE POSITIVE RATIO: %f\%\n",p*100);
    cdsc_bloomfilter_nuke(filter);
    return 0;
}