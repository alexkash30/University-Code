
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


int main(int argc, const char* argv[]) {
    CompareFP compare = order_str_ignore_case;

    if (argc < 2) {
        printf("Usage: ./day9 [filename]\n");
        exit(0);
    }
    FILE* fp = fopen(argv[1], "r");

    if (!fp) {
        printf("Failed to open file %s\n", argv[1]);
        exit(1);
    }

    int capacity = 10;
    MY_STRING* array = (MY_STRING*)calloc(capacity, sizeof(MY_STRING));

    if (!array) {
        printf("Error allocating array\n");
        fclose(fp);
        exit(2);
    }

    printf("Reading from %s\n", argv[1]);
    int size = 0;
    MY_STRING str = my_string_init_default();
    if (!str) {
        printf("Error allocating string\n");
        fclose(fp);
        exit(2);
    }
    while (my_string_extraction(str, fp) == SUCCESS) {
        array[size] = str;
        my_string_insertion(str, stdout);
        size++;
        if (size >= capacity) {
            capacity *= 2;
            MY_STRING newarray = (MY_STRING*)realloc(array, capacity * sizeof(MY_STRING));
            if (!newarray) {
                printf("Error resizing array\n");
                free(array);
                fclose(fp);
                exit(2);
            }
            array = newarray;
        }
        str = my_string_init_default();
        if (!str) {
            printf("Error allocating string\n");
            fclose(fp);
            exit(2);
        }
    }

    printf("\n");
    printf("Compare: %d\n", is_sorted(array, size, compare));
    sort(array, size, compare);
    printf("Compare: %d\n", is_sorted(array, size, compare));

    for (int i = 0; i < size; i++) {
        my_string_insertion(array[i], stdout);
        printf("\n");
        my_string_destroy(&array[i]);
    }

    fclose(fp);
    return 0;
}
