#ifndef HASHSET_H
#define HASHSET_H

#include <stdio.h>
#include "my_string.h"

typedef void* HASH_SET;
// Initializes a new hash set that uses the given comparison function to order items
// postcondition:
// Returns a handle to the new hash set or NULL if memory allocation fails
HASH_SET hashset_init();
// precondition: a handle to a valid hash set object
// postcondition: The memory for the object refered to by the handle is freed and the handle is set to NULL
void hashset_destroy(HASH_SET* phHashSet);
// Precondition: a handle to a valid hash set object
// postcondition: returns the number of unique objects stored inside the set
int hashset_get_size(HASH_SET hHashSet);
// Precondition:
// hHashSet is a handle to a valid hash set object
// hStr is a handle to a valid string object
// Postcondition:
// The string will be added to the set if it is not already there
// returns SUCCESS if the insertion succeeded and FAILURE if it does not
// (either because the item is already in the set or because of memory allocation fails)
// The memory of the set will be independent of the provided string
Status hashset_insert(HASH_SET hHashSet, MY_STRING hStr);
// Precondition:
// hHashSet is a handle to a valid hash set object
// hStr is a handle to a valid string object
// Postcondition:
// The string will be removed from the set if it is there
// Afterwards, the string will no longer be in the set
// returns SUCCESS if the string was removed and FAILURE if it was not
// (because the item was not in the set)
Status hashset_remove(HASH_SET hHashSet, MY_STRING hStr);
// Precondition:
// hHashSet is a handle to a valid hash set object
// hStr is a handle to a valid string object
// Postcondition:
// Returns true if the item is in the set and false if it is not
bool hashset_contains(HASH_SET hHashSet, MY_STRING hStr);
// Counts how many unique words are in a given file
// Precondition:
// fp: A valid handle to a file containing words
// ignoreCase: whether words with the same letters but different cases are considered the same
// Postcondition:
// The number of unique words there are in the file
int unique_words(FILE* fp);

#endif