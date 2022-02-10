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
Date: 4/22
Effort: 4 hours
Purpose: find the unique words in romeo and juliet using hashsets 
***********************************************************/

#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct hashnode{
    unsigned int hash;
    MY_STRING data;
    struct hashnode* next;
};
typedef struct hashnode HashNode;

const double MAX_LOAD_FACTOR = 0.5;

struct hashset {
    unsigned int size;
    unsigned int capacity;
    HashNode** table; // Array of node pointers
};
typedef struct hashset HashSet;

HASH_SET hashset_init() {
    HashSet* pSet = (HashSet*)malloc(sizeof(HashSet));
    if (pSet) {
        pSet->size = 0;
        pSet->capacity = 7;

        // Initialize to array of NULLs
        pSet->table = (HashNode**)calloc(pSet->capacity, sizeof(HashNode*));
        if (!pSet->table) {
            free(pSet);
            return NULL;
        }
    }
    return pSet;

}

void hashset_destroy(HASH_SET* phHashSet) {
    HashSet* pSet = (HashSet*)*phHashSet;
    // Loop over each row of the table
    for (unsigned int i = 0; i < pSet->capacity; i++) {
        // Loop over each item in the chain
        HashNode* pNode = pSet->table[i];
        while (pNode) {
            HashNode* pOld = pNode;
            pNode = pNode->next;
            my_string_destroy(&pOld->data);
            free(pOld);
        }
    }
    free(pSet->table);
    free(pSet);
    *phHashSet = NULL;

}

int hashset_get_size(HASH_SET hHashSet) {
    HashSet* pSet = (HashSet*)hHashSet;
    return pSet->size;
}

void resize(HashSet* pSet, int newCap){
    HashNode** newTable = (HashNode**)calloc(newCap, sizeof(HashNode*));

    if (newTable) {
        // Go through each spot of the old array
        for (unsigned int i = 0; i < pSet->capacity; i++) {
            HashNode* pNode = pSet->table[i];
            while (pNode) {
                HashNode* pOld = pNode;
                pNode = pNode->next;
                // And place it in the new table
                int index = pOld->hash % newCap;
                pOld->next = newTable[index];
                newTable[index] = pOld;
            }
        }

        // Update the table
        free(pSet->table);
        pSet->table = newTable;
        pSet->capacity = newCap;
    }
}


Status hashset_insert(HASH_SET hHashSet, MY_STRING hStr) {
    if (hashset_contains(hHashSet, hStr)) {
        return FAILURE; // Already contains item
    }
    HashSet* pSet = (HashSet*)hHashSet;
    unsigned int h = my_string_hash(hStr);
    unsigned int index = h % pSet->capacity;

    HashNode* pNode = (HashNode*)malloc(sizeof(HashNode));
    if (pNode) {
        pNode->data = NULL;
        my_string_assign(&pNode->data, hStr);
        pNode->hash = h;
        pNode->next = pSet->table[index];
        pSet->table[index] = pNode;
        pSet->size++;

        if (pSet->size > pSet->capacity * MAX_LOAD_FACTOR) {
            resize(pSet, pSet->capacity * 2 + 1);
        }

        return SUCCESS;
    }
    return FAILURE;
}

Status hashset_remove(HASH_SET hHashSet, MY_STRING hStr) {
    HashSet* pSet = (HashSet*)hHashSet;
    unsigned int h = my_string_hash(hStr);
    unsigned int index = h % pSet->capacity;

    for (HashNode** ppNode = &pSet->table[index];
        *ppNode != NULL;
        ppNode = &(*ppNode)->next) {
        HashNode* pNode = *ppNode;
        if (pNode->hash == h && my_string_equals(pNode->data, hStr) == TRUE) {
            *ppNode = pNode->next;
            my_string_destroy(&hStr);
            free(pNode);
            pSet->size--;

            if (pSet->size < pSet->capacity * MAX_LOAD_FACTOR / 4) {
                resize(pSet, pSet->capacity / 2);
            }

            return SUCCESS;
        }
    }

    return FAILURE;
}

bool hashset_contains(HASH_SET hHashSet, MY_STRING hStr) {
    HashSet* pSet = (HashSet*)hHashSet;
    unsigned int h = my_string_hash(hStr);
    unsigned int index = h % pSet->capacity;
    HashNode* pNode;
    for (pNode = pSet->table[index]; pNode != NULL; pNode = pNode->next) {
        if (pNode->hash == h && my_string_equals(pNode->data, hStr) == TRUE) {
            return true;
        }
    }
    return false;

}

int unique_words(FILE* fp) {
    //Make a TREE_SET using treeset_init
        //use bool ignore case to figure out which compare function to use
 
    HASH_SET unique_hash = hashset_init();
    //Make a MY_STRING using my_string_init_defualt
    MY_STRING unique_string = my_string_init_default();

    while (my_string_extraction(unique_string, fp) == SUCCESS) {
            hashset_insert(unique_hash, unique_string);
      
    }
    int total = hashset_get_size(unique_hash);

    my_string_destroy(&unique_string);
    hashset_destroy(&unique_hash);

    return total;
}