#ifndef BASE_STRING_H
#define BASE_STRING_H

#include <stdbool.h>

/*
Convention:
functions operating on Strings should be named after the following scheme:
str_<short name for action>
*/

#include "base.h"
#include "memory.h"

typedef struct {
    char* str;
    u64 len;
} String;

// allocate string in arena
String str_alloc(Arena* arena, u64 len);

// generate string from literal
String str_from_c_str(Arena* arena, const char* s);

// coppy string into new one
String str_copy(Arena* arena, String s);

// concat two strings in arena
String str_cat(Arena* arena, String a, String b);

// to null terminated
// this function will copy the string
char* str_to_c_str(Arena* arena, String s);

// find string b in string a
u64 str_find(String a, String b);

// compare two strings
bool str_eq(String a, String b);

// test if a starts with b
bool str_starts_with(String a, String b);

// test if a is contained in b
bool str_contains(String a, String b);

#endif // !BASE_STRING_H
