/***********************************************************
Computing II -- COMP.1020 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom,
providing an enriching learning experience for students, and as training as a practicing
computing professional upon graduation. This practice is manifested in the University's
Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and
adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be
dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help
is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner
consistent with this document, the course academic policy on the course website on Blackboard,
and the UMass Lowell academic code.
Author: Alex Kashian
Date: 3/17
Effort: 8 hours(way to much time)
Purpose: combing our understanding of opque objects and what we learned about bit flags. simplifying our code as well
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"


typedef struct bit_flags {
    int size;
    int capacity;
    int* data;
} Bit_flags;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {

    if (number_of_bits <= 0) {
        return NULL;
    }
    Bit_flags* pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    if (pBit_flags == NULL) {
        return NULL;
    }

 
    pBit_flags->size = number_of_bits;
    pBit_flags->capacity = number_of_bits / ((sizeof(int) * 8))+((number_of_bits % (sizeof(int) * 8)) != 0);
    pBit_flags->data = (int*)malloc(sizeof(int) * pBit_flags->capacity);

    if (pBit_flags->data == NULL) {

        free(pBit_flags);
        return NULL;
    }

    for (int i = 0; i < pBit_flags->capacity; i++) {
        pBit_flags->data[i] = 0;
    }

    return (BIT_FLAGS)pBit_flags;
}


Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) {

    Bit_flags* pBit_flag = (Bit_flags*)hBit_flags;
    int index = flag_position / ((sizeof(int) * 8));

    if (index >= pBit_flag->capacity) {
        int* temp = (int*)calloc((index + 1), sizeof(int));
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pBit_flag->capacity; i++) {
            temp[i] = pBit_flag->data[i];
        }
        free(pBit_flag->data);
        pBit_flag->data = temp;
        pBit_flag->capacity = (index + 1);
    }
    if (flag_position >= pBit_flag->size) {
        pBit_flag->size = flag_position + 1;
    }

    pBit_flag->data[index] |= (1 << flag_position % ((sizeof(int) * 8)));
    return SUCCESS;
}


Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {

    Bit_flags* pBit_flag = (Bit_flags*)hBit_flags;

    int index = flag_position / ((sizeof(int) * 8));

    if (index >= pBit_flag->capacity) {
        int* temp = (int*)calloc((index + 1), sizeof(int));
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pBit_flag->capacity; i++) {
            temp[i] = pBit_flag->data[i];
        }
        free(pBit_flag->data);
        pBit_flag->data = temp;
        pBit_flag->capacity = (index + 1);
    }

    if (flag_position >= pBit_flag->size) {
        pBit_flag->size = flag_position + 1;
    }

    pBit_flag->data[index] &= (~(1 << flag_position % ((sizeof(int) * 8))));

    return SUCCESS;
}


int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) {
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    int index = flag_position / ((sizeof(int) * 8));
    if (flag_position >= pBit_flags->size || flag_position < 0) {
        return -1;
    }
    return (pBit_flags->data[index] >> (flag_position % ((sizeof(int) * 8)))) & 1;
}


int bit_flags_get_size(BIT_FLAGS hBit_flags) {
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    return pBit_flags->size;
}


int bit_flags_get_capacity(BIT_FLAGS hBit_flags) {
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    return pBit_flags->capacity * ((sizeof(int) * 8));
}


void bit_flags_destroy(BIT_FLAGS* phBit_flags) {
    Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
    free(pBit_flags->data);
    free(pBit_flags);
    *phBit_flags = NULL;
}