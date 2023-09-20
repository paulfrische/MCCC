#include "base/base.h"
#include "base/filesystem.h"
#include "base/logging.h"
#include "base/memory.h"
#include "base/string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    DEBUG("Hello World!");
    INFO("Hello World!");
    WARN("Hello World!");
    ERROR("Hello World!");
    CRITICAL("Hello World!");

    Assert(Min(1, 2) == 1);
    Assert(Max(1, 2) == 2);

    Arena* arena = ArenaInit();
    String s = str_from_c_str(arena, "Hello World");
    Assert(s.len == 12);

    String s2 = str_copy(arena, s);
    Assert(s.str != s2.str);

    String s3 = str_from_c_str(arena, "This string is different from the others");
    Assert(str_eq(s, s2));
    Assert(!str_eq(s, s3));

    Assert(str_starts_with(s3, str_from_c_str(arena, "This")));

    Assert(str_find(s3, str_from_c_str(arena, " is")) == 11);

    Assert(str_contains(s3, str_from_c_str(arena, "is")));

    Assert(str_eq(str_from_c_str(arena, "Hello World"),
        str_cat(arena, str_from_c_str(arena, "Hello "), str_from_c_str(arena, "World"))));

    String s4 = str_from_c_str(arena, "Chello");
    s4.len -= 1; // "remove" the null terminator
    char* s5 = str_to_c_str(arena, s4);
    printf("%s\n", s5);

    String s6 = filesystem_read_file(arena, str_from_c_str(arena, "./src/main.c"));
    printf("%s\n", str_to_c_str(arena, s6));

    filesystem_write_file(str_from_c_str(arena, "tmp.txt"), str_from_c_str(arena, "Hello World!"));

    filesystem_append_file(str_from_c_str(arena, "tmp.txt"), str_from_c_str(arena, "\nSome more text"));

    arena_free(arena);
    return EXIT_SUCCESS;
}
