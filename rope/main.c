#include<stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include "rope.h"

int main() {
	rope *r = cdsc_rope_init();
	cdsc_rope_nuke(r);
    return 0;
}
