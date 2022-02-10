

/*
Author: Alex Kashian
Date: 2/4
Effort: 10 mins
Purpose: work with bitwise operators and unsigned ints
 */
#include <stdio.h>

int main(int argc, const char* argv[]) {
    unsigned int x = 1;

    for (int i = 0; x != 0; i++) {
        printf("%d: %u\n",i,x);
        x = x << 1;
    }

    return 0;
}