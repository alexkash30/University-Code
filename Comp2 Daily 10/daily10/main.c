#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>


#include "treeset.h"
#include "my_string.h"

int main(int argc, const char* argv[]){

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    FILE* fp = fopen("romeo.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    bool ignoreCase = false;
    int words = unique_words(fp, ignoreCase);
    printf("Number of unique words in \"romeo.txt\" is %d\n", words);

    fclose(fp);
    return 0;

}