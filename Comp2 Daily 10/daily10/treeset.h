#ifndef TREESET_H
#define TREESET_H
#include <stdio.h>
#include <stdbool.h>
#include "my_string.h"
typedef void* TREE_SET;

// Defines a signature for comparison functions
// precondition: left and right are handles to valid My_string objects
// postcondition:
// returns an integer that is
// <0 if left comes first in this ordering
// >0 if right comes first in this ordering
// ==0 if they are equal
typedef int (*CompareFP)(MY_STRING left, MY_STRING right);
// Initializes a new tree set that uses the given comparison function to order items
// precondition: A comparison function for comparing two items
// postcondition:
// Returns a handle to the new tree set or NULL if memory allocation fails
TREE_SET treeset_init(CompareFP compare);
// precondition: a handle to a valid tree set object
// postcondition: The memory for the object refered to by the handle is freed and the handle is setto NULL
void treeset_destroy(TREE_SET* phTreeSet);
// Precondition: a handle to a valid tree set object
// postcondition: returns the number of unique objects stored inside the set
int treeset_get_size(TREE_SET hTreeSet);
// Precondition: a handle to a valid tree set object
// postcondition: returns the height of the tree
// The empty tree has height -1 and each level adds 1 to the height
int treeset_get_height(TREE_SET hTreeSet);
// Precondition:
// hTreeSet is a handle to a valid tree set object
// hStr is a handle to a valid string object
// Postcondition:
// The string will be added to the set if it is not already there
// returns SUCCESS if the insertion succeeded and FAILURE if it does not
// (either because the item is already in the set or because of memory allocation fails)
// The memory of the set will be independent of the provided string
Status treeset_insert(TREE_SET hTreeSet, MY_STRING hStr);
// Precondition:
// hTreeSet is a handle to a valid tree set object
// hStr is a handle to a valid string object
// Postcondition:
// The string will be removed from the set if it is there
// Afterwards, the string will no longer be in the set
// returns SUCCESS if the string was removed and FAILURE if it was not
// (because the item was not in the set)
Status treeset_remove(TREE_SET hTreeSet, MY_STRING hStr);
// Precondition:
// hTreeSet is a handle to a valid tree set object
// hStr is a handle to a valid string object
// Postcondition:
// Returns true if the item is in the set and false if it is not
Boolean treeset_contains(TREE_SET hTreeSet, MY_STRING hStr);
// Precondition: a handle to a valid tree set object
// Postcondition:
// Returns a handle to the minimum item according to the comparison function
// or NULL if the set is empty
MY_STRING treeset_first(TREE_SET hTreeSet);
// Precondition: a handle to a valid tree set object
// Postcondition:
// Returns a handle to the maximum item according to the comparison function
// or NULL if the set is empty
MY_STRING treeset_last(TREE_SET hTreeSet);
// Counts how many unique words are in a given file
// Precondition:
// fp: A valid handle to a file containing words
// ignoreCase: whether words with the same letters but different cases are considered the same
// Postcondition:
// The number of unique words there are in the file
int unique_words(FILE* fp, bool ignoreCase);
//Used to test my contains funciton.
void print_contains(TREE_SET hTreeSet, MY_STRING hStr);


#endif