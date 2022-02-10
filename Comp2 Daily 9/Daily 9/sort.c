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
Date: 3/24
Effort: 6 Hours 
Purpose: sort a text file full of strings 
***********************************************************/



#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

typedef int (*CompareFP)(MY_STRING left, MY_STRING right);

bool is_sorted(MY_STRING* array, int size, CompareFP compare)
{
    int index;
    for (index = 0; index < size - 1; index++) {
        if (compare(array[index], array[index + 1]) == 0)
            continue;
        if (compare(array[index], array[index + 1]) > 0)
            return false;
    }
    return true;
}

void sort(MY_STRING* array, int size, CompareFP compare) {
    sort_conversion(array, 0, size - 1, compare);
}

void sort_conversion(MY_STRING* array, int start, int end, CompareFP compare) {

    int start_point, end_point, pivot;
    MY_STRING hold;

    if (start < end)
    {
        pivot = start;
        start_point = start;
        end_point = end;

        while (start_point < end_point)
        {
            while (compare(array[start_point], array[pivot]) <= 0 && start_point < end)
                start_point++;
            while (compare(array[end_point], array[pivot]) > 0)
                end_point--;
            if (start_point < end_point)
            {
                hold = array[start_point];
                array[start_point] = array[end_point];
                array[end_point] = hold;
            }
        }

        hold = array[pivot];
        array[pivot] = array[end_point];
        array[end_point] = hold;
        sort_conversion(array, start, end_point - 1, compare);
        sort_conversion(array, end_point + 1, end, compare);
    }
}