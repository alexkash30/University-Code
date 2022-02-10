#ifndef MY_STRING_H
#define MY_STRING_H

typedef void* MY_STRING;
#include <stdio.h>
#include <stdbool.h>

enum status { FAILURE, SUCCESS };
typedef enum status Status;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

MY_STRING my_string_init_default(void);
void my_string_destroy(MY_STRING* phMy_string);
MY_STRING my_string_init_c_string(const char* c_string);

int my_string_get_capacity(MY_STRING hMy_string);
int my_string_get_size(MY_STRING hMy_string);
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);
Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

Status my_string_push_back(MY_STRING hMy_string, char item);
Status my_string_pop_back(MY_STRING hMy_string);
char* my_string_at(MY_STRING hMy_string, int index);
char* my_string_c_str(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);
Boolean my_string_empty(MY_STRING hMy_string);
Status my_string_assign(MY_STRING* left, MY_STRING right);

int order_str_ignore_case(MY_STRING _str1, MY_STRING _str2);
int order_str(MY_STRING _str1, MY_STRING _str2);

Boolean my_string_equals(MY_STRING hLeft_string, MY_STRING hRight_string);
unsigned int my_string_hash(MY_STRING hString);
#endif