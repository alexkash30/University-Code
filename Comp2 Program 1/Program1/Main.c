/*
 
 */

#include <stdio.h>
#include "bit_flags.h"

void display_32_flags_as_array(BIT_FLAGS hBit_flags) {

	for (int i = 0; i < 32; i++) {
		if (i > 0 && i % 4 == 0) {
			printf(" ");
		}
		printf("%d", bit_flags_check_flag(hBit_flags, i));
	}
	printf("\n");
}


int main(int argc, const char* argv[]) {
    int userInput;
    BIT_FLAGS x;

    scanf("%d", &userInput);

    x = bit_flags_init_number_of_bits(userInput);

    printf("Set: %d %d %d\n", bit_flags_set_flag(x, 3), bit_flags_set_flag(x, 5), bit_flags_set_flag(x, 0));
    printf("Size: %d\n", bit_flags_get_size(x));
    printf("Cap: %d\n", bit_flags_get_capacity(x));
    printf("%d %d\n\n", bit_flags_check_flag(x, 3), bit_flags_check_flag(x, 0));

    printf("clear: %d %d %d\n", bit_flags_unset_flag(x, 3), bit_flags_unset_flag(x, 10), bit_flags_unset_flag(x, 5));
    printf("size: %d\n", bit_flags_get_size(x));
    printf("capacity: %d\n", bit_flags_get_capacity(x));
    printf("check: %d %d\n\n", bit_flags_check_flag(x, 3), bit_flags_check_flag(x, 0));

    bit_flags_destroy(&x);

    return 0;
}