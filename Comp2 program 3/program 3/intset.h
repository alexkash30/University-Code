#pragma once
#ifndef INTSET_H
#define INTSET_H

enum status { FAILURE, SUCCESS };
typedef enum status Status;

typedef void* BIT_FLAGS;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);
void bit_flags_destroy(BIT_FLAGS* phBit_flags);
int bit_flags_get_size(BIT_FLAGS hBit_flags);

#endif
