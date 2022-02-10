#include "my_string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct my_string {
    int size;
    int capacity;
    char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void) {
    My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
    if (pMy_string != NULL) {
        pMy_string->size = 0;
        pMy_string->capacity = 7;
        pMy_string->data = (char*)malloc(sizeof(char) * 7);
        if (pMy_string->data == NULL) {
            free(pMy_string);
            return pMy_string;
        }
    }
    return pMy_string;

}

void my_string_destroy(MY_STRING* phMy_string) {
    My_string* pMy_string = (My_string*)*phMy_string;
    free(pMy_string->data);
    free(pMy_string);
    *phMy_string = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string) {
    My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
    if (pMy_string != NULL) {
        pMy_string->size = strlen(c_string);
        pMy_string->capacity = strlen(c_string) + 1;
        pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
        if (pMy_string->data == NULL) {
            free(pMy_string);
            return NULL;
        }
        int length = strlen(c_string) + 1;
        for (int i = 0; i < length; i++) {
            pMy_string->data[i] = c_string[i];
        }
    }
    return (MY_STRING)pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
    My_string* pMy_string1 = (My_string*)hLeft_string;
    My_string* pMy_string2 = (My_string*)hRight_string;

    if (pMy_string1->size < pMy_string2->size) {
        return -1;
    }
    else if (pMy_string1->size > pMy_string2->size) {
        return 1;
    }
    else {
        int returnVal = 0;
        for (int i = 0; i < pMy_string1->size; i++) {
            if (pMy_string1->data[i] == pMy_string2->data[i]) {
                if (i == pMy_string1->size - 1) {
                    returnVal = 0;
                    break;
                }
                returnVal = 0;
            }
            else if (pMy_string1->data[i] < pMy_string2->data[i]) {
                returnVal = -1;
                break;
            }
        }
        return returnVal;
    }
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
    My_string* pMy_string = (My_string*)hMy_string;
    char c;
    char* temp;
    int i = 0, j = 0;
    pMy_string->size = 0;
    c = fgetc(fp);
    while (c != EOF && c != ' ' && c != '\n') {
        if (pMy_string->size >= pMy_string->capacity) {
            temp = malloc(sizeof(char) * 2 * pMy_string->capacity);
            if (temp == NULL) {
                return FAILURE;
            }
            for (j = 0; j < pMy_string->size; j++) {
                temp[j] = pMy_string->data[j];
            }
            free(pMy_string->data);
            pMy_string->data = temp;
            pMy_string->capacity *= 2;
        }
        pMy_string->data[i] = c;
        i++;
        pMy_string->size++;
        c = fgetc(fp);
    }
    if (c == ' ') {
        if (i != 0) {
            ungetc(c, fp);
        }
    }
    if (pMy_string->size == 0) {
        return FAILURE;
    }
    return SUCCESS;
}


Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
    My_string* pMy_string = (My_string*)hMy_string;
    int i = 0;
    if (pMy_string->size == 0) {
        return FAILURE;
    }
    while (i < pMy_string->size) {
        fputc(pMy_string->data[i], fp);
        i++;
    }
    return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item) {
    My_string* pMy_string = (My_string*)hMy_string;
    char* temp;
    int i;
    if (pMy_string->size >= pMy_string->capacity) {
        temp = malloc(sizeof(char) * 2 * pMy_string->capacity);
        if (temp == NULL) {
            return FAILURE;
        }
        for (i = 0; i < pMy_string->size; i++) {
            temp[i] = pMy_string->data[i];
        }
        free(pMy_string->data);
        pMy_string->capacity *= 2;
    }
    pMy_string->data[pMy_string->size] = item;
    pMy_string->size++;
    return SUCCESS;

}
Status my_string_pop_back(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    if (pMy_string->size <= 0) {
        return FAILURE;
    }
    pMy_string->size--;
    return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index) {
    My_string* pMy_string = (My_string*)hMy_string;
    if (index > 0 || index <= pMy_string->size) {
        return &(pMy_string->data[index]);
    }
    return 0;
}


char* my_string_c_str(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    pMy_string->data[pMy_string->size] = '\0';
    return &(pMy_string->data[0]);
}
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
    My_string* str1 = (My_string*)hResult;
    My_string* str2 = (My_string*)hAppend;
    int i;
    char* temp;
    if (str2->size == 0) {
        return FAILURE;
    }
    else if (str1->size == 0) {
        for (i = 0; i < str2->size; i++) {
            str1->data[i] = str2->data[i];
        }
        str1->size = str2->size;
        str1->capacity = str1->size + 1;
    }
    else {
        int temp_size = str1->size + str2->size + 1;
        int temp_capacity = temp_size + 1;
        int j;
        temp = (char*)malloc(sizeof(char) * temp_capacity);
        if (temp != NULL) {
            for (i = 0; i < str1->size; i++) {
                temp[i] = str1->data[i];
            }
            temp[i] = ' ';
            j = str1->size + 1;
            for (i = 0; i < str2->size; i++) {
                temp[j + i] = str2->data[i];
            }
            temp[j + i] = '\0';
            free(str1->data);
            str1->data = temp;
            str1->capacity = temp_capacity;
            str1->size = temp_size;
        }
    }

    return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string) {
    My_string* pString = (My_string*)hMy_string;
    if (pString->size == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int order_str_ignore_case(MY_STRING _str1, MY_STRING _str2){
    My_string* str1 = (My_string*)_str1;
    My_string* str2 = (My_string*)_str2;

    int minLength = str1->size < str2->size ? str1->size : str2->size;

    for (int i = 0; i < minLength; i++)
    {
        if (str1->data[i] > str2->data[i])
            return 1;
        if (str1->data[i] < str2->data[i])
            return -1;
    }
    return str1->size < str2->size ? -1 : str1->size > str2->size ? 1 : 0;
}

int order_str(MY_STRING _str1, MY_STRING _str2){
    My_string* string1 = (My_string*)_str1;
    My_string* string2 = (My_string*)_str2;
    int minLength = string1->size < string1->size ? string1->size : string1->size;

    for (int i = 0; i < minLength; i++)
    {
        int x = string1->data[i] < 'Z' ? string1->data[i] - 'A' : string1->data[i] - 'a';
        int y = string2->data[i] < 'Z' ? string2->data[i] - 'A' : string2->data[i] - 'a';
        if (x > y)
            return 1;
        if (x < y)
            return -1;
    }
    return string1->size < string2->size ? -1 : string1->size > string2->size ? 1 : 0;
}