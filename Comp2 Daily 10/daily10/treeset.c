#include "treeset.h"
#include "my_string.h"

#include <stdio.h>
#include <stdlib.h>


struct node {
    MY_STRING data;
    int height;
    int count;
    struct node* left;
    struct node* right;
};
typedef struct node Node;

struct tree {
    Node* root;
    int size;
    CompareFP compare;
};
typedef struct tree Tree;

TREE_SET treeset_init(CompareFP compare) {
    Tree* pTree = (Tree*)malloc(sizeof(Tree));
    if (pTree) {
        pTree->root = NULL;
        pTree->size = 0;
        pTree->compare = compare;
    }
    return (TREE_SET)(pTree);
}

void destroy_post_order(Node* pNode) {
    if (pNode) {
        destroy_post_order(pNode->left);
        destroy_post_order(pNode->right);
        my_string_destroy(&pNode->data);
        free(pNode);
    }
}

void treeset_destroy(TREE_SET* phTreeSet) {
    Tree* pTree = (Tree*)*phTreeSet;
    destroy_post_order(pTree->root);
    free(pTree);
    *phTreeSet = NULL;
}

int treeset_get_size(TREE_SET hTreeSet) {
    Tree* pTree = (Tree*)hTreeSet;
    return pTree->size;
}

int node_height(Node* pNode) {
    if (!pNode) {
        return -1;
    }
    else {
        return pNode->height;
    }
}

void node_update_height(Node* pNode) {
    int leftHeight = node_height(pNode->left) + 1;
    int rightHeight = node_height(pNode->right) + 1;
    pNode->height = (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int treeset_get_height(TREE_SET hTreeSet) {
    Tree* pTree = (Tree*)hTreeSet;
    return node_height(pTree->root);
}

void rotate_left(Node** ppNode) {
    Node* pNode = *ppNode;
    *ppNode = pNode->right;
    Node* pTemp = pNode->right->left;
    pNode->right->left = pNode;
    pNode->right = pTemp;
    node_update_height(pNode);
    node_update_height(*ppNode);
}

void rotate_right(Node** ppNode) {
    // Rotates ppNode to the right
    // Brings up the left child
    Node* pNode = *ppNode;
    *ppNode = pNode->left; // Set parent's child
    Node* pTemp = pNode->left->right;
    pNode->left->right = pNode;
    pNode->left = pTemp;
    node_update_height(pNode);
    node_update_height(*ppNode);
}

void node_rebalance(Node** ppNode) {
    if (ppNode) {
        node_update_height(*ppNode);
        int delta = node_height((*ppNode)->right) - node_height((*ppNode)->left);
        if (delta < -1) {
            // Left heavy
            int childDelta =
                node_height((*ppNode)->left->right) - node_height((*ppNode)->left->left);
            if (childDelta >= 0) {
                // Left-right case: double rotation
                rotate_left(&(*ppNode)->left);
            }
            rotate_right(ppNode);
        }
        else if (delta > 1) {
            // Right heavy
            int childDelta =
                node_height((*ppNode)->right->right) - node_height((*ppNode)->right->left);
            if (childDelta <= 0) {
                // Right-left case: double rotation
                rotate_right(&(*ppNode)->right);
            }
            rotate_left(ppNode);
        }
    }
}

Status node_insert(Node** ppNode, MY_STRING hStr, CompareFP compare) {
    if (*ppNode == NULL) {
        Node* pNode = (Node*)malloc(sizeof(Node));
        if (pNode) {
            pNode->data = NULL;
            my_string_assign(&pNode->data, hStr);
            pNode->count = 1;
            pNode->height = 0;
            pNode->left = NULL;
            pNode->right = NULL;
            *ppNode = pNode;
            return SUCCESS;
        }
        else {
            return FAILURE;
        }
    }
    else if (compare((*ppNode)->data, hStr) > 0) {
        Status result = node_insert(&(*ppNode)->left, hStr, compare);
        if (result == SUCCESS) {
            node_rebalance(ppNode);
        }
        return result;
    }
    else if (compare((*ppNode)->data, hStr) < 0) {
        Status result = node_insert(&(*ppNode)->right, hStr, compare);
        if (result == SUCCESS) {
            node_rebalance(ppNode);
        }
        return result;
    }
    else {
        (*ppNode)->count++; // Found a duplicate
        return FAILURE;
        
    }
}

Status treeset_insert(TREE_SET hTreeSet, MY_STRING hStr) {
    Tree* pTree = (Tree*)hTreeSet;
    Status result = node_insert(&pTree->root, hStr, pTree->compare);
    if (result == SUCCESS) {
        pTree->size++;
    }
    return result;
}

Node** min_node(Node** ppNode) {
    if ((*ppNode)->left == NULL) {
        return ppNode;
    }
    else {
        return min_node(&(*ppNode)->left);
    }
}

Status node_remove(Node** ppNode, MY_STRING hStr, CompareFP compare) {
    Node* pNode = *ppNode;
    if (pNode == NULL) {
        // Not found
        return FAILURE;
    }
    else if (compare((pNode)->data, hStr) > 0) {
        Status result = node_remove(&pNode->left, hStr,compare);
        if (result == SUCCESS) {
            node_rebalance(ppNode);
        }
        return result;
    }
    else if (compare((pNode)->data, hStr) < 0) {
        Status result = node_remove(&pNode->right, hStr,compare);
        if (result == SUCCESS) {
            node_rebalance(ppNode);
        }
        return result;
    }
    else {
        // Found it!
        pNode->count--;
        if (pNode->count <= 0) {
            // Need to remove node - Tricky part
            if (!pNode->left) {
                *ppNode = pNode->right;
            }
            else if (!pNode->right) {
                *ppNode = pNode->left;
            }
            else {
                // Hard part : Need to find another spot that we can swap with
                Node** ppMinSuccessor = min_node(&pNode->right);
                pNode->data = (*ppMinSuccessor)->data;
                pNode->count = (*ppMinSuccessor)->count;
                Status result = node_remove(&pNode->right, pNode->data,compare);
                if (result == SUCCESS) {
                    node_rebalance(ppNode);
                }
                return result;
            }
            my_string_destroy(&pNode->data);
            free(pNode);
        }
        return SUCCESS;
    }
}

Status treeset_remove(TREE_SET hTreeSet, MY_STRING hStr) {
    Tree* pTree = (Tree*)hTreeSet;
    Status result = node_remove(&pTree->root, hStr,pTree->compare);
    if (result == SUCCESS) {
        pTree->size--;
    }
    return result;
}

Boolean node_contains(Node* pNode, MY_STRING hStr, CompareFP compare) {
    if (pNode == NULL) {
        return FALSE;
    }
    else if (compare((pNode)->data, hStr) > 0) {
        return node_contains(pNode->left, hStr, compare);
    }
    else if (compare((pNode)->data, hStr) < 0) {
        return node_contains(pNode->right, hStr,compare);
    }
    else {
        return TRUE;
    }     
}

Boolean treeset_contains(TREE_SET hTreeSet, MY_STRING hStr) {
    Tree* pTree = (Tree*)hTreeSet;
    return node_contains(pTree->root, hStr, pTree->compare);
}

void print_contains(TREE_SET hTreeSet, MY_STRING hStr) {
    Tree* pTree = (Tree*)hTreeSet;
    if (treeset_contains(pTree, hStr) == TRUE) {
        printf("Contains is True\n");
    }
    else if (treeset_contains(pTree, hStr) == FALSE) {
        printf("Contains is False\n");
    }
}

MY_STRING node_first(Node* pNode) {
    MY_STRING minVal = pNode->data;;
    if (pNode) {
        //The root is bigger then the left
        if (my_string_compare(pNode->data, pNode->left->data) > 0) {
            minVal = pNode->left->data;
            node_first(pNode->left);
        }
        //The root is bigger then the right
        else if (my_string_compare(pNode->data, pNode->right->data) > 0) {
            minVal = pNode->right->data;
            node_first(pNode->right);
        }
        
    
    }
    return minVal;
}

//Find MIN
MY_STRING treeset_first(TREE_SET hTreeSet) {
    Tree* pTree = (Tree*)hTreeSet;
    return node_first(pTree->root);
}

MY_STRING node_last(Node* pNode) {
    MY_STRING maxVal = pNode->data;;
    if (pNode) {
        //The root is smaller then the left
        if (my_string_compare(pNode->data, pNode->left->data) < 0) {
            maxVal = pNode->left->data;
            node_last(pNode->left);
        }
        //The root is smaller then the right
        else if (my_string_compare(pNode->data, pNode->right->data) < 0) {
            maxVal = pNode->right->data;
            node_last(pNode->right);
        }
        
    }
    return maxVal;
}

//Find Max
MY_STRING treeset_last(TREE_SET hTreeSet) {
    Tree* pTree = (Tree*)hTreeSet;
    return node_last(pTree->root);
}

int unique_words(FILE* fp, bool ignoreCase) {
    //Make a TREE_SET using treeset_init
    //use bool ignore case to figure out which compare function to use
    CompareFP compare;
    if (ignoreCase == true) {
        compare = order_str_ignore_case;
    }
    else {
        compare = order_str;
    }
    TREE_SET unique_tree = treeset_init(compare);
    //Make a MY_STRING using my_string_init_defualt
    MY_STRING unique_string = my_string_init_default();
    
    while (my_string_extraction(unique_string, fp) == SUCCESS) {
        if (treeset_contains(unique_tree, unique_string) == FALSE) {
            treeset_insert(unique_tree, unique_string);
        }
    }
    int total = treeset_get_size(unique_tree);

    my_string_destroy(&unique_string);
    treeset_destroy(&unique_tree);

    return total;
}

