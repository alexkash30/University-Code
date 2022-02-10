#ifndef SORT_H
#define SORT_H
#include "my_string.h"
#include <stdbool.h>


// Defines a signature for comparison functions
// precondition: left and right are handles to valid My_string objects
// postcondition:
// returns an integer that is
// <0 if left comes first in this ordering
// >0 if right comes first in this ordering
// ==0 if they are equal
typedef int (*CompareFP)(MY_STRING left, MY_STRING right);
// Determines if the list is sorted
// precondition:
// array is an array of valid MY_STRING handles
// size is the length of the array
// compare is a comparison function
// postcondition:
// returns true if the list is sorted under the given comparison function and false otherwise
bool is_sorted(MY_STRING* array, int size, CompareFP compare);
// Sorts the list
// precondition:
// array is an array of valid MY_STRING handles
// size is the length of the array
// compare is a comparison function
// postcondition:
// The elements of array will be reordered so that they are in increasing order under the given comparison function
void sort(MY_STRING* array, int size, CompareFP compare);

void sort_conversion(MY_STRING* array, int start, int end, CompareFP compare);

#endif
