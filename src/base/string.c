#include "string.h"
#include "base.h"
#include "memory.h"
#include <stdio.h>
#include <string.h>

// allocate string in arena
String str_alloc(Arena* arena, u64 len)
{
    char* str = (char*)arena_alloc(arena, len);

    String s;
    s.str = str;
    s.len = len;

    return s;
}

// generate string from literal (with \0)
String str_from_c_str(Arena* arena, const char* s)
{
    // add one for \0
    u64 len = strlen(s) + 1;
    char* str = (char*)arena_alloc(arena, len);

    String string;
    strcpy(str, s);
    string.str = str;
    string.len = len;

    return string;
}

// coppy string into new one
String str_copy(Arena* arena, String s)
{
    char* str = (char*)arena_alloc(arena, s.len);
    strcpy(str, s.str);
    String s2;
    s2.str = str;
    s2.len = s.len;

    return s2;
}

// finds b in a
// returns -1 if b can't be found
u64 str_find(String a, String b)
{
    if (a.len < b.len) {
        return -1;
    }

    for (u64 i = 0; i < a.len - b.len; i++) {
        String s;
        s.str = a.str + i;
        s.len = a.len - i;
        if (str_starts_with(s, b)) {
            return i;
        }
    }

    return -1;
}

// compare two strings
bool str_eq(String a, String b)
{
    if (a.len != b.len) {
        return false;
    }

    // cant use strcmp because custom strings don't have to have a \0
    for (u64 i = 0; i < a.len; i++) {
        if (a.str[i] != b.str[i]) {
            return false;
        }
    }

    return true;
}
// test if a starts with b
bool str_starts_with(String a, String b)
{
    if (a.len < b.len) {
        return false;
    }

    for (u64 i = 0; i < b.len; i++) {
        // skip '\0' for ease of use
        if (b.str[i] == '\0') {
            continue;
        }

        if (a.str[i] != b.str[i]) {
            return false;
        }
    }

    return true;
}

// test if b is contained in a
bool str_contains(String a, String b)
{
    if (str_find(a, b) != (u64)(-1)) {
        return true;
    }
    return false;
}

// concat two strings in arena
String str_cat(Arena* arena, String a, String b)
{
    u64 len_a = a.len;

    if (a.str[a.len - 1] == '\0') {
        len_a -= 1;
    }

    u64 final_len = len_a + b.len;

    char* str = (char*)arena_alloc(arena, final_len);

    for (u64 i = 0; i < len_a; i++) {
        str[i] = a.str[i];
    }

    for (u64 i = len_a; i < final_len; i++) {
        str[i] = b.str[i - len_a];
    }

    String s;
    s.str = str;
    s.len = final_len;

    return s;
}

// to null terminated
// this function will copy the string
char* str_to_c_str(Arena* arena, String s)
{
    // if s.str ends with \0 it can be copied
    if (s.str[s.len - 1] == '\0') {
        return str_copy(arena, s).str;
    }

    Arena* scratch = arena_init_sized(1);
    String s2 = str_cat(arena, s, str_from_c_str(scratch, "\0"));
    arena_free(scratch);
    return s2.str;
}
